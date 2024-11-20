#ifndef LibraryShelf_H
#define LibraryShelf_H

#include <iostream>
#include "InventoryItem.h"
#include <vector>

using namespace std;

class LibraryShelf
{
    public:
        LibraryShelf();
        ~LibraryShelf();

        InventoryItem* operator[](int index) const;
        friend ostream& operator<<(ostream&, const LibraryShelf*);

        int getItemCount() const;

        void addItem(InventoryItem*, int);

    private:
        vector<InventoryItem*> items = vector<InventoryItem*>(15);

};;

#endif
