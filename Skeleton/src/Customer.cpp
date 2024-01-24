#include "/home/naomi/SPL/SPL_1/hadassi/Skeleton/include/Customer.h"
#include <iostream>
#include <vector>
#pragma once

using namespace std;


    // Constructor
    Customer::Customer(int id, const string &name, int locationDistance, int maxOrders)
        : id(id), name(name), locationDistance(locationDistance), maxOrders(maxOrders), ordersId() {}

    // Copy constructor
    Customer::Customer(const Customer &other)
        : id(other.id), name(other.name), locationDistance(other.locationDistance),
          maxOrders(other.maxOrders), ordersId(other.ordersId) {}
    
    


 int Customer::getId() const{
    return this->id;
 }

const string& Customer::getName() const{
    return this->name;
}

int Customer::getCustomerDistance() const{
    return this->locationDistance;
}

int Customer::getMaxOrders() const{
    return this->maxOrders;
}

int Customer::getNumOrders() const{
    return this->ordersId.size();
} 
        
bool Customer::canMakeOrder() const{
    if (this->getNumOrders() < this->getMaxOrders())
    {
        return true;
    }
    return false;
}

const vector<int>& Customer::getOrdersIds() const{
    return this->ordersId;
}

int Customer::addOrder(int orderId){
    
    for (int i = 0; i < ordersId.size(); i++)
    {
        if (ordersId.at(i)==orderId)
        {
            if(this->canMakeOrder()){
            this->ordersId.push_back(orderId);
            return orderId;
            }
        }    
    }
    return -1;
}

Customer* Customer::clone() const{
    //return new Customer(*this);
} 


    // constructor
    SoldierCustomer::SoldierCustomer(int id, const string &name, int locationDistance, int maxOrders)
        : Customer(id, name, locationDistance, maxOrders) {}

    // Copy constructor
    SoldierCustomer::SoldierCustomer(const SoldierCustomer &other) : Customer(other) {}

    SoldierCustomer* SoldierCustomer::clone() const {
            return new SoldierCustomer(*this);
    }



    //constructor
    CivilianCustomer::CivilianCustomer(int id, const string &name, int locationDistance, int maxOrders) 
            :Customer(id, name, locationDistance, maxOrders){}

    //copy constructor
    CivilianCustomer::CivilianCustomer(const CivilianCustomer &other): Customer(other){}

    CivilianCustomer* CivilianCustomer::clone() const {
            return new CivilianCustomer(*this);
    }
