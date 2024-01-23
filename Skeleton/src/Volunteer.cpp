#include "/home/naomi/SPL/SPL_1/hadassi/Skeleton/include/Volunteer.h"  
#include <iostream>
#pragma once

using namespace std;
class Volunteer {

    private:
        const int id;
        const string name;

    protected:
        int completedOrderId;
        int activeOrderId;

    public:
        // Constructor
        Volunteer(int id, const string name)
            : id(id), name(name), completedOrderId(NO_ORDER), activeOrderId(NO_ORDER) {}

        // Copy constructor
        Volunteer(const Volunteer &other)
            : id(other.id), name(other.name), completedOrderId(other.completedOrderId),
            activeOrderId(other.activeOrderId) {}

        int getId() const{
            return this->id;
        }

        const string &getName() const{
            return this->name;
        }

        int getActiveOrderId() const{
            return this->activeOrderId;
        }

        int getCompletedOrderId() const{
            return this->completedOrderId;
        }

        bool isBusy() const{
            return (activeOrderId != NO_ORDER);
        }

        virtual bool hasOrdersLeft() const {
            return true;
        }

        virtual bool canTakeOrder(const Order &order) const{
            if(!isBusy && hasOrdersLeft){
                return true;
            }

            return false;
        }

        virtual void acceptOrder(const Order &order){
            this->activeOrderId = order.getId();
        }

        virtual void step(){

        }

        virtual string toString(){
            return "Volunteer";
        }

        virtual Volunteer* clone() const{
            return new Volunteer(*this);
        }
};



class CollectorVolunteer: public Volunteer {

    private:
        const int coolDown;
        int timeLeft;

    public:    
    //constructor
    CollectorVolunteer(int id, const string &name, int coolDown)
        : Volunteer(id,name), coolDown(this->coolDown), timeLeft(NO_ORDER){}

    //copy constructor    
    CollectorVolunteer(const CollectorVolunteer &other):
         Volunteer(other),coolDown(other.coolDown), timeLeft(other.timeLeft){}
         
    CollectorVolunteer *clone() const{
        return new CollectorVolunteer(*this);
    }

    void step(){
        if (this->timeLeft== NO_ORDER){
            this->timeLeft= coolDown;
        }
        this->timeLeft--;
        if(this->timeLeft==0){
            // the collector finished his job - send back the order to pending (activeOrderId)
        }
        // ........
    }

    int getCoolDown() const{
        return this->coolDown;
    }

    int getTimeLeft() const{
        return this->timeLeft;
    }

    bool decreaseCoolDown(){
        this->timeLeft--;
        if(this->timeLeft==0){
            return true;
        }
        return false;
    }

    bool hasOrdersLeft() const{
        return true;
    }

    bool canTakeOrder(const Order &order) const{
        if(!isBusy && hasOrdersLeft){
            return true;
        }

        return false;
    }


    void acceptOrder(const Order &order){
        this->activeOrderId = order.getId();
    }
    
    string toString() const{
        return "CollectorVolunteer";
    }
};



class LimitedCollectorVolunteer: public CollectorVolunteer {

    private:
        const int maxOrders;
        int ordersLeft;


    public: 
        //constructor    
        LimitedCollectorVolunteer(int id, const string &name, int coolDown ,int maxOrders)
            : CollectorVolunteer(id, name, coolDown), maxOrders(this->maxOrders), ordersLeft(this->maxOrders){}

        //copy constructor    
        LimitedCollectorVolunteer(const LimitedCollectorVolunteer &other)
            : CollectorVolunteer(other), maxOrders(other.maxOrders), ordersLeft(other.ordersLeft){}

        LimitedCollectorVolunteer *clone() const{
            return new LimitedCollectorVolunteer(*this);
        }

        bool hasOrdersLeft(){
            return(ordersLeft > 0);
        }

        bool canTakeOrder(const Order &order) const{
            if(!isBusy && hasOrdersLeft){
                return true;
            }

            return false;
        }

        void acceptOrder(const Order &order){
            this->ordersLeft--;
            this->activeOrderId = order.getId();
        }


        int getMaxOrders() const{
            return this->maxOrders;
        }

        int getNumOrdersLeft() const{
            return this->ordersLeft;
        }
};




class DriverVolunteer: public Volunteer {

    private:
        const int maxDistance;
        const int distancePerStep;
        int distanceLeft;

    public:    

    //constructor
    DriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep)
        : Volunteer(id,name), maxDistance(this->maxDistance), distancePerStep(this->distancePerStep), distanceLeft(NO_ORDER){}
    
    //copy constructor
    DriverVolunteer(const DriverVolunteer &other)
        : Volunteer(other), maxDistance(other.maxDistance), distancePerStep(other.distancePerStep), distanceLeft(NO_ORDER){}
    
    int getDistanceLeft() const{
        return this->distanceLeft;
    }

    int getMaxDistance() const{
        return this->maxDistance;
    }

    int getDistancePerStep() const{
        return this->distancePerStep;
    }

    bool decreaseDistanceLeft(){
        this->distanceLeft =  this->distanceLeft - this->distancePerStep;
        // this.distanceLeft = this.getDistanceLeft() - this.getDistancePerStep();
        return (this->distanceLeft<=0);
    }

    bool hasOrdersLeft() const{
        return true;
    }

    bool canTakeOrder(const Order &order) const{
        if(!isBusy && hasOrdersLeft && order.getDistance() <= this->maxDistance){
            return true;
        }

        return false;
    }

    void acceptOrder(const Order &order){
        this->distanceLeft= order.getDistance();
    }

    void step(){
        // ....
    }

    string toString() const{
        return "DriverVolunteer";
    }
};





class LimitedDriverVolunteer: public DriverVolunteer {


    private:
        const int maxOrders;
        int ordersLeft;

    public:

    //constructor    
     LimitedDriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep,int maxOrders)
         : DriverVolunteer(id,name,maxDistance,distancePerStep) , maxOrders(maxOrders), ordersLeft(maxOrders){}

     //copy constructor  
     LimitedDriverVolunteer(const LimitedDriverVolunteer &other)
        : DriverVolunteer(other), maxOrders(other.maxOrders), ordersLeft(other.ordersLeft){}
    
    LimitedDriverVolunteer *clone() const {
        return new LimitedDriverVolunteer(*this);
    }
    
    int getMaxOrders() const{
        return this->maxOrders;
    }
    
    
    int getNumOrdersLeft() const{
        return this->ordersLeft;
    }
    
    bool hasOrdersLeft() const{
        return (this->ordersLeft > 0);
    }
    
    bool canTakeOrder(const Order &order) const {
        if(!isBusy() && hasOrdersLeft() && order.getDistance() <= this->getMaxDistance()){
            return true;
        }

        return false;
    }
    
        void acceptOrder(const Order &order) {
            DriverVolunteer:: acceptOrder(order);
            //this->distanceLeft = order.getDistance();
            this->ordersLeft--;
        } 
        string toString() const {
            return "LimitedDriverVolunteer";
        }

};




