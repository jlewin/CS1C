#ifndef BookItem_H
#define BookItem_H

#include <iostream>
#include "InventoryItem.h"

using namespace std;

class BookItem : public InventoryItem
{
    public:
        BookItem();
        friend ostream& operator<<(ostream&, const BookItem*);
        int static getInstanceCount();

    private:
        static int instanceCount;
        string title;
        string author;
        string copyrightDate;
};

#endif
