#include "Battery_Sensor.hpp"
Battery_Sensor::Battery_Sensor() : batteryLevel(0), batteryTemperature(0)
{

}

Battery_Sensor::~Battery_Sensor()
{

}

unsigned int Battery_Sensor::getValue() const {
    return batteryLevel;
}

void Battery_Sensor::update() {
    batteryTemperature = rand() % 51;
    batteryLevel = rand() % 101;
}

unsigned int Battery_Sensor::getBatteryTemp() const {
    return batteryTemperature;
}