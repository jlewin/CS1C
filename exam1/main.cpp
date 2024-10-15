#include <iostream>
#include <fstream>
#include <iomanip>
#include "AddressBook.h"

using namespace std;

AddressBook* loadSimpleList();
AddressBook* loadFromDisk();

int main() {
    // Load and print an address book from disk (5 users)
    AddressBook* book1 = loadFromDisk();
    cout << book1 << endl;

    // Load a simple address book (3 users)
    AddressBook* book2 = loadSimpleList();
    cout << book2 << endl;

    // Use the + operator on the two address books
    AddressBook* book3 = *book2 + *book1;
    cout << book3 << endl;

    // Use the * operator with an address book and int
    AddressBook* book4 = *book2 * 2;
    cout << book4 << endl;

    // Confirm requirements with simple runtime checks
    AddressEntry* dne = (*book2)[1001];
    bool isNull = (dne == nullptr);
    cout << boolalpha << "DNE subscript returns nullptr: " << isNull << endl;

    
    AddressEntry* entry1 = (*book2)[0];
    AddressEntry* entry2 = (*book3)[0];
    
    bool entriesHaveSameUser = entry1->getFullName() == entry2->getFullName();
    bool entriesAreNotReferences = &entry1 != &entry2;

    cout << "Copied item is same: " << entriesHaveSameUser << " (" <<
            entry1->getFullName() << " == " << entry2->getFullName() << ")" << endl;
    cout << "Copied item is not ref: " << entriesAreNotReferences << " (" <<
            &entry1 << " != " << &entry2 << ")" << endl;

    // Free resources
    delete book1;
    delete book2;
    delete book3;
    delete book4;

    // Confirm free
    cout << "Cleans up env - remaining AddressEntry count: " << AddressEntry::getInstanceCount() << endl << endl;

    return 0;
}

// Load users from text file on disk
AddressBook* loadFromDisk() {
    // Open the user data file
    ifstream file("users.txt");

    AddressBook* addressBook = new AddressBook();
    string line, name, phone, email;
    
    // Read the file line by line
    while (!file.eof()) {
        // Read in one user block at a time
        getline(file, name);
        getline(file, phone);
        getline(file, email);
        getline(file, line);

        // Add entry for user
        addressBook->addEntry(name, phone, email);
    }

    // Close the file
    file.close();

    return addressBook;
}

AddressBook* loadSimpleList() {
    AddressBook* addressBook = new AddressBook();
    addressBook->addEntry("joe bob", "333-1234", "joebob@example.com");
    addressBook->addEntry("jim smith", "222-1234", "jim@example.com");
    addressBook->addEntry("bob talck", "111-1234", "bob@example.com");

    return addressBook;
}
