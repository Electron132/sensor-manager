//
// Created by 25242 on 2026/7/16.
//

#ifndef SENSOR_H
#define SENSOR_H
#include <string>
#include <iostream>



enum class SensorType {
    Temperature,
    Humidity,
    Light
};

struct Sensor {
    int id;
    std::string name;
    SensorType type;
    double data;
    std::string unit;
    bool active;
    std::string label;


};

class m_Sensor {
public:
    Sensor sensor;

    explicit m_Sensor(const Sensor &sensor);

    ~m_Sensor() ;

    void printInfo() const;
};

std::istream& operator>>(std::istream& is, SensorType& type);

#endif //SENSOR_H
