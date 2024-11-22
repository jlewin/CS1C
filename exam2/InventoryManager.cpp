#include <iostream>
#include "InventoryManager.h"

using namespace std;

int InventoryManager::instanceCount = 0;

InventoryManager::InventoryManager() {
    instanceCount++;

    for (int i = 0; i < 3; i++) {
        char id = 'A' + i;
        libraryShelves.push_back(new LibraryShelf("Shelf " + string(1, id)));
    }
}

LibraryShelf& InventoryManager::operator[](int index) const {
    if (index < 0 || index >= getShelfCount()) {
        throw std::out_of_range("Index out of range");
    }

    return *libraryShelves[index];
}

void InventoryManager::addItem(int shelf, int compartment, InventoryItem* item) {
    libraryShelves[shelf]->addItem(item, compartment);
}

int InventoryManager::getShelfCount() const {
    return (int) libraryShelves.size();
}

ostream& operator<<(ostream& outstream, const InventoryManager& libraryInventory) {
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