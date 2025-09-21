#ifndef TEMPERATURE_SENSOR_HPP
#define TEMPERATURE_SENSOR_HPP
#include "Sensor.hpp"

constexpr unsigned int THRESHOLD_TEMPERATURE = 70;
constexpr unsigned int SAFE_TEMPERATURE = 50;

class Temperature_Sensor : public Sensor {
private:
    unsigned int temperature; 
public:
    Temperature_Sensor();
    ~Temperature_Sensor();
    unsigned int getValue() const override;
    void update() override;
};

#endif //TEMPERATURE_SENSOR_HPP