#include <iostream>
#include <fstream>
#include <cmath>
#include "AddressBook.h"

using namespace std;

int main() {

    // Open the user data file
    ifstream file("user-info.txt");

    AddressBook* book1 = new AddressBook();

    string line, name, phone, email;
    // Read the file line by line
    while (!file.eof()) {
        // Read in one user block
        getline(file, name);
        getline(file, phone);
        getline(file, email);
        getline(file, line);

        // Add entry for user
        book1->AddEntry(name, phone, email);
    }

    // Close the file
    file.close();

    // Print out the address book
    cout << book1 << endl;

    AddressBook* book2 = new AddressBook();
    book2->AddEntry("joe bob", "333-1234", "joebob@example.com");
    book2->AddEntry("jim smith", "222-1234", "jim@example.com");
    book2->AddEntry("bob talck", "111-1234", "bob@example.com");

    cout << book2 << endl;

    AddressBook* book3 = *book2 + *book1;
    cout << book3 << endl;

    delete book1;
    delete book2;
    delete book3;

    return 0;
}