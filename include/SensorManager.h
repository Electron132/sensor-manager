//
// Created by 25242 on 2026/7/16.
//

#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include "Sensor.h"
#include <vector>

class SensorManager {
    private:
    std::vector<m_Sensor> sensors;
    void addsensor();
    public:
    void initialize();
    void addSensor();
    int findSensor(const int id);
    void printSensor();
    void upgradeSensor(int i);
    void updateSensor();
    void eraseSensor();
    void showAllSensors() const;
    void run();
};



#endif //SENSORMANAGER_H
