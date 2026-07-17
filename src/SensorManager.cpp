//
// Created by 25242 on 2026/7/16.
//
#include "../include/Sensor.h"
#include "../include/SensorManager.h"
#include <iostream>
#include <limits>
#include <string>


void SensorManager::initialize() {
    struct Sensor sensor1={
        1,
        "DS18B20",
        SensorType::Temperature,
        0,
        "C",
        1,
        ""
    };
    //m_Sensor m_sensor1(sensor1);

    struct Sensor sensor2={
        2,
        "DS18B21",
        SensorType::Humidity,
        0,
        "RH",
        0,
        ""
    };
    //m_Sensor m_sensor2(sensor2);

    struct Sensor sensor3={
        3,
        "DS18B23",
        SensorType::Light,
        0,
        "cd",
        1,
        ""
    };
    //m_Sensor m_sensor3(sensor3);


    //std::vector<m_Sensor> sensors={m_sensor1,m_sensor2,m_sensor3};

    sensors.reserve(3); // 预分配内存，防止扩容
    sensors.emplace_back(sensor1);
    sensors.emplace_back(sensor2);
    sensors.emplace_back(sensor3);
}

void SensorManager::showAllSensors() const {
    if (sensors.empty()) {
        std::cout << "No sensors available.\n";
    } else {
        for (const auto& sensor : sensors) {
            sensor.printInfo();
        }
    }
}

void SensorManager::addsensor() {
    struct Sensor tempSensor={};
    std::cout << "input:" << std::endl;

    while (true) {
        std::cout << "ID: ";

        if (!(std::cin >> tempSensor.id)) {
            std::cout << "ID must be a number.\n";
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n'
            );
            continue;
        }

        bool duplicate = false;

        for (const auto& sensor : sensors) {
            if (tempSensor.id == sensor.sensor.id) {
                duplicate = true;
                break;
            }
        }

        if (duplicate) {
            std::cout << "ID already exists.\n";
            continue;
        }

        break;
    }

    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Name: ";
    std::getline(std::cin, tempSensor.name);

    while (true) {
        std::cout << "Type: ";

        if (std::cin >> tempSensor.type) {
            break;
        }

        std::cout << "Invalid sensor type.\n";
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );
    }

    std::cout << "Data:";
    std::cin >> tempSensor.data;
    std::cout << "Unit:";
    std::cin >> tempSensor.unit;
    std::cout << "Active:";
    std::cin >> tempSensor.active;
    std::cin.ignore(
    std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Label:";
    std::getline(std::cin, tempSensor.label);
    std::cout << std::endl;
    sensors.emplace_back(tempSensor);
}

int SensorManager::findSensor(const int id) {
    for (int i = 0; i < sensors.size(); ++i) {
        if (id==sensors[i].sensor.id) {
            return i;
        }
    }
    return -1;
}

void SensorManager::upgradeSensor(int i) {
    int command;
    std::cout << "press 1 to change data" << std::endl;
    std::cout << "press 2 to change active" << std::endl;
    std::cout << "press 3 to change label" << std::endl;
    std::cin >> command;
    switch (command) {
        case 1: {
            double data;
            std::cin >> data;
            sensors[i].sensor.data = data;
            std::cout << "data changed" << std::endl;
            break;
        }
        case 2: {
            bool active;
            std::cin >> active;
            sensors[i].sensor.active = active;
            std::cout << "active changed" << std::endl;
            break;
        }
        case 3: {
            std::string label;
            std::cin >> label;
            sensors[i].sensor.label = label;
            std::cout << "label changed" << std::endl;
            break;
        }
        default: {
            std::cout << "invalid command" << std::endl;
        }
    }
}

void SensorManager::addSensor() {
    SensorManager::addsensor();
    std::cout << "--------------------------------" << std::endl;
    std::cout << "success" << std::endl;
    sensors.back().printInfo();
}

void SensorManager::printSensor() {
    int input_id;
    std::cout << "input ID:" << std::endl;
    std::cin >> input_id;
    int i = findSensor(input_id);
    if (i == -1) {
        std::cout << "id not found" << std::endl;
    }
    else {
        sensors[i].printInfo();
    }
}

void SensorManager::updateSensor() {
    int input_id;
    std::cout << "input ID:" << std::endl;
    std::cin >> input_id;
    int i = findSensor(input_id);
    if (i == -1) {
        std::cout << "id not found" << std::endl;
    }
    else {
        upgradeSensor(i);
    }
}

void SensorManager::eraseSensor() {
    int inputid;
    std::cout << "enter the sensor id" << std::endl;
    std::cin >> inputid;
    int i = findSensor(inputid);
    if (i== -1) {
        std::cout << "sensor not found" << std::endl;
    }
    else {
        std::cout << "Are you sure?" << std::endl;
        bool fl = false;
        std::cin >> fl;
        if (fl == true) {
            auto v = sensors.begin()+i;
            sensors.erase(v);
            std::cout << "sensor deleted" << std::endl;
        }
    }
}

void SensorManager::run() {
    int mode;
    initialize();
    while (true) {
        std::cout << "what are you doing?" << std::endl;
        std::cout << "press 1 to add sensor" << std::endl;
        std::cout << "press 2 to find sensor" << std::endl;
        std::cout << "press 3 to upgrade sensor" << std::endl;
        std::cout << "press 4 to erase sensor" << std::endl;
        std::cout << "press 5 to show all sensors" << std::endl;
        std::cout << "press 0 to exit" << std::endl;
        std::cin >> mode;
        switch (mode){
            case 1:{
                addSensor();
                std::cin.get();
                break;
            }
            case 2: {
                printSensor();
                std::cin.get();
                break;
            }
            case 3: {
                updateSensor();
                std::cin.get();
                break;
            }
            case 4: {
                eraseSensor();
                std::cin.get();
                break;
            }
            case 5: {
                showAllSensors();
                std::cin.get();
                break;
            }
            case 0: {
                std::cout << "exit..." << std::endl;
                std::cin.get();
                break;
            }
            default:{
                std::cout << "Unknown input." << std::endl;
                break;
            }
        }
        if (!mode) {
            break;
        }
    }
}
