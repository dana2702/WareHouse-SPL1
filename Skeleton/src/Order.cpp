#include "/home/naomi/SPL/SPL_1/hadassi/Skeleton/include/Order.h"
#include <iostream>

using namespace std;

enum class OrderStatus {
    PENDING,
    COLLECTING,
    DELIVERING,
    COMPLETED,
};



class Order{


private:
    const int id;
    const int customerId;
    const int distance;
    OrderStatus status;
    int collectorId; 
    int driverId; 

public:

    //constructor
    Order(int id, int customerId, int distance)
        : id(id), customerId(customerId), distance(distance), status(OrderStatus::PENDING) ,collectorId(NO_VOLUNTEER), driverId(NO_VOLUNTEER){}

    int getId() {
        return this->id;
    }

    int getCustomerId(){
        return this->customerId;
    }

    void setStatus(OrderStatus status){
        this->status = status;
    }

    void setCollectorId(int collectorId){
        this->collectorId = collectorId;
    }

    void setDriverId(int driverId){
        this->driverId = driverId;
    }

    int getCollectorId() const{
        return this->collectorId;
    }

    int getDriverId() const{
        return this->driverId;
    }

    OrderStatus getStatus() const {
        return this->status;
    }

    const string toString() const{
        return "";
    }

    // extras:

    int getDistance() const{
        return this->distance;
    }
};