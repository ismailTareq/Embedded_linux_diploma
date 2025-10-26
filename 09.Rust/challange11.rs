use std::result;

// #[derive(Debug)]
// enum Myoption{
//     Some(i32),
//     None
// }
// impl Myoption{
//     fn unwrap(self) -> i32{
//         match self{
//             Myoption::Some(val)=> val,
//             Myoption::None=> panic!("WTF are you doing")
//         }
//     }
//     fn unwrap_or(self,fallback:i32)->i32{
//         match self{
//             Myoption::Some(val)=> val,
//             Myoption::None=> fallback
//         }
//     }
// }
#[derive(Debug)]
struct Food {
    name:String
}
struct Restaurant{
    reservation: u32,
    has_mice: bool
}

impl Restaurant{
    fn special(&self) -> Option<Food>{
        if self.has_mice{
            None
        }
        else if self.reservation < 12 {
            Some(Food { name: String::from("sashimi") })
        }
        else {
            Some(Food { name: String::from("steak") })
        }
    }

    fn burger_deliver(&self,address:&str) -> Result<Food,String>{
        if self.has_mice{
            Err(String::from("sorry ratatatouille is here"))
        }
        else if address.is_empty() {
            Err(String::from("where dafuck do you live?"))
        }
        else {
            Ok(Food{name: String::from("on my way")})
        }
    }
}


fn main() {
    let barka = Restaurant{
        reservation: 11,
        has_mice: true,
    };
    println!("{:?}",barka.special());
    println!("{:?}",barka.burger_deliver("elmo street"));

    let wendies = Restaurant{
        reservation: 15,
        has_mice: false,
    };
    println!("{:?}",wendies.special());
    println!("{:?}",wendies.burger_deliver(""));
    println!("{:?}",wendies.burger_deliver("elmo street"));

}

  