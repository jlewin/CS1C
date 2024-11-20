#include <iostream>
#include "MovieItem.h"

using namespace std;

int MovieItem::instanceCount = 0;

MovieItem::MovieItem() {
    instanceCount++;
}

ostream& operator<<(ostream& outstream, const MovieItem *MovieItem) {
    outstream << "Name: " << MovieItem->name << endl;

    return outstream;
}

int MovieItem::getInstanceCount() {
    return instanceCount;
}