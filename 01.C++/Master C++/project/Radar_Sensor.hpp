#ifndef RADAR_SENSOR_HPP
#define RADAR_SENSOR_HPP
#include "Sensor.hpp"

constexpr unsigned int SAFE_DISTANCE = 5;
constexpr unsigned int THRESHOLD_DISTANCE = 3;

class Radar_Sensor : public Sensor {
private:
    unsigned int distance;
public:
    Radar_Sensor();
    ~Radar_Sensor();
    unsigned int getValue() const override;
    void update() override;
};

#endif //RADAR_SENSOR_HPP