fn alpha(text:&str) -> (bool,bool){
    (text.contains("a"),text.contains("z"))
}

fn main() {
    apply_to_jobs(35, "embedded linux software");
    println!("{}",is_even(8));
    println!("{}",is_even(9));
    println!("{:?}",alpha("arabic"));
    println!("{:?}",alpha("zoo"));
}
fn apply_to_jobs(num:i32,title:&str)
{
    println!("am appling to {1} {0} jobs",title,num);
}
fn is_even(num:i32) -> bool{
    num % 2 == 0
}
 