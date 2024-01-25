#include "Action.h"
#include <iostream>

using namespace std;

BaseAction::BaseAction(){}

ActionStatus BaseAction::getStatus() const{
    this->status;
}

void BaseAction::complete(){
     status=ActionStatus::COMPLETED;
}

void BaseAction::error(string errorMsg){
    this->errorMsg = errorMsg;
}

string BaseAction::getErrorMsg() const{
        return this->errorMsg;
}

AddOrder::AddOrder(int id): customerId(id){}

void AddOrder::act(WareHouse &wareHouse){

    // WHEN WE FINISH SUCCESSFULLY
    complete();

     // push to wareHouse vector
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
:customerName(customerName),customerType(typeToString(customerType)),distance(distance),maxOrders(maxOrders){

}

CustomerType AddCustomer:: typeToString(string customerType){
        if(customerType=="solider"){
        return CustomerType::Soldier;
    }
    else{
        return CustomerType::Civilian;
    }
}

void AddCustomer::act(WareHouse &wareHouse){

    // WHEN WE FINISH SUCCESSFULLY
    complete();

     // push to wareHouse vector
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
    // std::cout << "OrderId: " << orderId << std::endl;
    // for (Order* or :  wareHouse->pendingOrders) {
    // if(or->getId() == orderId){
    // std::cout << "OrderStatus: pending"  << std::endl;
    // }
}


PrintOrderStatus* PrintOrderStatus::clone() const{
        return new PrintOrderStatus(*this);
}

string PrintOrderStatus::toString() const{
    return "PrintOrderStatus";
}

PrintCustomerStatus::PrintCustomerStatus(int customerId):customerId(customerId){}

void PrintCustomerStatus::act(WareHouse &wareHouse) {

}

PrintCustomerStatus* PrintCustomerStatus::clone() const {
            return new PrintCustomerStatus(*this);

}

 string PrintCustomerStatus::toString() const{
    return "PrintCustomerStatus";
 }
 PrintVolunteerStatus::PrintVolunteerStatus(int id): volunteerId(id){}

 void PrintVolunteerStatus:: act(WareHouse &wareHouse){

 }
 PrintVolunteerStatus* PrintVolunteerStatus::clone() const {
            return new PrintVolunteerStatus(*this);

}

 string PrintVolunteerStatus::toString() const{
    return "PrintVolunteerStatus";
 }

  PrintActionsLog::PrintActionsLog(){}

 void PrintActionsLog:: act(WareHouse &wareHouse){

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
 



