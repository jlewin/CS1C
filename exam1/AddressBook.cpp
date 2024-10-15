#include <iostream>
#include "AddressBook.h"

using namespace std;

AddressBook::AddressBook() {
    itemCount = 0;
    bufferSize = 1;
    items = new AddressEntry*[bufferSize];
}

AddressBook::AddressBook(const AddressBook& other) {
    itemCount = other.itemCount;
    bufferSize = other.bufferSize;
    items = new AddressEntry*[other.bufferSize];

    for (int i = 0; i < itemCount; i++) {
        items[i] = new AddressEntry(*other.items[i]);
    }
}


AddressBook::~AddressBook() {
    for (int i = 0; i < itemCount; i++) {
        delete items[i];
    }

    delete [] items;
}

void AddressBook::AddEntry(string name, string phone, string email) {
    // Ensure space
    EnsureSpace();

    items[itemCount++] = new AddressEntry(name, phone, email);
}

void AddressBook::AddEntry(const AddressEntry& other) {
    EnsureSpace();
    items[itemCount++] = new AddressEntry(other);
}

void AddressBook::EnsureSpace() {
    if (itemCount + 1 > bufferSize) {
        int initialSize = bufferSize;

        bufferSize *= 2;

        // Double array size and clone items
        AddressEntry** temp = new AddressEntry*[bufferSize];
        for (int i = 0; i < itemCount; i++) {
            temp[i] = items[i];
        }

        // Free existing
        delete [] items;

        // Update reference
        items = temp;

        #ifdef LOG_VERBOSE
            cout << "Growing array from/to (" << initialSize << "," << bufferSize << ")" << endl;
        #endif
    }
}

int AddressBook::getItemCount() {
    return itemCount;
}

// Operator overloads
AddressEntry* AddressBook::operator[] (int index) const{
    // Return value of AddressEntry copy
    if (index >= itemCount) {
        return nullptr;
    }

    return items[index];
 }

AddressBook* AddressBook::operator+(const AddressBook& other ) const {
    AddressBook* temp = new AddressBook(*this);

    for (int i = 0; i < other.itemCount; i++) {
        temp->AddEntry(*(other.items[i]));
    }

    return temp;
}

ostream& operator<<(ostream& outstream, const AddressBook *addressBook) {
    outstream << "------Address Book-------" << endl;
    outstream << "Size: " << addressBook->itemCount << endl;

    // Loop over entries
    for (int i = 0; i < addressBook->itemCount; i++) {
        outstream << (*addressBook)[i];
    }

    outstream << "---------------------------" << endl;

    return outstream;
}


