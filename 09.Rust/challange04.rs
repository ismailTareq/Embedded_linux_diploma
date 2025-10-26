fn color_to_number(color:&str) -> i32{
    match color{
        "red"=> 1,
        "green"=> 2,
        "blue"=> 3,
        _=> 0
    }
}
fn factorial(num:i32) -> i32{
    let mut product = 1;
    let mut count = num;
    while count > 0{
        product *= count;
        count -=1;
    }
    product
}
fn fact_recursive(num:i32) -> i32{
    if num == 1
    {
        return 1;
    }
        
    num * fact_recursive(num - 1)
}

fn main() {
    println!("{} , {} , {}",color_to_number("red"), color_to_number("blue"),color_to_number("orange"));
    println!("{}",factorial(4));
    println!("{}",fact_recursive(4));
}

 