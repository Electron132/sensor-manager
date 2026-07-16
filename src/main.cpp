#include <iostream>
#include <string>
#include <vector>
#include <limits>

enum class SensorType {
    Temperature,
    Humidity,
    Light
};

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

    explicit m_Sensor(const Sensor &sensor):sensor(sensor)
    {
        std::cout << "Sensor created" << std::endl;
    }

    ~m_Sensor() {
        //std::cout << "Sensor deleted" << std::endl;
    }

    void printInfo() const {
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
};

std::vector<m_Sensor> sensors;

void sensorsInit() {
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

void sensorsLoop() {
    if (sensors.empty()) {
        std::cout << "No sensors available.\n";
    } else {
        for (const auto& sensor : sensors) {
            sensor.printInfo();
        }
    }
}

int main() {
    int mode;
    sensorsInit();

    std::cout << "what are you doing?" << std::endl;
    std::cout << "press 1" << std::endl;
    std::cin >> mode;
    switch (mode)
    {
        case 1:
        {
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
            std::cout << "--------------------------------" << std::endl;
            std::cout << "success" << std::endl;
            sensors.back().printInfo();
            break;
        }
        default:
        {
            std::cout << "Unknown input." << std::endl;
            break;
        }
    }


    //sensorsLoop();

}