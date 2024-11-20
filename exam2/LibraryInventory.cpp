#include <iostream>
#include "LibraryInventory.h"

using namespace std;

int LibraryInventory::instanceCount = 0;

LibraryInventory::LibraryInventory() {
    instanceCount++;

    for (int i = 0; i < 6; i++) {
        libraryShelves.push_back(new LibraryShelf());
    }
}

LibraryShelf* LibraryInventory::operator[](int index) const {
    if (index >= 0 && index < libraryShelves.size()) {
        return libraryShelves[index];
    }
    return nullptr; // or handle the error as appropriate
}

int LibraryInventory::getShelfCount() const {
    return libraryShelves.size();
}

ostream& operator<<(ostream& outstream, const LibraryInventory *libraryInventory) {
    outstream << "-- Library Inventory -- << endl;
    for (int i = 0; i < libraryInventory->getShelfCount(); i++) {
        outstream << (*libraryInventory)[i];
    }

    return outstream;
}

int LibraryInventory::getInstanceCount() {
    return instanceCount;
}