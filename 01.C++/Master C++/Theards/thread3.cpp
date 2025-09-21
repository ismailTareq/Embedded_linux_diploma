#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex key;

int Data = 0;

void incrementData(int id) {
    for (int i = 0; i < 10000; ++i) {
        std::lock_guard<std::mutex> guard(key);
        ++Data;
        if(Data == 500)
        {
            return;
        }
        std::cout << "Thread " << id << " incremented Data to " << Data << std::endl;
    }
}

int main() {
    std::thread t1(incrementData, 10);
    std::thread t2(incrementData, 20);

    t1.join();
    t2.join();

    std::cout << "Final value of Data: " << Data << std::endl;

    return 0;
}