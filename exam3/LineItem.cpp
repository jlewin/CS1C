#include <iostream>
#include <iomanip>

#include "MenuItem.h"
#include "LineItem.h"

using namespace std;

LineItem::LineItem(const MenuItem& menuItem, int quantity) 
    : menuItem(menuItem), quantity(quantity) {
}

