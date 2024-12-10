#include <iostream>
#include <iomanip>

#include "LineItem.h"
#include "LineItem.h"

using namespace std;

int LineItem::instanceCount = 0;
string LineItem::indentText = "    │ ";
int LineItem::titleWidth = 16;

LineItem::LineItem(const MenuItem& menuItem, int quantity) 
    : menuItem(menuItem), quantity(quantity) {
        instanceCount++;
}

// Insertion operator
ostream& operator<<(ostream& outstream, const LineItem* lineItem) {
    lineItem->print(outstream);
    return outstream;
}


void LineItem::print(std::ostream& os) const {
    os << left
       << indent() << setw(titleWidth)
       << menuItem.getName() << "("  << quantity << ")" << endl; 
}

string LineItem::indent() const {
    return indentText;
}

int LineItem::getInstanceCount() {
    return instanceCount;
}

