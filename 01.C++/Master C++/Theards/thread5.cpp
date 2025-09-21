#include <iostream>
#include <thread>
#include <future>
#include <chrono>
void compute(std::promise<int>& prom) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    prom.set_value(10); 
}

int main() {
    std::promise<int> x;
    std::future<int> y = x.get_future();

    std::thread t1(compute, std::ref(x));

    std::cout << "Main thread is doing some other work..." << std::endl;

    int result = 0;
    if(y.valid())
    {
        result = y.get();
    }

    std::cout << "The result of the computation is: " << result << std::endl;

    if(t1.joinable())
    {
        t1.join();
    }

    return 0;
}