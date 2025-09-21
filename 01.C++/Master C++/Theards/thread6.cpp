#include <iostream>
#include <thread>
#include <future>
#include <chrono>
std::mutex key;
std::condition_variable cv;

bool ready = false;

void worker() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(key);
        ready = true;
        std::cout << "Worker thread is signaling readiness." << std::endl;
    }
    cv.notify_one();
}

void manager() {
    std::cout << "Manager thread is waiting for worker to be ready." << std::endl;
    std::unique_lock<std::mutex> lock(key);
    cv.wait(lock, [] { return ready; });
    std::cout << "Manager thread is resuming work." << std::endl;
}

int main()
{
    std::thread t1(worker);
    std::thread t2(manager);

    t1.join();
    t2.join();

    return 0;
}
