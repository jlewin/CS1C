#include <iostream>
#include "CustomerOrder.h"

// Constructor
CustomerOrder::CustomerOrder(string customerName) {
    this->customerName = customerName;
}

// Insertion operator
ostream& operator<<(ostream& outstream, const CustomerOrder& order) {
    for (size_t i = 0; i < order.lineItems.size(); i++) {
        outstream << order.lineItems[i];
    }

    return outstream;
}
