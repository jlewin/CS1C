#ifndef LibraryShelf_H
#define LibraryShelf_H

#include <iostream>
#include <vector>
#include "InventoryItem.h"
#include "Screen.h"

using namespace std;

class LibraryShelf
{
    public:
        LibraryShelf();
        ~LibraryShelf();

        InventoryItem* operator[](int index) const;
        friend ostream& operator<<(ostream&, const LibraryShelf&);

        int getItemCount() const;
        string name;

        void addItem(InventoryItem*, int);

    private:
        // Intiialized to nullptr until assigned
        vector<InventoryItem*> compartments = vector<InventoryItem*>(15);

};;

#endif
