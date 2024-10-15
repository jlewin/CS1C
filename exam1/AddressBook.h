#ifndef AddressBook_H
#define AddressBook_H

#include <iostream>
#include "AddressEntry.h"

using namespace std;

class AddressBook
{
    public:
        AddressBook();
        AddressBook(const AddressBook&);
        AddressEntry* operator[](int index) const;
        ~AddressBook();

        AddressBook* operator+(const AddressBook&) const;
        AddressBook* operator*(const int) const;

        friend ostream& operator<<(ostream&, const AddressBook*);
        int getItemCount();
        void addEntry(string, string, string);
        void addEntry(const AddressEntry&);

    private:
        void ensureSpace();
        int itemCount;
        int bufferSize;
        AddressEntry** items;
};

#endif
