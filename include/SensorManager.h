//
// Created by 25242 on 2026/7/16.
//

#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H
#include "../include/SensorManager.h"
#include "../include/Sensor.h"
#include "vector"

inline std::vector<m_Sensor> sensors;

void sensorsInit();
void sensorsLoop();
void sensorsAdd();

#endif //SENSORMANAGER_H
