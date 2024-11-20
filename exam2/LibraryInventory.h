#ifndef LibraryInventory_H
#define LibraryInventory_H

#include <iostream>
#include "InventoryItem.h"
#include "LibraryShelf.h"

using namespace std;

class LibraryInventory
{
    public:
        LibraryInventory();
        void addItem(InventoryItem*);
        void checkoutItem(InventoryItem*);
        void checkinItem(InventoryItem*);
        void printInventory() const;
        void printCheckedOutItems() const;
        void swapItems(InventoryItem*, InventoryItem*);

        int getShelfCount() const;

        LibraryShelf* operator[](int index) const;

        friend ostream& operator<<(ostream&, const LibraryInventory*);

        int static getInstanceCount();

    private:
        vector<LibraryShelf*> libraryShelves;
        static int instanceCount;
        string title;
        string author;
        string copyrightDate;
};

#endif
