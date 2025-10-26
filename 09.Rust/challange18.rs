fn double_length<T>(x: &Vec<T>) -> usize{
    x.len() * 2
}
fn last_two<T>(x: &[T])-> &[T]{
    // let y = x.len() - 2;
    &x[(x.len() - 2)..]
}
fn first_five<'a>(x: &'a str,y:&str)->&'a str{
    println!("{y}");
    &x[..5]
}
fn first_contain<'a>(x:&'a str,y:&'a str,z:&str)->&'a str{
    if x.contains(z){
        x
    }
    else {
       y
    }
}


fn main() {
    println!("{}",double_length(&vec![1,2,3]));
    let v = vec![1,2,3,4,5,6];
    let a = [1,2,3,4,5,6];
    println!("{:?}",last_two(&v));
    println!("{:?}",last_two(&v[..3]));
    println!("{:?}",last_two(&a));
    println!("{:?}",last_two(&a[..3]));
    println!("{:?}",first_five("ismailBigUnc", "bitch"));

    println!("{:?}",first_contain("programming", "dining", "gram"))
}


  