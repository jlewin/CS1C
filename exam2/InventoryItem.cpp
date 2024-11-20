#include <iostream>
#include "InventoryItem.h"

using namespace std;

int InventoryItem::instanceCount = 0;

InventoryItem::InventoryItem() {
    instanceCount++;
}

InventoryItem::InventoryItem(const string& name, const string& desc, const string& id) {
    this->name = name;
    this->description = desc;
    this->id = id;
    instanceCount++;
}

// InventoryItem::~InventoryItem() {
// }

ostream& operator<<(ostream& outstream, const InventoryItem *InventoryItem) {
    outstream << "Name: " << InventoryItem->name << endl;

    return outstream;
}

int InventoryItem::getInstanceCount() {
    return instanceCount;
}