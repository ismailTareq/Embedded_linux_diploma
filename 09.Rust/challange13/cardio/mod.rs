const PERSONAL_TRAINER: &str = "ismail tarek";

pub fn ask_about_prog(){
    println!("the trainer will be {}",PERSONAL_TRAINER);
}

#[derive(Debug)]
pub enum CardioTool{
    treadmill,
    Bike
}
#[derive(Debug)]
pub struct Exercise{
    day:String,
    tool:CardioTool,
    minutes: u32
}

impl Exercise{
    pub fn new(day:String,tool:CardioTool,minutes:u32)-> Self{
        Self{
            day,
            tool,
            minutes
        }
    }
}