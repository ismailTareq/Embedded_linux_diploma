#include <iostream>
#include <thread>

#include <iostream>
#include <algorithm>

class DummyClass {
public:
    DummyClass() {
        std::cout << "Constructor "<<std::endl;
    }

    ~DummyClass() {
        std::cout << "Destructor " << std::endl;
    }

    DummyClass(const DummyClass& other)  {
        std::cout << "Copy Constructor " << std::endl;
    }

    DummyClass& operator=(const DummyClass& other) {
            std::cout << "Copy Assignment Operator " << std::endl;
        return *this;
    }

    DummyClass(DummyClass&& other) {
        std::cout << "Move Constructor: " << std::endl;
    }

    DummyClass& operator=(DummyClass&& other) noexcept {
        std::cout << "Move Assignment Operator" << std::endl;
        return *this;
    }

};

void printHello(int id,const DummyClass& dc) {
    std::cout << "Hello from  printHello thread " << id << "!" << std::endl;
        for(auto i =0; i <10; i++)
    {
        std::cout << "Hello from printHello Thread"<< std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "printHello Thread Finished"<< std::endl;
}

int main() {
    std::cout << "Main thread started!" << std::endl;
    DummyClass dc;

    std::thread t1(printHello, 1, dc); 

    for(auto i =0; i <3; i++)
    {
        std::cout << "Hello from Main Thread"<< std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "Main thread finished!" << std::endl;
    //t1.detach();
    if(t1.joinable())
    {
        std::cout<<"Main thread finished and waiting for printHello thread"<<std::endl;
        t1.join(); 
    }
    
    return 0;
}