#include <iostream>
#include "BookItem.h"

using namespace std;

int BookItem::instanceCount = 0;

BookItem::BookItem() {
    instanceCount++;
}

// BookItem::~BookItem() {
// }

ostream& operator<<(ostream& outstream, const BookItem *BookItem) {
    outstream << "Name: " << BookItem->title << endl;

    return outstream;
}

int BookItem::getInstanceCount() {
    return instanceCount;
}