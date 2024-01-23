#include "/home/naomi/SPL/SPL_1/hadassi/Skeleton/include/Volunteer.h"  
#include <iostream>


using namespace std;


        // Constructor
        Volunteer::Volunteer(int id, const std::string &name): id(id), name(name), completedOrderId(NO_ORDER), activeOrderId(NO_ORDER) {}

        // Copy constructor
        Volunteer::Volunteer(const Volunteer &other): id(other.id), name(other.name), completedOrderId(other.completedOrderId),activeOrderId(other.activeOrderId) {}

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

        bool Volunteer::hasOrdersLeft() const {
            return true;
        }

        bool Volunteer::canTakeOrder(const Order &order) const{
            if(!isBusy && hasOrdersLeft){
                return true;
            }

            return false;
        }

        void Volunteer::acceptOrder(const Order &order){
            this->activeOrderId = order.getId();
        }

        void Volunteer::step(){

        }

        string Volunteer::toString() const{
            //return "Volunteer";
        }

        Volunteer* Volunteer::clone() const{
            //return new Volunteer(*this);
        }

        Volunteer:: ~Volunteer() {
            
        }



  
    //constructor
    CollectorVolunteer::CollectorVolunteer(int id, const string &name, int coolDown)
        : Volunteer(id,name), coolDown(this->coolDown), timeLeft(NO_ORDER){}

    //copy constructor    
    CollectorVolunteer::CollectorVolunteer(const CollectorVolunteer &other):
         Volunteer(other),coolDown(other.coolDown), timeLeft(other.timeLeft){}
         
    CollectorVolunteer* CollectorVolunteer::clone() const{
        return new CollectorVolunteer(*this);
    }

    void CollectorVolunteer::step(){
        if (this->timeLeft== NO_ORDER){
            this->timeLeft= coolDown;
        }
        this->timeLeft--;
        if(this->timeLeft==0){
            // the collector finished his job - send back the order to pending (activeOrderId)
        }
        // ........
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
        if(!isBusy && hasOrdersLeft){
            return true;
        }

        return false;
    }


    void CollectorVolunteer::acceptOrder(const Order &order){
        this->activeOrderId = order.getId();
    }
    
    string CollectorVolunteer::toString() const{
        return "CollectorVolunteer";
    }
    CollectorVolunteer:: ~CollectorVolunteer(){

    }




        //constructor    
        LimitedCollectorVolunteer::LimitedCollectorVolunteer(int id, const string &name, int coolDown ,int maxOrders)
            : CollectorVolunteer(id, name, coolDown), maxOrders(this->maxOrders), ordersLeft(this->maxOrders){}

        //copy constructor    
        LimitedCollectorVolunteer::LimitedCollectorVolunteer(const LimitedCollectorVolunteer &other)
            : CollectorVolunteer(other), maxOrders(other.maxOrders), ordersLeft(other.ordersLeft){}

        LimitedCollectorVolunteer* LimitedCollectorVolunteer::clone() const{
            return new LimitedCollectorVolunteer(*this);
        }

        bool LimitedCollectorVolunteer::hasOrdersLeft() const{
            return(ordersLeft > 0);
        }

        bool LimitedCollectorVolunteer::canTakeOrder(const Order &order) const{
            if(!isBusy && hasOrdersLeft){
                return true;
            }

            return false;
        }

        void LimitedCollectorVolunteer::acceptOrder(const Order &order){
            this->ordersLeft--;
            this->activeOrderId = order.getId();
        }


        int LimitedCollectorVolunteer::getMaxOrders() const{
            return this->maxOrders;
        }

        int LimitedCollectorVolunteer::getNumOrdersLeft() const{
            return this->ordersLeft;
        }
         LimitedCollectorVolunteer:: ~LimitedCollectorVolunteer(){
        
    }





    //constructor
    DriverVolunteer::DriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep)
        : Volunteer(id,name), maxDistance(this->maxDistance), distancePerStep(this->distancePerStep), distanceLeft(NO_ORDER){}
    
    //copy constructor
    DriverVolunteer::DriverVolunteer(const DriverVolunteer &other)
        : Volunteer(other), maxDistance(other.maxDistance), distancePerStep(other.distancePerStep), distanceLeft(NO_ORDER){}
    
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
        // this.distanceLeft = this.getDistanceLeft() - this.getDistancePerStep();
        return (this->distanceLeft<=0);
    }

    bool  DriverVolunteer::hasOrdersLeft() const{
        return true;
    }

    bool  DriverVolunteer::canTakeOrder(const Order &order) const{
        if(!isBusy && hasOrdersLeft && order.getDistance() <= this->maxDistance){
            return true;
        }

        return false;
    }

    void  DriverVolunteer::acceptOrder(const Order &order){
        this->distanceLeft= order.getDistance();
    }

    void  DriverVolunteer::step(){
        // ....
    }

    string  DriverVolunteer::toString() const{
        return "DriverVolunteer";
    }
    DriverVolunteer:: ~DriverVolunteer(){

    }
    







    //constructor    
     LimitedDriverVolunteer::LimitedDriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep,int maxOrders)
         : DriverVolunteer(id,name,maxDistance,distancePerStep) , maxOrders(maxOrders), ordersLeft(maxOrders){}

     //copy constructor  
     LimitedDriverVolunteer::LimitedDriverVolunteer(const LimitedDriverVolunteer &other)
        : DriverVolunteer(other), maxOrders(other.maxOrders), ordersLeft(other.ordersLeft){}
    
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
        if(!isBusy() && hasOrdersLeft() && order.getDistance() <= this->getMaxDistance()){
            return true;
        }

        return false;
    }
    
        void LimitedDriverVolunteer::acceptOrder(const Order &order) {
            DriverVolunteer:: acceptOrder(order);
            //this->distanceLeft = order.getDistance();
            this->ordersLeft--;
        } 
        string LimitedDriverVolunteer::toString() const {
            return "LimitedDriverVolunteer";
        }
         LimitedDriverVolunteer:: ~LimitedDriverVolunteer(){
        
    }






