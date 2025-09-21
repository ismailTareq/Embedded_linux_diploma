#ifndef ADAPTIVE_CRUISE_CONTROL_HPP
#define ADAPTIVE_CRUISE_CONTROL_HPP

#include "Temperature_Sensor.hpp"
#include "Radar_Sensor.hpp"
#include "Speed_Sensor.hpp"
#include "logger.hpp"


#define SLOW_CAR                (unsigned int)50
#define STOP_CAR                (unsigned int)0

class Adaptive_Cruise_Control
{
private:
    Speed_Sensor *speed_sensor;
    Radar_Sensor *radar_sensor;
    Temperature_Sensor *temp_sensor;
    Logger *logger;
public:
    Adaptive_Cruise_Control(Speed_Sensor *speed_sensor, Radar_Sensor *radar_sensor, Temperature_Sensor *temp_sensor);
    ~Adaptive_Cruise_Control();
    void cruiseControl();
};
#endif // ADAPTIVE_CRUISE_CONTROL_HPP