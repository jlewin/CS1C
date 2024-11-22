#ifndef LibraryShelf_H
#define LibraryShelf_H

#include <iostream>
#include <vector>
#include "InventoryItem.h"
#include "Screen.h"
#include "constants.h"

using namespace std;

class LibraryShelf
{
    public:
        LibraryShelf(const string&);
        ~LibraryShelf();

        InventoryItem* operator[](int index) const;
        friend ostream& operator<<(ostream&, const LibraryShelf&);

        int getCompartmentCount() const;

        void addItem(InventoryItem*, int);

        static int getInstanceCount();

    private:
        static int instanceCount;
        string name;
        // Intiialized to nullptr until assigned
        vector<InventoryItem*> compartments = vector<InventoryItem*>(MAX_COMPARTMENTS);
};

#endif
