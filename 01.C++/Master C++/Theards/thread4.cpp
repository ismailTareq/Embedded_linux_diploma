#include <iostream>
#include <thread>
#include <chrono>

std::string getThreadName() {
    char buffer[16]; 
    pthread_getname_np(pthread_self(), buffer, sizeof(buffer));
    return std::string(buffer);
}

void printHello() {
    pthread_setname_np(pthread_self(), "a7a");
    auto thread_name = getThreadName();
    std::cout << "Thread name: " << thread_name << std::endl;
    std::cout << "printHello thread id: " << std::this_thread::get_id() << std::endl;
}

int main() {
    std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;

    std::thread t1(printHello); 
    auto id = t1.get_id();

    if(t1.joinable())
    {
        t1.join();
    }
    std::cout<<"thread id: "<< id << std::endl;
    return 0;
}