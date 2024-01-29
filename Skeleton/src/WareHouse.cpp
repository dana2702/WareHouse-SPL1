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
            if(order->getStatus() == ActionStatus::COMPLETED){
                orderCounter++;
            }
            actionsLog.push_back(order);

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
            if(cust->getStatus() == ActionStatus::COMPLETED){
                customerCounter++;
            }
           actionsLog.push_back(cust);
        }
        
    }

    else if (action =="orderStatus"){  
        // Extract the number for orderStatus action
        int number;
        if (iss >> number) {
            PrintOrderStatus* print = new PrintOrderStatus(number);
            print->act(*this);
           actionsLog.push_back(print);
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
int WareHouse::getOrderCounter() const{
    return orderCounter;
};

int WareHouse::getVolunteerCounter() const{
    return volunteerCounter;
};

vector<Order*> WareHouse::getinProcessOrdersVector() const{
    return inProcessOrders;
};

vector<Order*> WareHouse::getCompletedOrdersVector() const{
    return completedOrders;
};

vector<Order*> WareHouse::getPendingOrderVector() const{
    return pendingOrders;
};

vector<BaseAction*> WareHouse::getActionsLog() const{
    return actionsLog;
};

vector<Volunteer*> WareHouse::getvolunteersVector() const{
    return volunteers;
};


