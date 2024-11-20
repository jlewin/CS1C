#include <iostream>
#include "LibraryShelf.h"

using namespace std;

LibraryShelf::LibraryShelf() {
}

LibraryShelf::~LibraryShelf() {
}

void LibraryShelf::addItem(InventoryItem* item, int index) {
    items[index] = item;
}

// Operator overloads

// Add subscript operator, returning nullptr for non-existing items
InventoryItem* LibraryShelf::operator[] (int index) const{
    return items[index];
 }

int LibraryShelf::getItemCount() const {
    return items.size();
}

ostream& operator<<(ostream& outstream, const LibraryShelf* libraryShelf) {
    outstream << "Shelf ------------------------------" << endl;

    LibraryShelf shelf = *libraryShelf;

    // Loop over entries
    for (int i = 0; i <  shelf.getItemCount(); i++) {
        // Call the LibraryItem operator<< overload

        if (shelf[i] == nullptr) {
            outstream << " " << (i + 1) << ". " << "Empty Container" << endl;
        } else {
            outstream << " " << (i + 1) << ". " << shelf[i];
        }
    }

    outstream << endl;

    return outstream;
}

