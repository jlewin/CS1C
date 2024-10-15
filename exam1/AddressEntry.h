#ifndef AddressEntry_H
#define AddressEntry_H

#include <iostream>
using namespace std;

class AddressEntry
{
    public:
        AddressEntry();
        AddressEntry(const AddressEntry&);
        AddressEntry(string, string, string);
        ~AddressEntry();

        // Accessors and mutators
        string getFullName() const; 
        string getPhoneNumber() const;
        string getEmail() const;
        void setFullName(string);
        void setPhoneNumber(string);
        void setEmail(string);

        void print();
        friend ostream& operator<<(ostream&, const AddressEntry*);

    private:
        static int instanceCount;
        int instanceId;
        string fullName;
        string phoneNumber;
        string email;
};

#endif
