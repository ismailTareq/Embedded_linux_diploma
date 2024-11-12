#include <iostream>
#include <csignal>

void signal_handler(int Signal)
{
    std::cout<< "interrupt signal received"<<std::endl;
    exit(Signal);
}


int main()
{
    signal(SIGINT, signal_handler);
    std::cout << "Program running. Press Ctrl+C to interrupt.\n";
    while (true) {



    }
    return 0;
}
