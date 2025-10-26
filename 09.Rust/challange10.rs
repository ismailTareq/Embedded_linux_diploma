#[derive(Debug)]
enum Digitalcontent{
    Audio,
    Video
}
#[derive(Debug)]
struct Chatmessage<T>{
    content: T,
    time: String
}
impl Chatmessage<Digitalcontent>{
    fn consume_entertainment(&self){
        println!("watching the {:?}",self.content)
    }
}
impl<T>Chatmessage<T>{
    fn retrieve_time(&self) -> String{
        self.time.clone()
    }
}
fn main() {
    let msg = Chatmessage{
        content: "hi, ismail",
        time: String::from("2025-10-20")
    };
    // msg.consume_entertainment();
    println!("{}",msg.retrieve_time());
    let notifi = Chatmessage{
        content: String::from("what's good boss!"),
        time: String::from("2025-09-20")
    };
    println!("{}",notifi.retrieve_time());
    println!("{}",msg.retrieve_time());
    let audio = Chatmessage{
        content: Digitalcontent::Audio,
        time: String::from("2025-11-20")
    };
    audio.consume_entertainment();
    println!("{}",audio.retrieve_time());
}

  