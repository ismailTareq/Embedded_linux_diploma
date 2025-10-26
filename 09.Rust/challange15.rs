use std::collections::HashMap;
fn main() {
    let mut meals = HashMap::from(
        [
            ("ketchep",vec!["french fries","burger","chicken"]),
            ("mayo",vec!["fish","burger","coleslaw"]),
        ]
    );
    meals.insert("mustard", vec!["hot dog","burger","pizza"]);
    println!("{:?}",meals.remove("mayo").unwrap_or(vec!["what is this"]));

    let mustard = meals.get("mustard");
    match mustard{
        Some(meals)=>println!("{:?}",meals),
        None => println!("couldn't find anything about that")
    }
    meals.entry("ketchep").or_insert(vec!["sushi"]);
    meals.entry("1000 island").or_insert(vec!["sushi"]);
    println!("{meals:?}")
}

  