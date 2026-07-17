#include <iostream>
#include <vector>
#include "../include/SensorManager.h"



int main() {
    int mode;
    sensorsInit();
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
                sensoradd();
                break;
            }
            case 2: {
                sensorprint();
                break;
            }
            case 3: {
                sensorupdate();
                break;
            }
            case 4: {
                sensorerase();
                break;
            }
            case 5: {
                sensorsLoop();
                break;
            }
            case 0: {
                std::cout << "exit" << std::endl;
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
