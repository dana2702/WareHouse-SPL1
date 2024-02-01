#include "Volunteer.h"
#include <iostream>
using namespace std;
using std:: string;
using std:: vector;
#include<sstream>


    // Constructor
    Volunteer::Volunteer(int id, const std::string &name): activeOrderId(NO_ORDER) , completedOrderId(NO_ORDER) , id(id) , name(name){}

        int Volunteer::getId() const{
            return this->id;
        }

        const string& Volunteer::getName() const{
            return this->name;
        }

        int Volunteer::getActiveOrderId() const{
            return this->activeOrderId;
        }

        int Volunteer::getCompletedOrderId() const{
            return this->completedOrderId;
        }

        bool Volunteer::isBusy() const{
            return (activeOrderId != NO_ORDER);
        }

        Volunteer:: ~Volunteer() {            
        }
  
    //constructor
    CollectorVolunteer::CollectorVolunteer(int id, const string &name, int coolDown)
        : Volunteer(id,name), coolDown(coolDown), timeLeft(NO_ORDER){}

    CollectorVolunteer* CollectorVolunteer::clone() const{
        return new CollectorVolunteer(*this);
    }

    void CollectorVolunteer::step(){
        if(decreaseCoolDown()){
            // send the order to driver (pending)
            this->completedOrderId=this->activeOrderId;
        }
    }

    int CollectorVolunteer::getCoolDown() const{
        return this->coolDown;
    }

    int CollectorVolunteer::getTimeLeft() const{
        return this->timeLeft;
    }
    
    bool CollectorVolunteer::decreaseCoolDown(){
        this->timeLeft--;
        if(this->timeLeft==0){
            return true;
        }
        return false;
    }
     
    bool CollectorVolunteer::hasOrdersLeft() const{
        return true;
    }

    bool CollectorVolunteer::canTakeOrder(const Order &order) const{
        if((!isBusy()) && hasOrdersLeft() && order.getStatus() == OrderStatus::PENDING){
            return true;
        }

        return false;
    }

    void CollectorVolunteer::acceptOrder(const Order &order){
        this->activeOrderId = order.getId();
        this->timeLeft = coolDown;
        this->completedOrderId = NO_ORDER;
    }
    
    string CollectorVolunteer::toString() const{
        return "CollectorVolunteer";
    }     
     
   


    CollectorVolunteer:: ~CollectorVolunteer(){
    }

    void CollectorVolunteer::setTimeLeft(int newTimeLeft){
        this->timeLeft = newTimeLeft;
    }



//constructor    
    LimitedCollectorVolunteer::LimitedCollectorVolunteer(int id, const string &name, int coolDown ,int maxOrders)
    : CollectorVolunteer(id, name, coolDown), maxOrders(maxOrders), ordersLeft(maxOrders){}

        LimitedCollectorVolunteer* LimitedCollectorVolunteer::clone() const{
            return new LimitedCollectorVolunteer(*this);
        }

        bool LimitedCollectorVolunteer::hasOrdersLeft() const{
            return(ordersLeft > 0);
        }

        bool LimitedCollectorVolunteer::canTakeOrder(const Order &order) const{
            if((!isBusy()) && hasOrdersLeft() && order.getStatus() == OrderStatus::PENDING){
                return true;
            }

            return false;
        }

        void LimitedCollectorVolunteer::acceptOrder(const Order &order){
            this->ordersLeft--;
            this->activeOrderId = order.getId();
            this->completedOrderId = NO_ORDER;
            setTimeLeft(getCoolDown());
        }


        int LimitedCollectorVolunteer::getMaxOrders() const{
            return this->maxOrders;
        }

        int LimitedCollectorVolunteer::getNumOrdersLeft() const{
            return this->ordersLeft;
        }

        string LimitedCollectorVolunteer::toString() const{
            return "LimitedCollectorVolunteer";
        }

        LimitedCollectorVolunteer:: ~LimitedCollectorVolunteer(){
        
    }





//constructor
    DriverVolunteer::DriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep)
    : Volunteer(id,name), maxDistance(maxDistance), distancePerStep(distancePerStep), distanceLeft(NO_ORDER){}
    
      DriverVolunteer* DriverVolunteer::clone() const{
        return new DriverVolunteer(*this);
    }

    int  DriverVolunteer::getDistanceLeft() const{
        return this->distanceLeft;
    }

    int  DriverVolunteer::getMaxDistance() const{
        return this->maxDistance;
    }

    int  DriverVolunteer::getDistancePerStep() const{
        return this->distancePerStep;
    }

    

    bool  DriverVolunteer::decreaseDistanceLeft(){
        this->distanceLeft =  this->distanceLeft - this->distancePerStep;
        return (this->distanceLeft<=0);
    }

    bool  DriverVolunteer::hasOrdersLeft() const{
        return true;
    }

    bool  DriverVolunteer::canTakeOrder(const Order &order) const{
        if((!isBusy()) && hasOrdersLeft() && order.getDistance() <= this->maxDistance && order.getStatus() == OrderStatus::COLLECTING){
            return true;
        }

        return false;
    }

    void  DriverVolunteer::acceptOrder(const Order &order){
        this->activeOrderId = order.getId();
        this->distanceLeft= order.getDistance();
        this->completedOrderId = NO_ORDER;
    }

    void  DriverVolunteer::step(){
        if(decreaseDistanceLeft()){
            this->completedOrderId= this->activeOrderId;
        }
    }

    string  DriverVolunteer::toString() const{
        return "DriverVolunteer";
    }
    DriverVolunteer:: ~DriverVolunteer(){

    }
    void DriverVolunteer::setDistanceLeft(int newDistanceLeft){
        this->distanceLeft = newDistanceLeft;
    }


//constructor    
    LimitedDriverVolunteer::LimitedDriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep,int maxOrders)
    : DriverVolunteer(id,name,maxDistance,distancePerStep) , maxOrders(maxOrders), ordersLeft(maxOrders){}

    LimitedDriverVolunteer* LimitedDriverVolunteer::clone() const {
        return new LimitedDriverVolunteer(*this);
    }
    
    int LimitedDriverVolunteer::getMaxOrders() const{
        return this->maxOrders;
    }
    
    
    int LimitedDriverVolunteer::getNumOrdersLeft() const{
        return this->ordersLeft;
    }
    
    bool LimitedDriverVolunteer::hasOrdersLeft() const{
        return (this->ordersLeft > 0);
    }
    
    bool LimitedDriverVolunteer::canTakeOrder(const Order &order) const {
        if((!isBusy()) && hasOrdersLeft() && order.getDistance() <= this->getMaxDistance() && order.getStatus() == OrderStatus::COLLECTING){
            return true;
        }

        return false;
    }
    
    void LimitedDriverVolunteer::acceptOrder(const Order &order) {
        this->ordersLeft--;
        this->activeOrderId= order.getId();
        this->completedOrderId = NO_ORDER;
        setDistanceLeft(order.getDistance());
    } 
    string LimitedDriverVolunteer::toString() const {
        return "LimitedDriverVolunteer";
    }
    
    LimitedDriverVolunteer:: ~LimitedDriverVolunteer(){
        
    }






