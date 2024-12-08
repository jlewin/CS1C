#include <iostream>
#include "PosSystem.h"

using namespace std;

// Constructor
PosSystem::PosSystem() {
}

// Insertion operator
ostream& operator<<(ostream& outstream, const PosSystem& posSystem) {
    for (size_t i = 0; i < posSystem.orders.size(); i++) {
        outstream << posSystem.orders[i];
    }

    return outstream;
}

CustomerOrder& PosSystem::createOrder(const string& customerName) {
    CustomerOrder* order = new CustomerOrder(customerName);
    orders.push_back(order);
    return *order;
}

void PosSystem::listOrders() const {
    cout << *this;
}

void PosSystem::listMenuItems() const {
    for (size_t i = 0; i < menu.size(); i++) {
        cout << menu[i];
        cout << "---------------------" << endl;
    }
}

void PosSystem::addMenuItem(const string& name, double cost, double salePrice) {
    menu.push_back(MenuItem(name, cost, salePrice));
}