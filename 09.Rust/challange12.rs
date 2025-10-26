#[derive(Debug)]
struct File{
    name:String
}
#[derive(Debug)]
struct Folder{
    name:String,
    content:Vec<File>
}
impl Folder{
    fn new(name: String) -> Self{
        Self { name, content: vec![] }
    }
    fn create_file(&mut self,name: String){
        self.content.push(File { name });
    }
    fn delete_file(&mut self,index:usize) -> File{
        self.content.remove(index)
    }
    fn get_file(&self ,index:usize) -> Option<&File>{
        self.content.get(index)
    }
}

fn main() {
    let mut folder = Folder::new(String::from("Soso"));
    folder.create_file(String::from("jomana"));
    folder.create_file(String::from("soso.cpp"));
    println!("{:#?}",folder);
    folder.delete_file(1);
    println!("{:#?}",folder);
    match folder.get_file(0) {
        Some(file)=>println!("{file:?}"),
        None=>println!("couldn't find it")
        
    }
}

  