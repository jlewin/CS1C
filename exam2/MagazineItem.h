#ifndef MagazineItem_H
#define MagazineItem_H

#include <iostream>
#include "InventoryItem.h"

using namespace std;

class MagazineItem : public InventoryItem
{
    public:
        MagazineItem();
        friend ostream& operator<<(ostream&, const MagazineItem*);
        int static getInstanceCount();

    private:
        static int instanceCount;
        string editor;
        string title; // Main article title
};

#endif
