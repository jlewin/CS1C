#include <iostream>
#include "MockState.h"

using namespace std;

void MockState::initAppState(PosSystem& posSystem) {
    loadMenu(posSystem);
    loadOrders(posSystem);
}

void MockState::loadMenu(PosSystem& posSystem) {
    posSystem.addMenuItem("Hamburger", 2.50, 5.99);
    posSystem.addMenuItem("Cheeseburger", 3.00, 6.99);
    posSystem.addMenuItem("Fries", 1.50, 1.99);
    posSystem.addMenuItem("Soda", 0.75, 1.49);
    posSystem.addMenuItem("Milkshake", 2.00, 7.99);
}

void MockState::loadOrders(PosSystem& posSystem) {
    // Order 0
    auto order = posSystem.addOrder("Joe Smith");
    posSystem.addOrderItem(order, "Hamburger", 2);
    posSystem.addOrderItem(order, "Cheeseburger", 1);
    posSystem.addOrderItem(order, "Milkshake", 1);

    // Order 1
    order = posSystem.addOrder("Emma Wilson");
    posSystem.addOrderItem(order, "Cheeseburger", 1);
    posSystem.addOrderItem(order, "Fries", 2);
    posSystem.addOrderItem(order, "Soda", 1);

    // Order 2
    order = posSystem.addOrder("Mike Chen");
    posSystem.addOrderItem(order, "Hamburger", 2);
    posSystem.addOrderItem(order, "Soda", 2);
    posSystem.addOrderItem(order, "Fries", 2);

    // Order 3
    order = posSystem.addOrder("Sarah Johnson");
    posSystem.addOrderItem(order, "Milkshake", 2);
    posSystem.addOrderItem(order, "Cheeseburger", 1);
    posSystem.addOrderItem(order, "Fries", 1);

    // Order 4
    order = posSystem.addOrder("David Brown");
    posSystem.addOrderItem(order, "Hamburger", 1);
    posSystem.addOrderItem(order, "Fries", 1);
    posSystem.addOrderItem(order, "Milkshake", 1);

    // Order 5
    order = posSystem.addOrder("Maria Garcia");
    posSystem.addOrderItem(order, "Cheeseburger", 2);
    posSystem.addOrderItem(order, "Soda", 2);
    posSystem.addOrderItem(order, "Fries", 2);

    // Order 6
    order = posSystem.addOrder("Tom Wilson");
    posSystem.addOrderItem(order, "Hamburger", 1);
    posSystem.addOrderItem(order, "Cheeseburger", 1);
    posSystem.addOrderItem(order, "Soda", 2);
}