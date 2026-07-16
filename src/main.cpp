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
    struct Sensor sensor1={1,"DS18B20",
        SensorType::Temperature,0,"C",
    1,""};

    m_Sensor sensorManage(sensor1);

    sensorManage.printInfo();


}