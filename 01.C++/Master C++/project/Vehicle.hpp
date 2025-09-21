#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include "Battery_Sensor.hpp"
#include "Temperature_Sensor.hpp"
#include "Diagnostics.hpp"
#include "Adaptive_Crusie_Control.hpp"
#include "Radar_Sensor.hpp"
#include "Speed_Sensor.hpp"
#include "logger.hpp"

class Vehicle {
private:
    Speed_Sensor speed_sensor;
    Radar_Sensor radar_sensor;
    Temperature_Sensor temp_sensor;
    Battery_Sensor battery;
    Adaptive_Cruise_Control cruise_control;
    Diagnostics diagnostics;
    Logger *logger;
public:
    Vehicle();
    ~Vehicle();
    void updateSensors();
    void displayDashboard();
    void runPerformanceDiagnostics();
    void controlVehicle();
};

#endif //VEHICLE_HPP
