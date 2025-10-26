use std::error::Error;
use std::fmt::Display;
trait TextTransformation {
    fn transform(&self,text: &str) -> Result<String,Box<dyn Error>>;
}
#[derive(Debug)]
struct PizzaEmojiInString;
impl Display for PizzaEmojiInString {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f,"hey, there is a pizza emoji in the fucking text")
    }
}
impl Error for PizzaEmojiInString {
    
}
#[derive(Debug)]
struct NoContentInString;
impl Display for NoContentInString {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f,"hey, the sting has nothing left")
    }
}
impl Error for NoContentInString {
    
}
struct WhiteSpaceTransform{
    start: bool,
    end: bool
}
impl TextTransformation for WhiteSpaceTransform{
    fn transform(&self,text: &str) -> Result<String,Box<dyn Error>> {
        if text.contains("pizza"){
            return Err(Box::new(PizzaEmojiInString));
        }
        let trans = if self.start && self.end{
            text.trim()
        }else if self.start{
            text.trim_start()
        }else if self.end{
            text.trim_end()
        }else{
            text
        };
        if trans.is_empty(){
            return Err(Box::new(NoContentInString));
        }
        Ok(trans.to_string())
    }
}
enum Case{
    Uppercase,
    Lowercase
}
struct CaseTransformer{
    case: Case
}
impl TextTransformation for CaseTransformer {
    fn transform(&self,text: &str) -> Result<String,Box<dyn Error>> {
        match self.case{
            Case::Lowercase=> Ok(text.to_lowercase()),
            Case::Uppercase=> Ok(text.to_uppercase()),
        }
    }
}

fn apply_transformation(text: String, pipeline: Vec<Box<dyn TextTransformation>>)-> String{
    pipeline.into_iter()
    .fold(text,|accumulator,transformer|{
        match transformer.transform(&accumulator){
            Ok(value)=>value,
            Err(error)=>{
                eprintln!("somthing went wrong:{error}");
                accumulator
            }
        }
    })
}
fn main() {

}

