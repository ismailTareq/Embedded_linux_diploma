use std::{
    env,
    io::{self, Write},
    net::{IpAddr, TcpStream},
    process,
    str::FromStr,
    sync::mpsc::{channel, Sender},
    thread,
    time::Duration,
};
const MAXPORT: u16 = 65535;
#[derive(Debug)]
struct Arguments{
    ipaddress: IpAddr,
    flag:String,
    threads:u16
}
impl Arguments{
    fn new(args:&[String])->Result<Arguments,&'static str>{
        if args.len() < 2{
            return Err("not enough");
        }
        else if args.len() > 4 {
            return Err("too many args");
        }
        if let Ok(ipaddress) = IpAddr::from_str(&args[1]){
            return Ok(Arguments{
                ipaddress,
                flag:String::from(""),
                threads: 4
            });
        }
        let flag = args[1].clone();
        if flag.contains("-h") || flag.contains("-help"){
            if args.len() == 2{
                println!("-j for thread\r\n-h is for help dumass");
                return Err("help");
            } else {
                return Err("too many args");
            }
        }else if flag.contains("-j"){
            let threads = args[2].parse::<u16>().map_err(|_|{
                "faild to catch the thread"
            })?;
            let ipaddress = IpAddr::from_str(&args[3])
            .map_err(|_|{
                "not a valid ip address"
            })?;
            return Ok(Arguments { ipaddress, flag, threads });
        }else{
            return Err("invalid syntax");
        }
    }
}

fn scan(tx:Sender<u16>,start:u16,ip: IpAddr,step:u16){
    let mut port = start;
    let timeout = Duration::from_millis(500);
    while port < MAXPORT {
        let sock_addr = (ip,port).into();
        if TcpStream::connect_timeout(&sock_addr, timeout).is_ok(){
            println!(".");
            io::stdout().flush().unwrap();
            tx.send(port).unwrap();
        }
        port = match port.checked_add(step){
            Some(n)=>n,
            None => break
        };
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    // let program = args[0].clone();
    // // println!("{program}")
    let argument = Arguments::new(&args).unwrap_or_else(|err|{
        if err == "help"
        {
            process::exit(0);
        }
        else{
            eprintln!("proplem parsed by an argument:{}",err);
            process::exit(0);
        }
    });
    let thread = argument.threads;
    let (tx,rx) = channel::<u16>();
    for i in 0..thread{
        let tx = tx.clone();
        let ip = argument.ipaddress;
        thread::spawn(move ||{
            scan(tx, i+1, ip, thread);
        });
    }
    drop(tx);
    let v:Vec<u16> =rx.iter().collect();
    for x in v {
        println!("{} is open",x);
    } 
}