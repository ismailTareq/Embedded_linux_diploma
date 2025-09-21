#ifndef BATTERY_SENSOR_HPP
#define BATTERY_SENSOR_HPP
#include "Sensor.hpp"

constexpr unsigned int THRESHOLD_LEVEL = 20;

class Battery_Sensor : public Sensor {
private:
    unsigned int batteryLevel;          
    unsigned int batteryTemperature;      
public:
    Battery_Sensor();
    ~Battery_Sensor();
    unsigned int getValue() const override;
    void update() override;
    unsigned int getBatteryTemp() const ;
};

#endif //BATTERY_SENSOR_HPP