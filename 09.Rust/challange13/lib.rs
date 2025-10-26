mod weightlifting;
mod cardio;
mod diet{
    const NUTRITIONIST:&str = "jomana salah";
    pub fn ask_about_prog(){
    println!("the nutritionist will be {}",NUTRITIONIST);
    }
}
use cardio::{CardioTool,Exercise as cardioExercise};
use weightlifting::Exercise as weightliftingExercise;
#[derive(Debug)]
pub struct GymWorkout{
    cardio: cardioExercise,
    weight: weightliftingExercise
}
impl GymWorkout{
    pub fn new()-> Self{
        diet::ask_about_prog();
        cardio::ask_about_prog();
        weightlifting::ask_about_prog();
        Self { cardio: cardioExercise::new(String::from("thusday"), CardioTool::treadmill, 60) ,
             weight: weightliftingExercise::new(String::from("bench press"), 12)
            }
    }
}