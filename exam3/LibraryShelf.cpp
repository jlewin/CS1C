#include <iostream>
#include "LibraryShelf.h"

using namespace std;

int LibraryShelf::instanceCount = 0;

LibraryShelf::LibraryShelf(const string& name) {
    instanceCount++;
    compartments = vector<InventoryItem*>(MAX_COMPARTMENTS);
    this->name = name;
}

LibraryShelf::~LibraryShelf() {
    for (auto item : compartments) {
        delete item;
    }

    instanceCount--;

    cout << "LibraryShelf destructor called: " << endl;
    cout << InventoryItem::getInstanceCount() << " InventoryItem instances remaining" << endl;
}

void LibraryShelf::addItem(InventoryItem* item, int index) {
    compartments[index] = item;
}

// Operator overloads

// Indexer operators
InventoryItem* LibraryShelf::operator[] (int index) const{
    return compartments[index];
}

InventoryItem*& LibraryShelf::operator[] (int index) {
    return compartments[index];
}

// Insertion operator
ostream& operator<<(ostream& outstream, const LibraryShelf& shelf) {
    outstream << headingText(shelf.name) << endl;
    outstream << separator() << endl;

    auto& options = FormattingOptions::getInstance();

    // Loop over entries
    for (int i = 0; i <  shelf.getCompartmentCount(); i++) {
        // Reference the item on the given shelf, at the given compartment
        InventoryItem* item = shelf[i];

        if (item == nullptr) {
            if (options.showEmptyCompartments) {
                outstream << " C" << (i + 1) << ". " << "Empty Compartment" << endl;
            }
        } else {
            if ((options.showCheckedOutOnly && item->getCheckedOut()) ||
                (options.showCheckedInOnly && !item->getCheckedOut()) ||
                options.showAllItems){
                outstream << " C" << (i + 1) << ". " << "Occupied with #" << item->getID() << endl;
                outstream << *item; // Call the LibraryItem operator<< overload
            }

        }
    }

    outstream << endl;

    return outstream;
}

// Other members
int LibraryShelf::getCompartmentCount() const {
    return (int) compartments.size();
}

int LibraryShelf::getInstanceCount() {
    return instanceCount;
}
