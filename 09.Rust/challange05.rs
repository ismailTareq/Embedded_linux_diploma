fn eat(mut meal:String) -> String{
    meal.clear();
    meal
}
fn main() {
    let concert = true;
    let event = concert;
    println!("{concert},{event}");

    let x = "salmon";
    let y = x;
    println!("{x},{y}");
    let x = String::from("salmon");
    // let y: String = x;
    // println!("{x},{y}");
    let fish = eat(x);
    println!("{fish}");
}

 