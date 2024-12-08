#include <iostream>
#include "MockState.h"

using namespace std;

void MockState::initAppState(PosSystem& posSystem) {
    loadMenu(posSystem);
}

void MockState::loadMenu(PosSystem& posSystem) {
    posSystem.addMenuItem("Hamburger", 2.50, 5.99); 
    posSystem.addMenuItem("Cheeseburger", 3.00, 6.99); 
    posSystem.addMenuItem("Fries", 1.50, 1.99); 
    posSystem.addMenuItem("Soda", 0.75, 1.49); 
    posSystem.addMenuItem("Milkshake", 2.00, 7.99);
}
