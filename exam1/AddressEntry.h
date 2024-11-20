#ifndef AddressEntry_H
#define AddressEntry_H

#include <iostream>
using namespace std;

class AddressEntry
{
    public:
        AddressEntry();
        AddressEntry(const AddressEntry&);
        AddressEntry(const string&, const string&, const string&);
        ~AddressEntry();

        // Accessors and mutators
        string getFullName() const; 
        string getPhoneNumber() const;
        string getEmail() const;
        void setFullName(const string&);
        void setPhoneNumber(const string&);
        void setEmail(const string&);

        friend ostream& operator<<(ostream&, const AddressEntry*);
        int static getInstanceCount();

    private:
        static int instanceCount;
        int instanceId;
        string fullName;
        string phoneNumber;
        string email;
};

#endif
