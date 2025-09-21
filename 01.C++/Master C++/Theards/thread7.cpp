#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <queue>
std::queue<int> queue;
std::mutex key;
std::condition_variable cv;

bool ready = false;

bool done = false;

void worker(int item)
{
    for(int i = 0; i <= 10 ; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lock(key);
        queue.push(i);
        std::cout << "Worker " << item << " is signaling readiness." << std::endl;
        ready = true;
        key.unlock();
        cv.notify_one();
    }
    done = true;
    cv.notify_one();
}

void manager()
{
    while(true)
    {
        std::cout << "Manager thread is waiting for worker to be ready." << std::endl;
    std::unique_lock<std::mutex> lock(key);
    cv.wait(lock, [] { return ready || done; });
    while (!queue.empty())
    {
        std::cout << "Manager thread is processing item: " << queue.front() << std::endl;
        int item = queue.front();
        queue.pop();
        std::cout << "Manager thread processed item: " << item << std::endl;

    }
    ready = false;
    key.unlock();

    std::cout << "Manager thread is resuming work." << std::endl;

    if(done && queue.empty())
        break;
    }
}

int main()
{
    std::thread t1(worker, 1);
    std::thread t2(manager);

    t1.join();
    t2.join();

    return 0;
}