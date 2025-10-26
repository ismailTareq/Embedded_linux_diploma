fn start() -> String{
    String::from("start trip...\n")
}
fn  visit(trip:&mut String){
    trip.push_str("egypt");
}
fn visit1(trip:&mut String){
    trip.push_str("new york");
}
fn show(trip:&String){
    println!("{trip}");
}
fn main() {
    let mut trip = start();
    visit(&mut trip);
    trip.push_str(" and ");
    visit1(&mut trip);
    // trip.push_str(" and ");
    trip.push('.');
    show(&trip)
}

 