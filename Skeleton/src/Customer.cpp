#pragma once
#include "Customer.h"
#include <iostream>
#include <vector>
using namespace std;


// Constructor
Customer::Customer(int id, const string &name, int locationDistance, int maxOrders)
     : id(id), name(name), locationDistance(locationDistance), maxOrders(maxOrders), ordersId() {}

    const string& Customer::getName() const{
        return this->name;
    }
    
    int Customer::getId() const{
        return this->id;
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
        if (this->getNumOrders() < this->getMaxOrders()){
            return true;
        }
        return false;
    }

    const vector<int>& Customer::getOrdersIds() const{
        return this->ordersId;
    }

    int Customer::addOrder(int orderId){
        
        for (int i = 0; i < ordersId.size(); i++){
            if (ordersId.at(i)==orderId){
                if(this->canMakeOrder()){
                    this->ordersId.push_back(orderId);
                    return orderId;
                }
            }    
        }
        return -1;
    }

// constructor
SoldierCustomer::SoldierCustomer(int id, const string &name, int locationDistance, int maxOrders)
    : Customer(id, name, locationDistance, maxOrders) {}


    SoldierCustomer* SoldierCustomer::clone() const {
        return new SoldierCustomer(*this);
    }



//constructor
CivilianCustomer::CivilianCustomer(int id, const string &name, int locationDistance, int maxOrders) 
    :Customer(id, name, locationDistance, maxOrders){}

    CivilianCustomer* CivilianCustomer::clone() const {
        return new CivilianCustomer(*this);
    }
