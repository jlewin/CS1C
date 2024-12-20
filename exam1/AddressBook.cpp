#include <iostream>
#include "AddressBook.h"

using namespace std;

int AddressBook::instanceCount = 0;

AddressBook::AddressBook() {
    itemCount = 0;
    bufferSize = 1;
    items = new AddressEntry*[bufferSize];
    instanceCount++;
}

AddressBook::AddressBook(const AddressBook& other) {
    itemCount = other.itemCount;
    bufferSize = other.bufferSize;
    items = new AddressEntry*[other.bufferSize];

    for (int i = 0; i < itemCount; i++) {
        items[i] = new AddressEntry(*other.items[i]);
    }

    instanceCount++;
}

AddressBook::~AddressBook() {
    // Free entries in the array
    for (int i = 0; i < itemCount; i++) {
        delete items[i];
    }

    // Free the array
    delete [] items;

    instanceCount--;
}

void AddressBook::add(const string& name, const string& phone, const string& email) {
    ensureSpace();
    items[itemCount++] = new AddressEntry(name, phone, email);
}

void AddressBook::add(const AddressEntry& other) {
    ensureSpace();
    items[itemCount++] = new AddressEntry(other);
}

// Resize the array, as needed using a doubling approach
void AddressBook::ensureSpace() {
    if (itemCount + 1 > bufferSize) {
        #ifdef LOG_VERBOSE
            int initialSize = bufferSize;
        #endif

        bufferSize *= 2;

        // Double array size and **copy** item references
        AddressEntry** temp = new AddressEntry*[bufferSize];
        for (int i = 0; i < itemCount; i++) {
            temp[i] = items[i];
        }

        // Free old array
        delete [] items;

        // Swap array reference
        items = temp;

        #ifdef LOG_VERBOSE
            cout << "Array grown from " << initialSize << " to " << bufferSize << endl;
        #endif
    }
}

int AddressBook::getItemCount() const {
    return itemCount;
}

// Operator overloads

// Add subscript operator, returning nullptr for non-existing items
AddressEntry* AddressBook::operator[] (int index) const{
    // Return value of AddressEntry copy
    if (index >= itemCount || index < 0) {
        return nullptr;
    }

    return items[index];
 }

// Add two address books
AddressBook* AddressBook::operator+(const AddressBook& other ) const {
    // Clone this address book
    AddressBook* temp = new AddressBook(*this);

    // Copy/clone in new items
    for (int i = 0; i < other.itemCount; i++) {
        temp->add(*(other.items[i]));
    }

    // Return the generated address book
    return temp;
}

// Duplicate the current address book, n times, into a new array
AddressBook* AddressBook::operator*(const int count ) const {
    AddressBook* temp = new AddressBook(*this);

    // Loop n times over this array, creating n cloned copies
    for (int j = 0; j < count -1; j++) {
        for (int i = 0; i < this->itemCount; i++) {
            temp->add(*(this->items[i]));
        }
    }

    // Return the generated address book
    return temp;
}

ostream& operator<<(ostream& outstream, const AddressBook *addressBook) {
    outstream << "--------Address Book-------" << endl;
    outstream << "Size: " << addressBook->itemCount << endl;

    // Loop over entries
    for (int i = 0; i < addressBook->itemCount; i++) {
        // Call the AddressEntry operator<< overload
        outstream << (*addressBook)[i];
    }

    outstream << "---------------------------" << endl;

    return outstream;
}

int AddressBook::getInstanceCount() {
    return instanceCount;
}