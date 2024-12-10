#include <iostream>
#include "CustomerOrder.h"

// Constructor
CustomerOrder::CustomerOrder(string customerName) {
    this->customerName = customerName;
}

// Insertion operator
ostream& operator<<(ostream& outstream, const CustomerOrder* order) {
    cout << "Order for " << order->customerName << "--------------" << endl;
    for (size_t i = 0; i < order->lineItems.size(); i++) {
        outstream << order->lineItems[i];
    }

    outstream << endl;

    return outstream;
}

void CustomerOrder::addItem(const MenuItem* menuItem, int quantity) {
    LineItem* lineItem = new LineItem(*menuItem, quantity);
    lineItems.push_back(lineItem);
}