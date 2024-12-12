#include <iostream>
#include <iomanip>
#include "MenuItem.h"
#include "constants.h"

using namespace std;

int MenuItem::instanceCount = 0;

MenuItem::MenuItem() {
    instanceCount++;
    cout << "Creating empty MenuItem (" << instanceCount << ")" << endl;
}

MenuItem::MenuItem(string name, double cost, double salePrice)
    : name(name), cost(cost), salePrice(salePrice)
 {
    instanceCount++;
    cout << "Creating MenuItem for " << name << " (" << instanceCount << ")" << endl;
 }

 MenuItem::~MenuItem() {
    cout << "   Destroying MenuItem for " << name << "(" << instanceCount << ")" << endl;
    instanceCount--;
 }

string MenuItem::getName() const {
    return name;
}

double MenuItem::getCost() const {
    return cost;
}

double MenuItem::getSalePrice() const {
    return salePrice;
}

double MenuItem::getItemProfit() const {
    return salePrice - cost;
}

void MenuItem::setName(string name) {
    this->name = name;
}

void MenuItem::setCost(double cost) {
    this->cost = cost;
}

void MenuItem::setSalePrice(double salePrice) {
    this->salePrice = salePrice;
}

void MenuItem::print(std::ostream& os) const {
    os << left
       << setprecision(2) << fixed
       << indentText << setw(titleWidth) << "Name" << getName() << endl
       << indentText << setw(titleWidth) << "Cost" << "$" << getCost() << endl
       << indentText << setw(titleWidth) << "Sale Price" << "$" << getSalePrice() << endl
       << indentText << setw(titleWidth) << "Profit" << "$" << getItemProfit() << endl;
}

ostream& operator<<(ostream& outstream, const MenuItem &item) {
    item.print(outstream);

    return outstream;
}

int MenuItem::getInstanceCount() {
    return instanceCount;
}
