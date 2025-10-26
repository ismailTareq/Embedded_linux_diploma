use std::fmt::{Debug,Display,Formatter};
trait Drinkable{
    fn consume(&mut self);
    fn getter(&self) -> String;
    fn stats(&self){
        println!("{}",self.getter());
    }
}

#[derive(Debug)]
enum Milk{
    Whole,
    Oat,
    Almond
}

struct  Coffee<T>{
    kind: T,
    milk: Milk,
    ounce:u32
}
impl<T> Coffee<T>{
    fn new(kind: T,
    milk: Milk,
    ounce:u32) -> Self{
        Self { kind, milk, ounce}
    }
}
impl<T: Debug> Debug for Coffee<T>{
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        f.debug_struct("COFFEE")
        .field("Kind", &self.kind)
        .field("Milk", &self.milk)
        .field("Ounce", &self.ounce)
        .finish()
    }
}

impl<T:Display> Drinkable for Coffee<T>{
    fn consume(&mut self) {
        self.ounce = 0;
    }
    fn getter(&self) -> String {
        format!("{} {}",self.ounce,self.kind)
    }
}
// #[derive(Debug)]
struct Soda{
    calories:u32,
    price:f64,
    flaver: String,
    percent: u32
}
impl Soda{
    fn new(calories:u32,
    price:f64,
    flaver: String)-> Self{
        Self { calories, price, flaver, percent:100 }
    }
}
impl Drinkable for Soda{
    fn consume(&mut self) {
        self.percent = 0;
    }
    fn getter(&self) -> String {
        format!("{} {}",self.flaver,self.calories)
    }
}
impl Debug for Soda{
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        f.debug_struct("Soda bitch")
        .field("Price", &self.price)
        .field("Calories", &self.calories)
        .field("Flaver", &self.flaver)
        .field("Percentage", &self.percent)
        .finish()
    }
}
impl Display for Soda{
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        write!(f,"{}",self.flaver)
    }
}

impl Clone for Soda{
    fn clone(&self) -> Self {
        Self { calories: self.calories, price: self.price, flaver: self.flaver.clone(), percent: self.percent }
    }
}
impl PartialEq for Soda{
    fn eq(&self, other: &Self) -> bool {
        self.price == other.price
    }
}


fn main() {
    let mut latte = Coffee::new("latte", Milk::Oat, 32);
    println!("{latte:?}");
    latte.consume();
    println!("{latte:?}");

    let coffe = Coffee::new(String::from("cappicciono"), Milk::Oat, 16);
    println!("{}",coffe.getter());

    let mut coca = Soda::new(300, 2.99, String::from("cola"));
    println!("{}",coca);
    let mut pepsi = coca.clone();
    println!("{}",coca == pepsi);
    coca.consume();
    println!("{:?} {:?}",coca,pepsi);
}


  