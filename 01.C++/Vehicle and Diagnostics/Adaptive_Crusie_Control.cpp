#include "Adaptive_Crusie_Control.hpp"
Adaptive_Cruise_Control::Adaptive_Cruise_Control(Speed_Sensor *speed_sensor, Radar_Sensor *radar_sensor, Temperature_Sensor *temp_sensor){
    this->speed_sensor = speed_sensor;
    this->radar_sensor = radar_sensor;
    this->temp_sensor = temp_sensor;
    logger = Logger::getInstance();     
}

Adaptive_Cruise_Control::~Adaptive_Cruise_Control() 
{

}

void Adaptive_Cruise_Control::cruiseControl() 
{
    unsigned int speed = speed_sensor->getValue();
    unsigned int temperature = temp_sensor->getValue();
    unsigned int distance = radar_sensor->getValue();
    if(speed > SAFE_SPEED){
        speed_sensor->controlSpeed(SAFE_SPEED);
        logger->log("AdaptiveCruiseControl: Automatic decelerating activated... Speed is very high!", LogLevel::WARNING, OutputDestination::BOTH);
    }
    if(distance <= SAFE_DISTANCE){
        speed_sensor->controlSpeed(STOP_CAR);
        logger->log("AdaptiveCruiseControl: Automatic brake activated... An object is infront of you!", LogLevel::CRITICAL, OutputDestination::BOTH);
    }
    else if(temperature >= SAFE_TEMPERATURE && temperature < THRESHOLD_TEMPERATURE){
        speed_sensor->controlSpeed(SLOW_CAR);
        logger->log("AdaptiveCruiseControl: Automatic decelerating activated... Car temperature is high!", LogLevel::WARNING, OutputDestination::BOTH);
    }
    else if(temperature >= THRESHOLD_TEMPERATURE){
        while(speed_sensor->getValue() > 0){
            speed_sensor->controlSpeed(speed_sensor->getValue() - 10);
        }
        speed_sensor->controlSpeed(STOP_CAR);
        logger->log("AdaptiveCruiseControl: Automatic parking activated... Car temperature is very high!", LogLevel::CRITICAL, OutputDestination::BOTH);
    }
}