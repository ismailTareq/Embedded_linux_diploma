#include "Speed_Sensor.hpp"

Speed_Sensor::Speed_Sensor() : speed(0) {}

Speed_Sensor::~Speed_Sensor() {}

unsigned int Speed_Sensor::getValue() const 
{
    return speed;
}

void Speed_Sensor::update() 
{
    speed = rand() % 251;
}

void Speed_Sensor::controlSpeed(unsigned int sp) 
{
    speed = sp;
}