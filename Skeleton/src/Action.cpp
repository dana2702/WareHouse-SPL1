#pragma once
#include "Action.h"
#include "Volunteer.h"
#include <iostream>
using namespace std;

BaseAction::BaseAction(){}

    ActionStatus BaseAction::getStatus() const{
        return this->status;
    }

    void BaseAction::complete(){
        this->status=ActionStatus::COMPLETED;
    }

    void BaseAction::error(string errorMsg){
        this->status=ActionStatus::ERROR;
        this->errorMsg = errorMsg;
        std::cout << errorMsg << std::endl;
    }

    string BaseAction::getErrorMsg() const{
        return this->errorMsg;
    }


//constructor
AddOrder::AddOrder(int id): customerId(id){}

void AddOrder::act(WareHouse &wareHouse){
    // if the provided customer ID doesn’t exist: ”Cannot place this order”.
    if (customerId > wareHouse.getCustomerCounter()){
        error("Cannot place this order");
        std::cout << getErrorMsg() << std::endl;
    }
    // the id is ok
    else{
        for(Customer* cus : wareHouse.getCustomerVector()){
            if(cus->getId() == customerId){
                // if the customer reaches his maxOrders limit: ”Cannot place this order”.
                if (cus->getOrdersIds().size() < cus->getMaxOrders())
                {
                    error("Cannot place this order");
                }
            }    // the input is ok
            else{
                std::cout << "Performing order action with number: " << customerId << std::endl;
                // the code for 'order' action here
                Order* newOrder = new Order(wareHouse.getOrderCounter(), customerId, cus->getCustomerDistance());
                cus->addOrder(newOrder->getId());
                wareHouse.addOrder(newOrder);
                complete();
            }
        }
    }
}
           

    string AddOrder::toString() const{
        if( getStatus() == ActionStatus::COMPLETED){
            return ("Order "+ std::to_string(customerId) + " COMPLETED");
        }
        else{
            return ("Order "+ std::to_string(customerId) + " ERROR");
        }
    }

    AddOrder* AddOrder::clone() const{
        return new AddOrder(*this);
    }




AddCustomer::AddCustomer(const string &customerName, const string &customerType, int distance, int maxOrders)
    :customerName(customerName),customerType(StringToType(customerType)),distance(distance),maxOrders(maxOrders){}

    CustomerType AddCustomer:: StringToType(string customerType){
        if(customerType=="Soldier"){
            return CustomerType::Soldier;
        }
        else{
            return CustomerType::Civilian;
        }
    }

    void AddCustomer::act(WareHouse &wareHouse){

        // WHEN WE FINISH SUCCESSFULLY
        if(customerType==CustomerType::Soldier){
            SoldierCustomer* cust = new SoldierCustomer( wareHouse.getCustomerCounter(), customerName, distance, maxOrders);
            wareHouse.getCustomerVector().push_back(cust);
        }else{
            CivilianCustomer* cust = new CivilianCustomer( wareHouse.getCustomerCounter(), customerName, distance, maxOrders);
            wareHouse.getCustomerVector().push_back(cust);
        }
        complete();
    }

    AddCustomer* AddCustomer::clone() const{
        return new AddCustomer(*this);
    }

    string AddCustomer::toString() const{
        if(customerType==CustomerType::Civilian){
            return ("customer "+ customerName+  " civilian "+ std::to_string(distance) + std::to_string(maxOrders));
        }
        else{
            return ("customer "+ customerName+  " solider "+ std::to_string(distance) + std::to_string(maxOrders));
        }
    }



PrintOrderStatus::PrintOrderStatus(int id):orderId(id){}

    void PrintOrderStatus::act(WareHouse &wareHouse){

    // if the provided order ID doesn’t exist: ”Cannot place this order”.
        if (orderId > wareHouse.getOrderCounter()){
            error("Order doesn't exist");
            std::cout << getErrorMsg() << std::endl;           
         }
        // the id is ok
        else{
            bool flag = false;
            std::cout << "OrderId:"<< orderId << std::endl;
            for(Order* ord : wareHouse.getPendingOrderVector()){
                if(ord->getId() == orderId){
                    std::cout << "OrderStatus: PENDING"<<  std::endl;
                    std::cout << "CustomerID: "<< ord->getCustomerId()<<  std::endl;  
                    if(ord->getCollectorId() == NO_VOLUNTEER){
                        std::cout << "CollectorID: none"<<  std::endl;
                    }else{
                        std::cout << "Collector: "<< ord->getCollectorId()<<  std::endl;
                    }
                    if( ord->getDriverId() == NO_VOLUNTEER){
                        std::cout << "DriverID: none"<<  std::endl;
                    }else{
                        std::cout << "DriverID: "<< ord->getDriverId()<<  std::endl;
                    }
                    flag=true;
                }
            }
            if(!flag){
                for(Order* ord : wareHouse.getinProcessOrdersVector()){
                    if(ord->getId() == orderId){
                        if(ord->getStatus() == OrderStatus::COLLECTING){
                            std::cout << "OrderStatus: COLLECTING"<<  std::endl;
                        }
                        else if (ord->getStatus() == OrderStatus::DELIVERING){
                            std::cout << "OrderStatus: DELIVERING"<<  std::endl;
                        }
                        std::cout << "CustomerID: "<< ord->getCustomerId()<<  std::endl;  
                        if( ord->getCollectorId() == NO_VOLUNTEER){
                            std::cout << "CollectorID: none"<<  std::endl;
                        }else{
                            std::cout << "Collector: "<< ord->getCollectorId()<<  std::endl;
                        }
                        if( ord->getDriverId() == NO_VOLUNTEER){
                            std::cout << "DriverID: none"<<  std::endl;
                        }else{
                            std::cout << "DriverID: "<< ord->getDriverId()<<  std::endl;
                        }
                        flag=true;
                    }
                }  
            }
            
            if(!flag){
                for(Order* ord : wareHouse.getCompletedOrdersVector()){
                    if(ord->getId() == orderId){
                        std::cout << "OrderStatus: COMPLETED"<<  std::endl;
                        std::cout << "CustomerID: "<< ord->getCustomerId()<<  std::endl;  
                        std::cout << "Collector: "<< ord->getCollectorId()<<  std::endl;
                        std::cout << "DriverID: "<< ord->getDriverId()<<  std::endl;
                    }
                }
            } 

            if (flag)
            {
                complete();
            }
            else{
                error("Order doesn't exist");
                std::cout << getErrorMsg() << std::endl;           
            }
              
        }
    };


    PrintOrderStatus* PrintOrderStatus::clone() const{
            return new PrintOrderStatus(*this);
    }

    string PrintOrderStatus::toString() const{
        return "PrintOrderStatus";
    }




PrintCustomerStatus::PrintCustomerStatus(int customerId):customerId(customerId){}

    void PrintCustomerStatus::act(WareHouse &wareHouse) {
         // if the provided customer ID doesn’t exist: ”Cannot place this order”.
        if (customerId > wareHouse.getCustomerCounter()){
            error("Customer doesn't exist");
            std::cout << getErrorMsg() << std::endl;           
        }
        // the id is ok
        else{
            std::cout << "CustomerID:"<< customerId << std::endl;
            for(Order* ord : wareHouse.getPendingOrderVector()){
                if(ord->getCustomerId() == customerId){
                    std::cout << "OrderID: "<< ord->getId()<<  std::endl;
                    std::cout << "OrderStatus: PENDING"<<  std::endl;
                }
            }
            for(Order* ord : wareHouse.getinProcessOrdersVector()){
                    if(ord->getCustomerId() == customerId){
                        std::cout << "OrderID: "<< ord->getId()<<  std::endl;  
                        if(ord->getStatus() == OrderStatus::COLLECTING){
                            std::cout << "OrderStatus: COLLECTING"<<  std::endl;
                        }
                        else if (ord->getStatus() == OrderStatus::DELIVERING){
                            std::cout << "OrderStatus: DELIVERING"<<  std::endl;
                        }
                    }
            }  
            for(Order* ord : wareHouse.getCompletedOrdersVector()){
                    if(ord->getCustomerId() == customerId){
                    std::cout << "OrderID: "<< ord->getId()<<  std::endl;
                    std::cout << "OrderStatus: COMPLETED"<<  std::endl;
                    }
            }
            complete();
        }
        
    }


    PrintCustomerStatus* PrintCustomerStatus::clone() const {
        return new PrintCustomerStatus(*this);
    }



    string PrintCustomerStatus::toString() const{
         return "PrintCustomerStatus";
    }




PrintVolunteerStatus::PrintVolunteerStatus(int id): volunteerId(id){}

    void PrintVolunteerStatus:: act(WareHouse &wareHouse){
        // if the provided Volunteer ID doesn’t exist: ”Cannot place this order”.
        if (volunteerId > wareHouse.getVolunteerCounter()){
            error("Volunteer doesn’t exist");
            std::cout << getErrorMsg() << std::endl;
        }
        // the id is ok
        else{
            bool flag = false;
            for(Volunteer* voli : wareHouse.getvolunteersVector()){
                if(voli->getId() == volunteerId){
                    std::cout << "VolunteerID: "<< voli->getId()<<  std::endl;
                    if(voli->isBusy()){
                        std::cout << "isBusy: True"<< std::endl;
                        std::cout << "OrderID: "<< voli->getActiveOrderId()<<  std::endl;
                    }
                    else{
                        std::cout << "isBusy: False"<< std::endl;
                        std::cout << "OrderID: None"<<  std::endl;
                    }
                    if(DriverVolunteer* driverVoli = dynamic_cast<DriverVolunteer*>(voli)){
                        std::cout << "TimeLeft: "<< driverVoli->getDistanceLeft()<< std::endl;
                        std::cout << "OrdersLeft: no limit"<<  std::endl;
                    }
                    if(LimitedDriverVolunteer* LidriverVoli = dynamic_cast<LimitedDriverVolunteer*>(voli)){
                        std::cout << "TimeLeft: "<< LidriverVoli->getDistanceLeft()<< std::endl;
                        std::cout << "OrdersLeft:"<< LidriverVoli->getNumOrdersLeft()<< std::endl;
                    }
                    if(CollectorVolunteer* coliVoli = dynamic_cast<CollectorVolunteer*>(voli)){
                        std::cout << "TimeLeft: "<< coliVoli->getTimeLeft()<< std::endl;
                        std::cout << "OrdersLeft: no limit"<<  std::endl;
                    }
                    if(LimitedCollectorVolunteer* LicoliVoli = dynamic_cast<LimitedCollectorVolunteer*>(voli)){
                        std::cout << "TimeLeft: "<< LicoliVoli->getTimeLeft()<< std::endl;
                        std::cout << "OrdersLeft:"<< LicoliVoli->getNumOrdersLeft()<< std::endl;
                    }
                    flag =true;
                    complete();
                }    
                
                
            }
            
            if(!flag){
                error("Volunteer doesn’t exist");
                std::cout << getErrorMsg() << std::endl;
            }
        }
    }



    PrintVolunteerStatus* PrintVolunteerStatus::clone() const {
        return new PrintVolunteerStatus(*this);

    }



    string PrintVolunteerStatus::toString() const{
         return "PrintVolunteerStatus";
     }



PrintActionsLog::PrintActionsLog(){}

    void PrintActionsLog:: act(WareHouse &wareHouse){
        for (BaseAction* act : wareHouse.getActionsLog()) {
            std::cout << act->toString() << std::endl;
        }
    }


    PrintActionsLog* PrintActionsLog::clone() const {
        return new PrintActionsLog(*this);
    }


    string PrintActionsLog::toString() const{
        return "PrintActionsLog";
    }



Close::Close(){}

    void Close:: act(WareHouse &wareHouse){
        wareHouse.close();
    }


    Close* Close::clone() const {
        return new Close(*this);
    }

    string Close::toString() const{
        return "Close";
    }




BackupWareHouse::BackupWareHouse(){}

    void BackupWareHouse:: act(WareHouse &wareHouse){
    }


    BackupWareHouse* BackupWareHouse::clone() const {
        return new BackupWareHouse(*this);
    }


    string BackupWareHouse::toString() const{
        return "BackupWareHouse";
    }




RestoreWareHouse::RestoreWareHouse(){}

    void RestoreWareHouse:: act(WareHouse &wareHouse){
    }

    RestoreWareHouse* RestoreWareHouse::clone() const {
        return new RestoreWareHouse(*this);
    }
    

    string RestoreWareHouse::toString() const{
        return "RestoreWareHouse";
}