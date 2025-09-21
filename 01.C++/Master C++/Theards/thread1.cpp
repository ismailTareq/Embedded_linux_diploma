#include <iostream>
#include <thread>

using namespace std;

void printhello(int id) {
    cout << "Hello from thread " << id << "!" << endl;
    for(int i=0; i<=10; i++) {
        std::cout << "Hello from printhello thread " << id << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    cout<<"main thread"<<endl;
    thread t1(printhello, 1);
    for(int i=0; i<=5; i++) {
        std::cout << "Hello from main thread " << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    //t1.detach();
    if(t1.joinable()) {
        cout << "main thread finished waiting for thread 1" << endl;
        t1.join();
    }
    cout << "main thread finished will not wait for thread 1" << endl;
    return 0;
}