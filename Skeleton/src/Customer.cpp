#include "Customer.h"
#include <iostream>
#include <vector>
#pragma once

using namespace std;


class Customer {
private:
    int id;
    string name;
    int locationDistance;
    int maxOrders;
    vector<int> ordersId;

public:
    // Constructor
    Customer(int id, const string &name, int locationDistance, int maxOrders)
        : id(id), name(name), locationDistance(locationDistance), maxOrders(maxOrders), ordersId() {}

    // Copy constructor
    Customer(const Customer &other)
        : id(other.id), name(other.name), locationDistance(other.locationDistance),
          maxOrders(other.maxOrders), ordersId(other.ordersId) {}
    
    


 int getId() const{
    return this->id;
 }

const string &getName() const{
    return this->name;
}

int getCustomerDistance() const{
    return this->locationDistance;
}

int getMaxOrders() const{
    return this->maxOrders;
}

int getNumOrders() const{
    return this->ordersId.size();
} 
        
bool canMakeOrder() const{
    if (this->getNumOrders() < this->getMaxOrders())
    {
        return true;
    }
    return false;
}

const vector<int> &getOrdersIds() const{
    return this->ordersId;
}

int addOrder(int orderId){
    
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

virtual Customer *clone() const{
    return new Customer(*this);
} 
};


class SoldierCustomer : public Customer {
public:
    // constructor
    SoldierCustomer(int id, const string &name, int locationDistance, int maxOrders)
        : Customer(id, name, locationDistance, maxOrders) {}

    // Copy constructor
    SoldierCustomer(const SoldierCustomer &other) : Customer(other) {}

    SoldierCustomer *clone() const {
            return new SoldierCustomer(*this);
    }

};

class CivilianCustomer: public Customer {
    //constructor
    CivilianCustomer(int id, const string &name, int locationDistance, int maxOrders) 
            :Customer(id, name, locationDistance, maxOrders){}

    //copy constructor
    CivilianCustomer(const CivilianCustomer &other): Customer(other){}

    CivilianCustomer *clone() const {
            return new CivilianCustomer(*this);
    }
};