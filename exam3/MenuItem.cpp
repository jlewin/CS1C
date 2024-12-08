#include <iostream>
#include <iomanip>
#include "MenuItem.h"

using namespace std;

int MenuItem::instanceCount = 0;
string MenuItem::indentText = "    │ ";
int MenuItem::titleWidth = 16;

MenuItem::MenuItem(string name, double cost, double salePrice)
    : name(name), cost(cost), salePrice(salePrice)
 {
    instanceCount++;
 }

 MenuItem::~MenuItem() {
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
       << indent() << setw(titleWidth) << "Name" << getName() << endl
       << indent() << setw(titleWidth) << "Cost" << "$" << getCost() << endl
       << indent() << setw(titleWidth) << "Sale Price" << "$" << getSalePrice() << endl
       << indent() << setw(titleWidth) << "Profit" << "$" << getItemProfit() << endl;
}

void MenuItem::setIndentText(string text) {
    indentText = text;
}

string MenuItem::indent() const {
    return indentText;
}

ostream& operator<<(ostream& outstream, const MenuItem &item) {
    item.print(outstream);

    return outstream;
}

int MenuItem::getInstanceCount() {
    return instanceCount;
}
