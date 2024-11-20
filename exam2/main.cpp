#include <iostream>
#include <fstream>
#include <iomanip>
#include "LibraryInventory.h"

using namespace std;

// AddressBook* loadSimpleList();
// AddressBook* loadFromDisk();

// Define LOG_VERBOSE or set -DLOG_VERBOSE compile time flag to enable verbose logging
// of constructor and destructor calls

int main() {

    LibraryInventory* inventory = new LibraryInventory();

    auto shelf = (*inventory)[0];
    shelf->addItem(new InventoryItem("The Great Gatsby", "F. Scott Fitzgerald", "1925"), 2); 

    cout << "Library Inventory instance count: " << LibraryInventory::getInstanceCount() << endl;
    cout << inventory << endl;

    return 0;
}
