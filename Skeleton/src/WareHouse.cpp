#include "WareHouse.h"
#include "Action.h"

#include <fstream>
#include <iostream>
using std:: string;
#include <sstream>


WareHouse::WareHouse(const string &configFilePath)
: isOpen(false), actionsLog(actionsLog),volunteers(volunteers),pendingOrders(pendingOrders),inProcessOrders(inProcessOrders),completedOrders(completedOrders),customers(customers) ,customerCounter(0),volunteerCounter(0),orderCounter(0){}

    
void WareHouse::start(){
    std::string input;
    std::cout << "Enter action: ";
    std::getline(std::cin, input);

    // Extract the action (first word)
    std::istringstream iss(input);
    std::string action;
    iss >> action;

    // Perform actions based on the first word
    if (action == "step") {
        // Extract the number for step action
        int number;
        if (iss >> number) {
            std::cout << "Performing step action with number: " << number << std::endl;
            // the code for 'step' action here
            SimulateStep* step = new SimulateStep(number);
            step->act(*this);
        } 
    } 


    else if (action == "order") {
        // Extract the number for order action
        int number;
        if (iss >> number) {
            AddOrder* order = new AddOrder(number);
            order->act(*this); 
        }      
    }  


    else if (action =="customer"){  
        // Extract the number for step action
        std::string *name;
       // iss >> *name;
        std::string *type;
        //iss >> *type;
        int distance;
        //iss >> distance;
        int maxOrd;
        //iss >> maxOrd;
        if(iss >> *name >> *type >> distance >> maxOrd){
            AddCustomer* cust = new AddCustomer(*name,*type, distance, maxOrd);
            cust->act(*this);
        }
        
    }

    else if (action =="orderStatus"){
        // Extract the number for orderStatus action
        int number;
        if (iss >> number) {
            // if the provided order ID doesn’t exist: ”Cannot place this order”.
            if (number > orderCounter){
                std::cout << "Cannot place this order" << std::endl;
            }
            // the id is ok
            else{
                    // לופ על כל רשימה ואם מוצאים א ההזמנה מחזירים את הסטטוס- שם הרשימה
                }
            }
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