use std::fs;
use std::io;
use std::io::Read;

fn write() -> io::Result<String>{
    println!("name of the file");
    let mut req_file = String::new();
    io::stdin().read_line(&mut req_file)?;

    println!("what to write in the file");
    let mut content = String::new();
    io::stdin().read_line(&mut content)?;

    fs::write(req_file.trim(), content.trim())?;

    Ok(req_file)
}
fn read() -> io::Result<String>{
    println!("name of the file");
    let mut req_file = String::new();
    io::stdin().read_line(&mut req_file)?;
    
    fs::read_to_string(req_file.trim())
    // let mut file = fs::File::open(req_file.trim())?;
    // let mut content = String::new();
    // file.read_to_string(&mut content)?;
    // Ok(content)
}

fn main() {
    
    
}


  