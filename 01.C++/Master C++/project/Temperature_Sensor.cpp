#include "Temperature_Sensor.hpp"
Temperature_Sensor::Temperature_Sensor() : temperature(0) {}

Temperature_Sensor::~Temperature_Sensor() {}

unsigned int Temperature_Sensor::getValue() const {
    return temperature;
}

void Temperature_Sensor::update() {
    temperature = rand() % 101;
}