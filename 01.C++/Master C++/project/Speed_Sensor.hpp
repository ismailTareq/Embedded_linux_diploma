#ifndef SPEED_SENSOR_HPP
#define SPEED_SENSOR_HPP

#include "Sensor.hpp"

constexpr unsigned int SAFE_SPEED = 150;

class Speed_Sensor : public Sensor {
private:
    unsigned int speed;    
public:
    Speed_Sensor();
    ~Speed_Sensor();
    unsigned int getValue() const override;
    void update() override;
    void controlSpeed(unsigned int sp);
};

#endif //SPEED_SENSOR_HPP