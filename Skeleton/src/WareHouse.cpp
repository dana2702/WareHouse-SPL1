#include "WareHouse.h"
#include <fstream>
#include <iostream>

using std:: string;


WareHouse::WareHouse(const string &configFilePath)
: isOpen(false), actionsLog(),volunteers(),pendingOrders(),inProcessOrders(),completedOrders(),customers() ,customerCounter(0),volunteerCounter(0),orderCounter(0){

}

void WareHouse::start(){
    std::string input;
    std::string digits;
    std::cout << "Enter action: ";
    std::getline(std::cin, input);
    std::cout << "You entered: " << input << std::endl;

    if(input.find("step")){
        // // Extract digits from input
        // for (char c : input) {
        //     if (std::isdigit(c)) {
        //         digits += c; // Append digit to digits string
        //     }
        // }

        // int number_of_steps = std::stoi(digits);
    }
    
    else if (input.find("order")){
        // // Extract digits from input
        // for (char c : input) {
        //     if (std::isdigit(c)) {
        //         digits += c; // Append digit to digits string
        //     }
        // }

        // int customer_id = std::stoi(digits);

        // for (int i = 0; i < customers.size(); i++)
        // {
        //     if (customers.at(i)->getId()==customer_id)
        //     {
        //         if(customers.at(i)->canMakeOrder()){
        //             Order* order = new Order(orderCounter++, customer_id, customer_id);
        //             this->addOrder(order);
        //         }    
        //     }
    }  

    else if (input.find("customer")){  
    }

    else if (input.find("orderStatus")){  
    }

    else if (input.find("customerStatus")){  
    }
    
    else if (input.find("volunteerStatus")){  
    }

    else if (input.find("log")){  

        // for (int i = 0; i < actionsLog.size(); i++)
        // {
        //     actionsLog->at(i)->toString();
        // }

        // for (BaseAction* act : actionsLog) {
        //      act->toString();
        // }

    }

    else if (input.find("close")){  
    }

    else if (input.find("backup")){  
    }

    else if (input.find("restore")){  
    }





    //  void WareHouse::addOrder(Order* order){

    //  }

};



