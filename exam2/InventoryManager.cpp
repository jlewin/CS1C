#include <iostream>
#include "InventoryManager.h"

using namespace std;

int InventoryManager::instanceCount = 0;

InventoryManager::InventoryManager() {
    instanceCount++;

    for (int i = 0; i < 3; i++) {
        auto shelf = new LibraryShelf();
        shelf->name = "Shelf " + to_string(i + 1);
        libraryShelves.push_back(shelf);
    }
}

LibraryShelf& InventoryManager::operator[](int index) const {
    if (index < 0 || index >= getShelfCount()) {
        throw std::out_of_range("Index out of range");
    }

    return *libraryShelves[index];
}

int InventoryManager::getShelfCount() const {
    return (int) libraryShelves.size();
}

ostream& operator<<(ostream& outstream, const InventoryManager& libraryInventory) {
    outstream << "-- Library Inventory --" << endl;
    for (int i = 0; i < libraryInventory.getShelfCount(); i++) {
        // Added for clarity on what's passed to cout below
        LibraryShelf& shelf = libraryInventory[i];
        outstream << shelf;
    }

    return outstream;
}

int InventoryManager::getInstanceCount() {
    return instanceCount;
}