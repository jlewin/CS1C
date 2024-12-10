#include <iostream>
#include "PosSystem.h"

using namespace std;

// Constructor
PosSystem::PosSystem() {
}


CustomerOrder* PosSystem::addOrder(const string& customerName) {
    CustomerOrder* order = new CustomerOrder(customerName);
    orders.push_back(order);
    return order;
}

void PosSystem::addOrderItem(CustomerOrder* order, const string& name, int quantity) {
    const MenuItem* menuItem = getMenuItem(name);
    if (menuItem != nullptr) {
        order->addItem(menuItem, quantity);
    }
}

const MenuItem* PosSystem::getMenuItem(const std::string& name) const {
    for (size_t i = 0; i < menu.size(); i++) {
        if (menu[i].getName() == name) {
            return &menu[i];
        }
    }

    // Handle non-matching case
    return nullptr;
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
    for (size_t i = 0; i < orders.size(); i++) {
        cout << orders[i];
        cout << "---------------------" << endl;
    }
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