#include <iostream>
#include <vector>
#include "../include/SensorManager.h"

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
            sensorsAdd();
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