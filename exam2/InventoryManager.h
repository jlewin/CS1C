#ifndef InventoryManager_H
#define InventoryManager_H

#include <iostream>
#include "InventoryItem.h"
#include "LibraryShelf.h"

using namespace std;

class InventoryManager
{
    public:
        InventoryManager();
        void checkoutItem(InventoryItem*);
        void checkinItem(InventoryItem*);
        void printInventory() const;
        void printCheckedOutItems() const;
        void swapItems(InventoryItem*, InventoryItem*);
        int getShelfCount() const;

        LibraryShelf& operator[](int index) const;

        friend ostream& operator<<(ostream&, const InventoryManager&);

        int static getInstanceCount();
        void addItem(const int shelf, const int compartment, InventoryItem* item);

    private:
        vector<LibraryShelf*> libraryShelves;
        static int instanceCount;
        string title;
        string author;
        string copyrightDate;
};
#endif
