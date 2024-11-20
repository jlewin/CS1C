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
        int getItemCount() const;
        void add(const string&, const string&, const string&);
        void add(const AddressEntry&);
        int static getInstanceCount();

    private:
        static int instanceCount;
        void ensureSpace();
        int itemCount;
        int bufferSize;

        // Use an array of pointers to avoid up front allocation during construction,
        // shift to during insertion, so that large datasets don't double in size when
        // additional item is added, over their current size.
        AddressEntry** items;
};

#endif
