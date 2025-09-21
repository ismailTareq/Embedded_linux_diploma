#ifndef DIAGNOSTICS_HPP
#define DIAGNOSTICS_HPP

#include "Battery_Sensor.hpp"
#include "Temperature_Sensor.hpp"
#include "Radar_Sensor.hpp"
#include "Speed_Sensor.hpp"
#include "logger.hpp"

class Diagnostics
{
private:
    Speed_Sensor* speedSensor;
    Radar_Sensor* radarSensor;
    Temperature_Sensor* tempSensor;
    Battery_Sensor* battery;
    Logger* logger;
public:
    Diagnostics(Speed_Sensor* speed, Radar_Sensor* radar, Temperature_Sensor* temp, Battery_Sensor* batt);
    ~Diagnostics();
    void runDiagnostics();
    bool checkSpeed();
    bool checkRadar();
    bool checkTemperature();
    bool checkBattery();
};



#endif //DIAGNOSTICS_HPP