#include "Customer.h"
#include <iostream>
#include <vector>

using namespace std;


class Customer {
Customer(int id, const string &name, int locationDistance, int maxOrders): id(this.id), name(this.name), locationDistance(this.locationDistance), maxOrders(this.maxOrders),ordersId(){
    std::vector<int> ordersId;
}

Customer(Customer other): id(other.getId()), name(other.getName()), locationDistance(other.getCustomerDistance()), maxOrders(other.getMaxOrders()),ordersId(){
    std::vector<int> ordersId;

    for (int i = 0; i < other.ordersId.size(); i++)
    {
        this.ordersId.push_back(other.ordersId.at(i));
    }
    
    //         this.ordersId = other.ordersId;
}

 int getId() const{
    return thid.id;
 }

const string &getName() const{
    return this.name;
}

int getCustomerDistance() const{
    return this.locationDistance;
}

int getMaxOrders() const{
    return this.maxOrders;
}

int getNumOrders() const{
    return this.ordersId.size();
} 
        
bool canMakeOrder() const{
    if (this.getNumOrders() < this.getMaxOrders())
    {
        return true;
    }
    return false;
}

const vector<int> &getOrdersIds() const{
    return this.orderId;
}

int addOrder(int orderId){
    
    for (int i = 0; i < ordersId.size(); i++)
    {
        if (ordersId.at(i)==orderId)
        {
            if(this.canMakeOrder()){
            this.ordersId.push_back(orderId);
            return ordersId;
            }
        }    
    }
    return -1;
}

virtual Customer *clone() const{
    return new Costumer(*this);
} 
}


class SoldierCustomer: public Customer {

        SoldierCustomer(int id, const string &name, int locationDistance, int maxOrders): Customer(id,&name,locationDistance, maxOrders){}
        SoldierCustomer(SoldierCustomer other): Customer(other){}
        SoldierCustomer *clone() const {
            return new SoldierCustomer(*this);
        }

}

class CivilianCustomer: public Customer {
        CivilianCustomer(int id, const string &name, int locationDistance, int maxOrders): Customer(id,&name,locationDistance, maxOrders){}
        CivilianCustomer(CivilianCustomer other): Customer(other){}
        CivilianCustomer *clone() const {
            return new CivilianCustomer(*this);
        }
}