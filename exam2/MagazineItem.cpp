#include <iostream>
#include "MagazineItem.h"

using namespace std;

int MagazineItem::instanceCount = 0;

MagazineItem::MagazineItem() {
    instanceCount++;
}

ostream& operator<<(ostream& outstream, const MagazineItem *MagazineItem) {
    outstream << "Name: " << MagazineItem->name << endl;

    return outstream;
}

int MagazineItem::getInstanceCount() {
    return instanceCount;
}