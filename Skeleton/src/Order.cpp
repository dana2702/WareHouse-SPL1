#include "/home/users/bsc/hadassi/Skeleton/include/Order.h"
#include <iostream>

using namespace std;

Order(int id, int customerId, int distance): id(this.id), customerId(this.customerId), distance(this.distance),status(Order.PENDING) ,collectorId(Order.NO_VOLUNTEER), driverId(Order.NO_VOLUNTEER){}

int getId() {
    return this.id;
}

int getCustomerId(){
    return this.customerId;
}

void setStatus(OrderStatus status){
    this.OrderStatus = status;
}

void setCollectorId(int collectorId){
    this.collectorId = collectorId;
}

void setDriverId(int driverId){
    this.driverId = driverId;
}

int getCollectorId() const{
    return this.collectorId;
}

int getDriverId() const{
    return this.getDriverId
}

OrderStatus getStatus() const {
    return this.status;
}

const string toString() const{
    return "";
}

// extras:

int getDistance() const{
    return this.distance;
}