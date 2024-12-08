#include <iostream>
#include "InventoryManager.h"

using namespace std;

int InventoryManager::instanceCount = 0;

// Constructor
InventoryManager::InventoryManager() {
    instanceCount++;

    for (int i = 0; i < 3; i++) {
        char id = 'A' + i;
        libraryShelves.push_back(new LibraryShelf("Shelf " + string(1, id)));
    }
}

// Indexer operators
LibraryShelf& InventoryManager::operator[](int index) const {
    if (index < 0 || index >= getShelfCount()) {
        throw std::out_of_range("Index out of range");
    }

    return *libraryShelves[index];
}

LibraryShelf& InventoryManager::operator[](int index) {
    if (index < 0 || index >= getShelfCount()) {
        throw std::out_of_range("Index out of range");
    }

    return *libraryShelves[index];
}

// Insertion operator
ostream& operator<<(ostream& outstream, const InventoryManager& libraryInventory) {
    for (int i = 0; i < libraryInventory.getShelfCount(); i++) {
        // Added for clarity on what's passed to cout below
        LibraryShelf& shelf = libraryInventory[i];
        outstream << shelf;
    }

    return outstream;
}

// Other Members
void InventoryManager::addItem(int shelf, int compartment, InventoryItem* item) {
    libraryShelves[shelf]->addItem(item, compartment);
}

int InventoryManager::getShelfCount() const {
    return (int) libraryShelves.size();
}

int InventoryManager::getInstanceCount() {
    return instanceCount;
}

void InventoryManager::swapItems(int shelfIndexA, int compartmentA, int shelfIndexB, int compartmentB) {

    LibraryShelf& shelfA = (*libraryShelves[shelfIndexA]);
    LibraryShelf& shelfB = (*libraryShelves[shelfIndexB]);

    InventoryItem* temp = shelfA[compartmentA];
    shelfA[compartmentA] = shelfB[compartmentB];
    shelfB[compartmentB] = temp;
}
