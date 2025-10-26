// use std::io::stdin;

// struct Vault{
//     pass: String,
//     treasure: String
// }
// impl Vault{
//     fn unlock(self,procedure: impl FnOnce()->String) -> Option<String>
//     {
//         let user_pass = procedure();
//         if user_pass == self.pass{
//             Some(self.treasure)
//         }
//         else {
//             None
//         }
//     }
// }
// #[derive(Debug)]
// struct Location{
//     name:String,
//     value:u32
// }
// struct Map<'a>{
//     locations: &'a [Location]
// }
// impl<'a>Map<'a>{
//     fn explore<F>(&self,mut action:F)
//     where F: FnMut(&Location)
//     {
//         let end = self.locations.len() -1;
//         let mut start = 0;
//         while start <= end{
//             let current = &self.locations[start];
//             action(current);
//             start += 1;
//         }
//     }
// }
#[derive(Debug)]
struct SupermarketItem{
    name: String,
    price: f64
}
#[derive(Debug)]
struct ShoppingCart{
    items: Vec<SupermarketItem>
}
impl ShoppingCart{
    fn traverse_item<F>(&mut self,mut operation:F)
    where F: FnMut(&mut SupermarketItem){
        let end = self.items.len() -1;
        let mut start = 0;
        while start <= end{
            let current = &mut self.items[start];
            operation(current);
            start += 1;
        }
    }
    fn checkout<F>(self,operation: F)
    where
        F: FnOnce(Self)
    {
        operation(self);
    }
}

fn main() {
    let mut cart = ShoppingCart{
        items: vec![
            SupermarketItem{
                name: "apple".to_string(),
                price: 3.99
            },
            SupermarketItem{
                name: "banana".to_string(),
                price: 2.99
            }
        ],
    };
    cart.traverse_item(|item|{
        item.price *= 0.85;
    });
    cart.traverse_item(|item|{
        item.name = item.name.to_uppercase();
    });
    let mut total_price = 0.0;
    cart.checkout(|mut x|{
        println!("{x:?}");
        x.traverse_item(|item|{
            total_price += item.price;
        });
    });
    println!("{total_price}");
    // let loc = [
    //     Location{
    //         name:String::from("forest"),
    //         value:15
    //     },
    //     Location{
    //         name:String::from("mountain"),
    //         value:10
    //     }
    // ];
    // let map = Map{
    //     locations:&loc
    // };
    // let mut total = 0;
    // map.explore(|loc|{
    //     total += loc.value;
    // });
    // println!("{total}");

    // let mut v: Vec<String> = Vec::new();
    // map.explore(|loc|{
    //     v.push(loc.name.clone());
    // });
    // println!("{:?}",v)
    // let vault = Vault{
    //     pass: String::from("bitch"),
    //     treasure: String::from("merry chrismas"),
    // };
    // let hack = || {
    //     let mut user_input = String::new();
    //     println!("enter the pass?");
    //     match stdin().read_line(&mut user_input){
    //     Ok(_)=> println!("pass entered let me calculate this shit"),
    //     Err(err)=>println!("{err}")
        
    // }
    //     user_input.trim().to_string()
    // };
    // let extraction = vault.unlock(hack);
    // println!("{:?}",extraction);
    // let mut user_input = String::new();
    // println!("enter the pass?");
    // match stdin().read_line(&mut user_input){
    //     Ok(_)=> println!("pass entered let me calculate this shit"),
    //     Err(err)=>println!("{err}")
    // }
    // user_input = user_input.trim().to_string();
    // let hack = || user_input;
    // let extraction = vault.unlock(hack);
    // println!("{:?}",extraction);
}


  