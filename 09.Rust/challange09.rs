use std::ops::Sub;

#[derive(Debug)]
enum Tier{
    Gold,
    Silver,
    Platinum
}
#[derive(Debug)]
enum Subscription{
    Free,
    Basic(f64,u64),
    Premium{tier: Tier}
}

impl Subscription{
    fn summarize(&self){
        match self{
            Subscription::Free =>{
                println!("ypu have limited access");
            }
            Subscription::Basic(price,month, )=>{
                println!("more than limit the premium is{price} for {month} months")
            }
            Subscription::Premium { tier }=>{
                println!("you have full access your tier is {tier:?}")
            }
        }
    }
}

fn main() {
    Subscription::Free.summarize();
    Subscription::Basic(4.99, 3).summarize();
    Subscription::Premium { tier: Tier::Platinum }.summarize();
    Subscription::Premium { tier: Tier::Gold }.summarize();
}

  