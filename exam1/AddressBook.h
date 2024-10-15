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
        friend ostream& operator<<(ostream&, const AddressBook*);
        int getItemCount();
        void AddEntry(string, string, string);
        void AddEntry(const AddressEntry&);

    private:
        void EnsureSpace();
        int itemCount;
        int bufferSize;
        AddressEntry** items;

};

#endif
