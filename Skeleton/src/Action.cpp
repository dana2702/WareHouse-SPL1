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

}