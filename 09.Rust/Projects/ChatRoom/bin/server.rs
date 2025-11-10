use tokio::{net::{TcpListener,TcpStream},sync::broadcast,
            io::{AsyncBufReadExt,AsyncWriteExt,BufReader}};
use serde::{Serialize,Deserialize};
// use tokio::time::{sleep, Duration};
use chrono::Local; 
use std::error::Error; 

#[derive(Debug,Clone,Serialize,Deserialize)]
enum MsgType{
    DataMessage,
    SystemNotification
}

#[derive(Debug,Clone,Serialize,Deserialize)]
struct Msg{
    username: String,
    content: String,
    time: String,
    msg_type: MsgType
}

async fn client_connections_handle(tx:broadcast::Sender<String>,mut rx: broadcast::Receiver<String>,mut socket:TcpStream){
    let (reader,mut writer) = socket.split();
    let mut reader = BufReader::new(reader);
    let mut username = String::new();
    reader.read_line(&mut username).await.unwrap();
    let username = username.trim().to_string();
    let join_chat = Msg{
        username: username.clone(),
        content: "joined the chat".to_string(),
        time: Local::now().format("%H:%M:%S").to_string(),
        msg_type: MsgType::SystemNotification
    };
    let json_noti = serde_json::to_string(& join_chat).unwrap();
    tx.send(json_noti).unwrap();
    let mut client_buffer = String::new();
    loop {
        tokio::select! {
            //speak
            result = reader.read_line(& mut client_buffer) =>{
                if result.unwrap() == 0{
                    break;
                }
                let client_message = Msg{
                    username: username.clone(),
                    content: client_buffer.trim().to_string(),
                    time: Local::now().format("%H:%M:%S").to_string(),
                    msg_type: MsgType::DataMessage
                };
                let json_msg = serde_json::to_string(&client_message).unwrap();
                tx.send(json_msg).unwrap();
                client_buffer.clear();
            }
            //listen
            result = rx.recv() =>{
                let msg = result.unwrap();
                writer.write_all(msg.as_bytes()).await.unwrap();
                writer.write_all(b"\n").await.unwrap();
            }
        }
    }

}

#[tokio::main]
async fn main() -> Result<(), Box<dyn Error>>{
    
    let listener = TcpListener::bind("127.0.0.1:8085").await?;
    println!("╔════════════════════════════════════════╗");
    println!("║        RETRO CHAT SERVER ACTIVE        ║");
    println!("║        Port: 8082  Host: 127.0.0.1     ║");
    println!("║        Press Ctrl+C to shutdown        ║");
    println!("╚════════════════════════════════════════╝");
    let (tx,_) = broadcast::channel::<String>(100);
    loop{
        let (socket, address) = listener.accept().await?;
        println!("┌─[{}] New connection", Local::now().format("%H:%M:%S"));
        println!("└─ Address: {}", address);

        let tx = tx.clone();
        let rx = tx.subscribe();

        tokio::spawn(async move {
            client_connections_handle(tx,rx,socket).await
        });
    }
}