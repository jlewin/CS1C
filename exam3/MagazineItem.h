#ifndef MagazineItem_H
#define MagazineItem_H

#include <iostream>
#include "InventoryItem.h"
#include "Screen.h"

using namespace std;

class MagazineItem : public InventoryItem
{
    public:
        MagazineItem();
        MagazineItem(const string& id, const string& desc, const string& title, const string& edition);
        void print(std::ostream& os) const override;
        int static getInstanceCount();

    private:
        static int instanceCount;
        string title; // Main article title
        string edition;
};

#endif
