#include <iostream>
#include <vector>
#include "../include/SensorManager.h"



int main() {
    int mode;
    sensorsInit();

    std::cout << "what are you doing?" << std::endl;
    std::cout << "press 1 to add sensor" << std::endl;
    std::cout << "press 2 to find sensor" << std::endl;
    
    std::cin >> mode;
    switch (mode){
        case 1:{
            sensorsAdd();
            std::cout << "--------------------------------" << std::endl;
            std::cout << "success" << std::endl;
            sensors.back().printInfo();
            break;
        }
        case 2: {
            int input_id;
            std::cout << "input ID:" << std::endl;
            std::cin >> input_id;
            int i = foundid(input_id, sensors);
            if (i == -1) {
                std::cout << "id not found" << std::endl;
            }
            else {
                sensors[i].printInfo();
            }
            break;
        }
        default:{
            std::cout << "Unknown input." << std::endl;
            break;
        }
    }
}
