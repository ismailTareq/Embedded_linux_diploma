#include "Diagnostics.hpp"
Diagnostics::Diagnostics(Speed_Sensor* speed, Radar_Sensor* radar, Temperature_Sensor* temp, Battery_Sensor* batt) 
    : speedSensor(speed), radarSensor(radar), tempSensor(temp), battery(batt) {
    logger = Logger::getInstance(); 
}

Diagnostics::~Diagnostics() {}

void Diagnostics::runDiagnostics() {
    bool speedCheck = checkSpeed();
    bool radarCheck = checkRadar();
    bool tempCheck = checkTemperature();
    bool batteryCheck = checkBattery();

    if (!speedCheck && !radarCheck && !tempCheck && !batteryCheck) {
        logger->log("Diagnostics: Warning or error detected.", LogLevel::WARNING);
    }
}

bool Diagnostics::checkSpeed() {
    if (speedSensor->getValue() > SAFE_SPEED) { 
        logger->log("Diagnostics: Speed is very high!", LogLevel::WARNING, OutputDestination::BOTH);
        return false;
    }
    return true;
}

bool Diagnostics::checkRadar() {
    if (radarSensor->getValue() <= SAFE_DISTANCE) {
        logger->log("Diagnostics: Object is too close!", LogLevel::CRITICAL, OutputDestination::BOTH);
        return false;
    }
    return true;
}

bool Diagnostics::checkTemperature() {
    if (tempSensor->getValue() > SAFE_TEMPERATURE) { 
        logger->log("Diagnostics: Engine's temperature is high!", LogLevel::WARNING, OutputDestination::BOTH);
        return false;
    }
    return true;
}

bool Diagnostics::checkBattery() {
    if (battery->getValue() <= THRESHOLD_LEVEL) { 
        logger->log("Diagnostics: Battery level is low!", LogLevel::WARNING, OutputDestination::BOTH);
        return false;
    }
    return true;
}
