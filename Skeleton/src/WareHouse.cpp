#pragma once
#include "WareHouse.h"
#include "Action.h"
#include "Customer.h"

#include "Order.h"
#include "Volunteer.h"
using namespace std;
#include <fstream>
#include <iostream>
using std:: string;
#include <sstream>
#include <istream>


WareHouse::WareHouse(const string &configFilePath)
: isOpen(false), actionsLog(actionsLog),volunteers(volunteers),pendingOrders(pendingOrders),inProcessOrders(inProcessOrders),completedOrders(completedOrders),customers(customers) ,customerCounter(0),volunteerCounter(0),orderCounter(0){}

    
void WareHouse::start(){
    open();
    while(isOpen){
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
                addAction(order);
                        std::cout << "doneee" << std::endl;

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
            addAction(cust);
            }
            
        }

        else if (action =="orderStatus"){  
            // Extract the number for orderStatus action
            int number;
            if (iss >> number) {
                PrintOrderStatus* print = new PrintOrderStatus(number);
                print->act(*this);
            addAction(print);
            }    
        

        else if (action =="customerStatus"){  
            int number;
            if (iss >> number) {
                PrintCustomerStatus* print = new PrintCustomerStatus(number);
                print->act(*this);
                addAction(print);
            }    
        }
            
        else if (action =="volunteerStatus"){  
            int number;
            if (iss >> number) {
                PrintVolunteerStatus* print = new PrintVolunteerStatus(number);
                print->act(*this);
                addAction(print);
            }  
        }

        else if (action =="log"){  
            PrintActionsLog* log = new PrintActionsLog();
            log->act(*this);
            addAction(log);
        }

        else if (action =="close"){ 
            close(); 
        }

        else if (action =="backup"){  
        }

        else if (action =="restore"){  
        }
    }

}
};

        void WareHouse::addOrder(Order* order){
            pendingOrders.push_back(order);
        }

        void WareHouse::addAction(BaseAction* action){
            actionsLog.push_back(action);
        };


    Customer& WareHouse::getCustomer(int customerId) const {
        // Iterate through the vector to search for the customer
        for (Customer* cus : customers) {
            // Check if the customerId of the current customer matches the given customerId
            if (cus->getId() == customerId) {
                // Return a reference to the found customer
                return *cus;
            }
        }
    };

        Volunteer& WareHouse::getVolunteer(int volunteerId) const {
        // Iterate through the vector to search for the customer
        for (Volunteer* voli : volunteers) {
            // Check if the customerId of the current customer matches the given customerId
            if (voli->getId() == volunteerId) {
                // Return a reference to the found customer
                return *voli;
            }
        }
    };

        Order& WareHouse::getOrder(int orderId) const {
        // Iterate through the vector to search for the customer
       for(Order* ord : pendingOrders){
                if(ord->getId() == orderId){
                    return *ord;
                }
        }
         for(Order* ord : inProcessOrders){
                    if(ord->getId() == orderId){
                        return *ord;
                    }
         }
        for(Order* ord : completedOrders){
                    if(ord->getId() == orderId){
                        return *ord;
                    }
        }
    };


    void WareHouse::parseText(const string &configFilePath){
        ifstream configFile(configFilePath);
    if (!configFile.is_open()) {
        std::cerr << "Error opening the configuration file." << std::endl;
        return;
    }

    customerCounter = 0;
    volunteerCounter = 0;
    std::string line;
    while (getline(configFile, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "customer") {
            // Parse customer
            std::string name;
            std::string customerType;
            int distance;
            int maxOrders;

            iss >> name >> customerType >> distance >> maxOrders;

            if (customerType == "soldier") {
                AddCustomer *newCustomer = new AddCustomer(name, customerType,
                                                  distance, maxOrders);
            } else if (customerType == "civilian") {
                AddCustomer *newCustomer = new AddCustomer(name, customerType,
                                                  distance, maxOrders);
            } else {
                std::cerr << "Unknown customer type: " << customerType
                          << std::endl;
            }

         
            
        } else if (type == "volunteer") {
            // Parse volunteer
            std::string name;
            std::string volunteerType;
            int coolDown;
            int maxDistance;
            int distancePerStep;
            int maxOrders = -1;

            iss >> name >> volunteerType >> coolDown;

            Volunteer *newVolunteer = nullptr;
            if (volunteerType == "collector") {
                newVolunteer =
                    new CollectorVolunteer(volunteers.size(), name, coolDown);
            } else if (volunteerType == "limited_collector") {
                iss >> maxOrders;
                newVolunteer = new LimitedCollectorVolunteer(
                    volunteers.size(), name, coolDown, maxOrders);
            } else if (volunteerType == "driver") {
                iss >> maxDistance >> distancePerStep;
                newVolunteer = new DriverVolunteer(
                    volunteers.size(), name, maxDistance, distancePerStep);
            } else if (volunteerType == "limited_driver") {
                iss >> maxDistance >> distancePerStep >> maxOrders;
                newVolunteer = new LimitedDriverVolunteer(
                    volunteers.size(), name, maxDistance, distancePerStep,
                    maxOrders);
            } else {
                std::cerr << "Unknown volunteer type: " << volunteerType
                          << std::endl;
            }

            // add to warehouse
            if (newVolunteer) {
                volunteerCounter++;
                volunteers.push_back(newVolunteer);
            }
        }
    }

    configFile.close();
}
    




int WareHouse::getOrderCounter() const{
    return orderCounter;
};

int WareHouse::getVolunteerCounter() const{
    return volunteerCounter;
};

int WareHouse::getCustomerCounter() const{
    return customerCounter;
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



