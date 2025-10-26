#[derive(Debug)]
struct Flight{
    start: String,
    des: String,
    price: f64,
    passengers: u32,
}

impl Flight{    
    fn new(start: String,des: String,price: f64,passengers: u32) -> Self{
        Self { start,
                des,
                price,
                passengers
            }
    }
    fn change_destination(&mut self,new:String){
        self.des = new;
    }
    fn increase_price(&mut self){
        self.price *= 1.2;
    }
    fn itinerary(&self){
        println!("{} -> {}",self.start,self.des);
    }

}
fn main() {
    let mut flight = Flight::new(
        String::from("egypt"),
        String::from("UAE"),
        299.99,
        160
    );
    println!("{:?}",flight);
    flight.change_destination(String::from("USA"));
    flight.increase_price();
    flight.itinerary();
    println!("{:?}",flight);

    let another_one = Flight{
        start: String::from("russia"),
        des: String::from("paris"),
        ..flight
    };
    println!("{:?}",another_one);

}

  