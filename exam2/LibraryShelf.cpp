#include <iostream>
#include "LibraryShelf.h"

using namespace std;

LibraryShelf::LibraryShelf() {
}

LibraryShelf::~LibraryShelf() {
    for (auto item : compartments) {
        delete item;
    }

    cout << "LibraryShelf destructor called: " << endl;
    cout << InventoryItem::getInstanceCount() << " InventoryItem instances remaining" << endl;
}

void LibraryShelf::addItem(InventoryItem* item, int index) {
    compartments[index] = item;
}

// Operator overloads

// Add subscript operator, returning nullptr for non-existing items
InventoryItem* LibraryShelf::operator[] (int index) const{
    return compartments[index];
 }

int LibraryShelf::getItemCount() const {
    return (int) compartments.size();
}

ostream& operator<<(ostream& outstream, const LibraryShelf& shelf) {
    outstream << Screen::heading("Shelf ------------------------------") << endl;

    //InventoryItem::setIndentText("    │ ");

    // Loop over entries
    for (int i = 0; i <  shelf.getItemCount(); i++) {
        // Reference the item on the given shelf, at the given compartment
        InventoryItem* item = shelf[i];

        if (item == nullptr) {
            outstream << " " << (i + 1) << ". " << "Empty Container" << endl;
        } else {
            outstream << " " << (i + 1) << ". " << "Occupied with (#" << item->getID() << ")" << endl;
            // Call the LibraryItem operator<< overload
            outstream << *item;
        }
    }

    outstream << endl;

    return outstream;
}

