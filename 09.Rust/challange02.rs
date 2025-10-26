fn main() {
    let dis: i32 = 1_337;
    let miles = dis as i16;
    println!("{}",miles);
    let height = 150.34566;
    println!("{:.3}",height);
    let milk = true;
    let sugar = false;
    let coff_type = milk && sugar;
    let acc_coff = milk || sugar;

    let dis: [i8;4] = [55,66,77,88];
    println!("{:?}",dis);
    let typle = (miles,height,coff_type,dis);
    println!("{typle:?}"); 
}
 