use std::collections::HashSet;

// mod weightlifting;
// mod cardio;
// mod diet{
//     const NUTRITIONIST:&str = "jomana salah";
//     pub fn ask_about_prog(){
//     println!("the nutritionist will be {}",NUTRITIONIST);
//     }
// }
// use cardio::{CardioTool,Exercise as cardioExercise};
// use weightlifting::Exercise as weightliftingExercise;
// #[derive(Debug)]
// pub struct GymWorkout{
//     cardio: cardioExercise,
//     weight: weightliftingExercise
// }
// impl GymWorkout{
//     pub fn new()-> Self{
//         diet::ask_about_prog();
//         cardio::ask_about_prog();
//         weightlifting::ask_about_prog();
//         Self { cardio: cardioExercise::new(String::from("thusday"), CardioTool::treadmill, 60) ,
//              weight: weightliftingExercise::new(String::from("bench press"), 12)
//             }
//     }
// }
trait Caloric {
    fn calories(&self) -> u32;
}

#[derive(Debug, Clone, Hash, PartialEq, Eq)]
enum Vegetable {
    Tomato,
    Cucumber,
    SweetPotato,
}

impl Caloric for Vegetable {
    fn calories(&self) -> u32 {
        match self {
            Self::Tomato => 20,
            Self::Cucumber => 15,
            Self::SweetPotato => 100,
        }
    }
}

#[derive(Debug, Clone, PartialEq, Eq)]
enum Protein {
    CrispyChicken,
    FriedChicken,
    Steak,
    Tofu,
}

impl Caloric for Protein {
    fn calories(&self) -> u32 {
        match self {
            Self::CrispyChicken => 400,
            Self::FriedChicken => 500,
            Self::Steak => 300,
            Self::Tofu => 200,
        }
    }
}

#[derive(Debug, Clone, PartialEq, Eq)]
enum Dressing {
    Ranch,
    Vinaigrette,
    Italian,
}

impl Caloric for Dressing {
    fn calories(&self) -> u32 {
        match self {
            Self::Ranch => 150,
            Self::Vinaigrette => 120,
            Self::Italian => 130,
        }
    }
}
#[derive(Debug)]
struct Salad{
    protein: Protein,
    vegetable: Vec<Vegetable>,
    dressing: Dressing
}
impl Salad{
    fn new(protein: Protein,
    vegetable: Vec<Vegetable>,
    dressing: Dressing) -> Self{
        Self { protein, vegetable, dressing}
    }
    fn is_valid(&self) -> bool{
        self.vegetable.len() > 0
    }
    fn calories(&self) -> u32{
        self.protein.calories() + self.dressing.calories()
        + self.vegetable.iter()
        .map(|veg|veg.calories())
        .sum::<u32>()
    }
    fn duplicated_vegetable(&self) -> bool
    {
        self.vegetable.clone().into_iter()
        .fold(HashSet::<Vegetable>::new(), |mut data,vegetable|{
            data.insert(vegetable);
            data
        }).len() < self.vegetable.len()
    }
}

#[cfg(test)]
mod test{
    use super::*;
    use pretty_assertions::assert_eq;
    use rstest::{fixture,rstest};

    #[fixture]
    fn return_things() -> Salad{
        Salad::new(
        Protein::CrispyChicken,
        vec![Vegetable::SweetPotato,Vegetable::Tomato],
        Dressing::Ranch)
    }

    #[rstest]
    fn salad_p_v_d(){
        let salad = Salad::new(
        Protein::Steak,
        vec![Vegetable::SweetPotato,Vegetable::Tomato],
        Dressing::Italian);
        assert_eq!(salad.protein,Protein::Steak);
        assert_eq!(salad.vegetable,vec![Vegetable::SweetPotato,Vegetable::Tomato]);
        assert_eq!(salad.dressing,Dressing::Italian);
    }
    #[rstest]
    fn salad_have_one_v(){
        let salad = Salad::new(
        Protein::CrispyChicken,
        vec![Vegetable::SweetPotato,Vegetable::Tomato],
        Dressing::Ranch);
        assert!(salad.is_valid());
    }
    #[rstest]
    fn salad_total_calaries(return_things : Salad){
        assert_ne!(return_things.calories(),600);
    }
    #[rstest]
    fn has_duplication(){
        let salad = Salad::new(
        Protein::Steak,
        vec![Vegetable::Cucumber,Vegetable::Cucumber],
        Dressing::Italian);
        assert!(salad.duplicated_vegetable());
    }
}   