#include "Radar_Sensor.hpp"
Radar_Sensor::Radar_Sensor() : distance(0) {}

Radar_Sensor::~Radar_Sensor(){}

unsigned int Radar_Sensor::getValue() const {
    return distance;
}

void Radar_Sensor::update() {
    distance = rand() % 40;
}