
fn main() {
    let mut cereals = [
        String::from("cookies crisp"),
        String::from("cinnamon toast crunch"),
        String::from("frosted flakes"),
        String::from("cocoa puffs"),
        String::from("captain crunch"),
    ];
    let x = &cereals[..2];
    println!("{x:?}");
    let x = &cereals[1..4];
    println!("{x:?}");
    let x = &mut cereals[2..];
    println!("{x:?}");
    x[2] = String::from("lucky charms");
    println!("{x:?}");
    let y = &cereals[0];
    let z = &y[..6];
    println!("{z}");
    let y = &cereals[3];
    let z = &y[6..];
    println!("{z}");
}

  