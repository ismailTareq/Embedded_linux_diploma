#include "Vehicle.hpp"


Vehicle::Vehicle()
    : speed_sensor(), radar_sensor(), temp_sensor(), battery(),
      cruise_control(&speed_sensor, &radar_sensor, &temp_sensor),
      diagnostics(&speed_sensor, &radar_sensor, &temp_sensor, &battery) {
    
    logger = Logger::getInstance();
    logger->log("Vehicle has been initialized...", LogLevel::INFO);
}

Vehicle::~Vehicle(){
    delete logger;
}

void Vehicle::updateSensors() {
    speed_sensor.update();
    radar_sensor.update();
    temp_sensor.update();
    battery.update();
    logger->log("Vehicle sensors updated: Speed = " + std::to_string(speed_sensor.getValue()) + 
                ", Distance = " + std::to_string(radar_sensor.getValue()) +
                ", Temperature = " + std::to_string(temp_sensor.getValue()) +
                ", Battery Level = " + std::to_string(battery.getValue()), LogLevel::INFO);
}

void Vehicle::displayDashboard() {
    std::cout << "======= Vehicle Dashboard =======" << std::endl;
    std::cout << "Speed: " << speed_sensor.getValue() << " km/h" << std::endl;
    std::cout << "Distance to Obstacle: " << radar_sensor.getValue() << " meters" << std::endl;
    std::cout << "Engine Temperature: " << temp_sensor.getValue() << " C" << std::endl;
    std::cout << "Battery Level: " << battery.getValue() << " %" << std::endl;
    std::cout << "=================================" << std::endl;
    logger->log("Dashboard displayed...", LogLevel::INFO);
}

void Vehicle::runPerformanceDiagnostics() {
    diagnostics.runDiagnostics();
}

void Vehicle::controlVehicle() {
    cruise_control.cruiseControl();
    logger->log("Vehicle control executed...", LogLevel::INFO, OutputDestination::BOTH);
}
