use std::io::stdin;
fn get_identity() -> String{
    let mut fname = String::new();
    let mut lname = String::new();
    println!("enter the first name?");
    stdin().read_line(&mut fname).expect("failed");
    println!("enter the last name?");
    stdin().read_line(&mut lname).expect("failed");
    format!("{} {}",fname.trim(),lname.trim())
}
fn money(text: &mut String){
    text.push_str("$$$");
}
fn capitalize(text: &str) -> String{
    text.trim().to_uppercase()
}
fn split(text: &str) -> Vec<&str>{
    text.split(", ").collect::<Vec<&str>>()
}
fn main() {
    let mut ammount = String::from("40");
    money(&mut ammount);
    println!("{ammount}");
    let x = capitalize("     i love woman        ");
    println!("{x}");
    let y = split("ismail, jomana, safia, lili");
    println!("{y:?}");
    let z = get_identity();
    println!("{z}");
}

  