#include <iostream>
#include <map>


void print(auto& container){
    for (auto i : container)
    {
        std::cout << i.first << ' ' << i.second << std::endl;
    }
}

class Student{
private:
    std::string name;
    float gpa;
public:
    Student(std::string name,float gpa):name(name),gpa(gpa){}
    bool is_passed(){
        return gpa > 2;
    }
    std::string get_name(){
        return name;
    }
    bool operator<(const Student& student) const{
        return name < student.name;
    }
    friend std::ostream& operator<<(std::ostream& os,const Student& student){
        os<<student.name;
        return os;
    }
};

int main()
{
    Student student1("Khaled",3.5);
    Student student2("Essam",2);
    Student student3("Mohammed",1.8);
    std::map <Student,int> m=
    {
        {student1,5000},
        {student2,15000},
        {student3,10000},
    };

    print(m);

    std::cout << "Empty " << m.empty()<<std::endl;

    std::cout << "Size " << m.size()<<std::endl;

    std::cout << "Max_size " << m.max_size()<<std::endl;

    m.insert({Student("ismail",3),8000});
    m.emplace(Student("jomana",1.1),9000);
    m.emplace(Student("jomana",2),11000);

    m.emplace(student1,11111);

    print(m);

    std::map<Student,int> m2=
    {
        {Student("Kamal",3),900},
        {Student("Saad" ,0.5),2000},
    };
    //m.merge(m2);
    print(m);

    m.erase(Student("ismail",3.2));

    std::cout << "Count1 " << m.count(student1) << std::endl;
    std::cout << "Count2 " << m.count(Student("jomana" ,0.5)) << std::endl;

    print(m);

    //auto it = m.find(Student("Hassan" ,0.5));
    auto it = m.find(Student("jomana" ,0.5));
    if(it==m.end())
        std::cout << "Not Found" << std::endl;
    else
        std::cout << "Find " << it->first << it->second << std::endl;

    m.clear();
    print(m);
    return 0;
}
