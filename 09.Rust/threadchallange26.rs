use std::{thread, time::Duration};
use rand::Rng;
use std::sync::mpsc;
fn main() {
    // thread::spawn(||{
    //     for i in 1..=10{
    //     println!("{:?} displaying {}",thread::current().id(),i);
    //     thread::sleep(Duration::from_secs(1));
    //     }
    // });
    // for i in 100..=105{
    //     println!("{:?} displaying {}",thread::current().id(),i);
    //     thread::sleep(Duration::from_secs(4));
    // }
    // println!("thats the main thread");
    // let handle = thread::spawn(||{
    //     println!("{:?} starting",thread::current().id());
    //     thread::sleep(Duration::from_secs(10));
    //     println!("{:?} ending",thread::current().id());
    // });
    // for i in 100..=105{
    //     println!("{:?} displaying {}",thread::current().id(),i);
    //     thread::sleep(Duration::from_millis(500));
    // }
    // println!("waiting for the the second thread to finish");
    // match handle.join(){
    //     Ok(_)=> println!("okay"),
    //     Err(_)=>println!("Error")
    // }
    // let mut handles: Vec<thread::JoinHandle::<_>> = vec![];
    // for _ in 1..=5{
    //     let handle = thread::spawn(||{
    //         let mut rng = rand::rng();
    //         let num = rng.random_range(5..10);
    //         println!("{:?} starting for {} sec",thread::current().id(),num);
    //         thread::sleep(Duration::from_secs(num));
    //         println!("{:?} ending for {} sec",thread::current().id(),num);
    //     });
    //     handles.push(handle);
    // } 
    // for i in 100..=105{
    //     println!("{:?} displaying {}",thread::current().id(),i);
    //     thread::sleep(Duration::from_millis(500));
    // }
    // println!("waiting for other threads");
    // for h in handles{
    //     h.join().unwrap();
    // }
    // println!("done")
    // let (tx,rx) = mpsc::channel::<String>();
    // let handle = thread::spawn(move ||{
    //     thread::sleep(Duration::from_secs(5));
    //     tx.send(String::from("hello bitch")).unwrap();
    // });
    // let rec = rx.recv().unwrap();
    // println!("{rec}");
    // handle.join().unwrap();
}

