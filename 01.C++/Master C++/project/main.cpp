#include <iostream>
#include "Vehicle.hpp"
#include <thread>
#include <chrono>
#include <ctime>

int main()
{

    srand(static_cast<unsigned int>(time(0)));
    Vehicle vehicle;

    while (true) {
        vehicle.updateSensors();    
        vehicle.displayDashboard(); 
        vehicle.runPerformanceDiagnostics();   
        vehicle.controlVehicle();   
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    return 0;
}
