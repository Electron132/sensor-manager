//
// Created by 25242 on 2026/7/16.
//
#include "../include/Sensor.h"



m_Sensor::m_Sensor(const Sensor &sensor):sensor(sensor)
{
    std::cout << "Sensor created" << std::endl;
}

m_Sensor::~m_Sensor() {
    //std::cout << "Sensor deleted" << std::endl;
}

void m_Sensor::printInfo() const {
    std::cout << "ID: " << sensor.id << '\n';
    std::cout << "Name: " << sensor.name << '\n';
    std::cout << "Data: " << sensor.data << ' '
              << sensor.unit << '\n';
    switch (sensor.type) {
        case SensorType::Temperature:
            std::cout << "Type: Temperature\n";
            break;
        case SensorType::Humidity:
            std::cout << "Type: Humidity\n";
            break;
        case SensorType::Light:
            std::cout << "Type: Light\n";
            break;
    }
    std::cout << "Active: "
      << (sensor.active ? "Online" : "Offline")
      << '\n';
    std::cout << "Label: " << sensor.label << '\n';
}


std::istream& operator>>(std::istream& is, SensorType& type) {
    int val;
    is >> val;
    switch (val) {
        case 0:
            type = SensorType::Temperature;
            break;
        case 1:
            type = SensorType::Humidity;
            break;
        case 2:
            type = SensorType::Light;
            break;
        default:
            is.setstate(std::ios::failbit);

            break;
    }
    return is;

}