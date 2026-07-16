#include <iostream>
#include <string>
#include <vector>



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

    explicit m_Sensor(const Sensor &sensor):sensor(sensor)
    {
        std::cout << "Sensor created" << std::endl;
    }

    ~m_Sensor() {
        std::cout << "Sensor deleted" << std::endl;
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

int main() {
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
    std::vector<m_Sensor> sensors;
    sensors.reserve(3); // 预分配内存，防止扩容
    sensors.emplace_back(sensor1);
    sensors.emplace_back(sensor2);
    sensors.emplace_back(sensor3);

    if (sensors.empty()) {
        std::cout << "No sensors available.\n";
    } else {
        for (const auto& sensor : sensors) {
            sensor.printInfo();
        }
    }


}