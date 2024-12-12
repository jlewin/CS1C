#include <iostream>
#include <iomanip>

#include "LineItem.h"
#include "LineItem.h"
#include "constants.h"

using namespace std;

int LineItem::instanceCount = 0;

LineItem::LineItem(const MenuItem& menuItem, int quantity) 
    : menuItem(menuItem), quantity(quantity) {
    #ifdef LOG_VERBOSE
        cout << "Creating LineItem for " << menuItem.getName() << " (" << instanceCount++ << ")" << endl;
    #endif
}

LineItem::~LineItem() {
    #ifdef LOG_VERBOSE
        cout << "  Destroying LineItem for " << menuItem.getName() << "(" << --instanceCount << ")" << endl;
    #endif
}

// Insertion operator
ostream& operator<<(ostream& outstream, const LineItem* lineItem) {
    lineItem->print(outstream);
    return outstream;
}

string LineItem::getName() const {
    return menuItem.getName();
}

double LineItem::getCost() const {
    return menuItem.getCost() * quantity;
}

double LineItem::getPrice() const {
    return menuItem.getSalePrice() * quantity;
}

double LineItem::getProfit() const {
    return (getPrice() - getCost());
}

void LineItem::print(std::ostream& os) const {
    os << left
       << indentText << setw(titleWidth)
       << menuItem.getName() << "("  << quantity << ")" << endl; 
}

int LineItem::getInstanceCount() {
    return instanceCount;
}

