#ifndef SENSOR__H
#define SENSOR__H

#include <iostream>
#include <cstdlib>  
using namespace std;

class Sensor
{
public:
    Sensor() {}
    ~Sensor() {}
    virtual unsigned int getValue() const = 0;
    virtual void update() = 0;
};

#endif  //SENSOR__H

