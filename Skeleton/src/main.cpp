// #include "/home/naomi/SPL/SPL_1/hadassi/Skeleton/include/WareHouse.h"
#include <iostream>
#include <fstream>

using std:: string;
#include <sstream>

using namespace std;

// WareHouse* backup = nullptr;

// int main(int argc, char** argv){
//     if(argc!=2){
//         std::cout << "usage: warehouse <config_path>" << std::endl;
//         return 0;
//     }
//     string configurationFile = argv[1];
//     cout << configurationFile<< endl;
//     // WareHouse wareHouse(configurationFile);
//     // wareHouse.start();
//     // if(backup!=nullptr){
//     // 	delete backup;
//     // 	backup = nullptr;
//     // }
//     return 0;
// }

int main(int argc, char** argv){
    #include <iostream>
#include <string>
#include <sstream>


    std::string str;
    std::cout << "Enter action: ";
    std::getline(std::cin, str);
    std::cout << "You entered: " << str << std::endl;

    // Extract the action (first word)
    std::istringstream iss(str);
    std::string action;
    iss >> action;

    // Perform actions based on the first word
    if (action == "step") {
        // Extract the number for step action
        int number;
        if (iss >> number) {
            std::cout << "Performing step action with number: " << number << std::endl;
            // Your code for 'step' action here
        } else {
            std::cout << "Invalid input: No number found for 'step' action." << std::endl;
            return 1; // Return error code
        }
    } else if (action == "order") {
        // Extract the number for order action
        int number;
        if (iss >> number) {
            std::cout << "Performing order action with number: " << number << std::endl;
            // Your code for 'order' action here
        } else {
            std::cout << "Invalid input: No number found for 'order' action." << std::endl;
            return 1; // Return error code
        }
    

    return 0;
}

//         std::string str;
//         std::string digits;
//         std::cout << "Enter action: ";
//         std::getline(std::cin, str);
//        // std::cout << "You entered: " << str << std::endl;
//         std::istringstream iss(str);
//         std::string token;

//         // Extract the action (first word)
//         std::string action;
//         iss >> action;
//         if(action == "step"){
//             // Skip the first token ("step")
//             iss >> token;
//             // Extract the number
//             int number;
//             if (iss >> number) {
//             std::cout << "number is: " << number << std::endl; 
//             }
//         }else if(action == "order"){
//             // Skip the first token ("step")
//             iss >> token;
//             // Extract the number
//             int number;
//             if (iss >> number) {
//             std::cout << action << "is: " << number << std::endl; 
//             }
//         }
       



//         return 0;
};
