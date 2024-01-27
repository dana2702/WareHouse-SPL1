#include "WareHouse.h"
#include <fstream>
#include <iostream>
using std:: string;
#include <sstream>


WareHouse::WareHouse(const string &configFilePath)
: isOpen(false), actionsLog(actionsLog),volunteers(volunteers),pendingOrders(pendingOrders),inProcessOrders(inProcessOrders),completedOrders(completedOrders),customers(customers) ,customerCounter(0),volunteerCounter(0),orderCounter(0){}

    int extractNumber(const std::string& str) {
    std::istringstream iss(str);
    std::string token;

    // Skip the first token ("step")
    iss >> token;

    // Extract the number
    int number;
    if (iss >> number) {
        return number;
    }
}
    
    void WareHouse::start(){
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
        

       
    }

        
        
        else if (action =="order"){

        }  

        else if (action =="customer"){  
        }

        else if (action =="orderStatus"){  
        }

        else if (action =="customerStatus"){  
        }
        
        else if (action =="volunteerStatus"){  
        }

        else if (action =="log"){  

            // for (int i = 0; i < actionsLog.size(); i++)
            // {
            //     actionsLog->at(i)->toString();
            // }

            // for (BaseAction* act : actionsLog) {
            //      act->toString();
            // }

        }

        else if (action =="close"){  
        }

        else if (action =="backup"){  
        }

        else if (action =="restore"){  
        }
    





    

};
int WareHouse::getOrderCounter(){
    return orderCounter;
};

int WareHouse::getVolunteerCounter(){
    return volunteerCounter;
};

int WareHouse::getCustomerCounter(){
    return customerCounter;
}



