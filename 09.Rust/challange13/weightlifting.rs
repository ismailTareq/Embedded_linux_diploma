const PERSONAL_TRAINER: &str = "khadiga tarek";

pub fn ask_about_prog(){
    println!("the trainer will be {}",PERSONAL_TRAINER);
}
#[derive(Debug)]
pub struct Exercise{
    name:String,
    reps: u32
}
impl Exercise{
    pub fn new(name:String,reps:u32) -> Self
    {
        Self{
            name,
            reps
        }
    }
}

