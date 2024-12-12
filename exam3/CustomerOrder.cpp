#include <iostream>
#include "CustomerOrder.h"

int CustomerOrder::instanceCount = 0;

// Constructor
CustomerOrder::CustomerOrder(string customerName) {
    #ifdef LOG_VERBOSE
        cout << "Creating order for " << customerName << " (" << instanceCount++ << ")" << endl;
    #endif

    this->customerName = customerName;
}

// Destructor
CustomerOrder::~CustomerOrder() {
    #ifdef LOG_VERBOSE
        cout << "Destroying order for " << customerName << " (" << --instanceCount << ")" << endl;
    #endif


    for (size_t i = 0; i < lineItems.size(); i++) {
        delete lineItems[i];
    }
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

double CustomerOrder::getTotalCost() const {
    double totalCost = 0.0;
    for (size_t i = 0; i < lineItems.size(); i++) {
        totalCost += lineItems[i]->getCost();
    }
    return totalCost;
}

double CustomerOrder::getTotalRevenue() const {
    double totalRevenue = 0.0;
    for (size_t i = 0; i < lineItems.size(); i++) {
        totalRevenue += lineItems[i]->getPrice();
    }
    return totalRevenue;
}

double CustomerOrder::getTotalProfit() const {
    double totalProfit = 0.0;
    for (size_t i = 0; i < lineItems.size(); i++) {
        totalProfit += lineItems[i]->getProfit();
    }
    return totalProfit;
}
