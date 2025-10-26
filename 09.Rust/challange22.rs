use chrono::NaiveDate;

fn main(){
    let birthday = NaiveDate::from_ymd_opt(2000, 5, 12);
    println!("{birthday:?}")

}