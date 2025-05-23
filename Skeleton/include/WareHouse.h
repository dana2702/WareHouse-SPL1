#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Order.h"
#include "Customer.h"

class BaseAction;
class Volunteer;

// Warehouse responsible for Volunteers, Customers Actions, and Orders.


class WareHouse {

    public:
        WareHouse(const string &configFilePath);
        void start();
        void addOrder(Order* order);
        void addAction(BaseAction* action);
        Customer &getCustomer(int customerId) const;
        Volunteer &getVolunteer(int volunteerId) const;
        Order &getOrder(int orderId) const;
        const vector<BaseAction*> &getActions() const;
        void close();
        void open();
        void parseText(const string &configFilePath);

        //extras
        vector<Customer*> getCustomerVector() const;
        vector<Volunteer*> getvolunteersVector() const;
        vector<BaseAction*> getActionsLog() const;
        vector<Order*> getPendingOrderVector() const;
        vector<Order*> getinProcessOrdersVector() const;
        vector<Order*> getCompletedOrdersVector() const;
        int getOrderCounter() const;
        int getVolunteerCounter() const;
        int getCustomerCounter() const;
        void fromPendingToinProcess(int orderID);
        void frominProcessToPending(int orderID);
        void frominProcessToCompleted(int orderID);
        void deleteVolunteer(Volunteer* volunteer);
        void addCustomer(Customer* customer);
        ~WareHouse(); //destructor

        //extars
        WareHouse(const WareHouse &other); //copy constructor
        WareHouse& operator=(WareHouse &&other) noexcept; //move assignment operator
        

    private:
        bool isOpen;
        vector<BaseAction*> actionsLog;
        vector<Volunteer*> volunteers;
        vector<Order*> pendingOrders;
        vector<Order*> inProcessOrders;
        vector<Order*> completedOrders;
        vector<Customer*> customers;
        int customerCounter; //For assigning unique customer IDs
        int volunteerCounter; //For assigning unique volunteer IDs

        // extra
        int orderCounter;
};