#include <iostream>
#include "AddressEntry.h"

using namespace std;

int AddressEntry::instanceCount = 0;

AddressEntry::AddressEntry() {
    // dbg instances
    #ifdef LOG_VERBOSE
        cout << "AddressEntry(" << instanceCount << ")" << endl;
    #endif
    this->instanceId = instanceCount++;
}

AddressEntry::AddressEntry(const AddressEntry& other) {
    // dbg instances
    #ifdef LOG_VERBOSE
        cout << "AddressEntry Copy(" << instanceCount << ")" << endl;
    #endif

    this->fullName = other.fullName;
    this->phoneNumber = other.phoneNumber;
    this->email = other.email;
    this->instanceId = instanceCount++;
}

AddressEntry::AddressEntry(const string& fullName, const string&  phoneNumber, const string& email) {
    // dbg instances
    #ifdef LOG_VERBOSE
        cout << "AddressEntry(" << fullName << ", num, email): " << instanceCount << endl;
    #endif
    this->fullName = fullName;
    this->phoneNumber = phoneNumber;
    this->email = email;
    this->instanceId = instanceCount++;
}

AddressEntry::~AddressEntry() {
    // dbg instances
    #ifdef LOG_VERBOSE
        cout << "~AddressEntry(" << instanceId << ")" << endl;
    #endif

    instanceCount--;
}

int AddressEntry::getInstanceCount() {
    return instanceCount;
}

string AddressEntry::getFullName() const {
    return fullName;
} 
string AddressEntry::getPhoneNumber() const {
    return phoneNumber;
}
string AddressEntry::getEmail() const {
    return email;
}

void AddressEntry::setFullName(const string& newName) {
    fullName = newName;
}

void AddressEntry::setPhoneNumber(const string& newPhone) {
    phoneNumber = newPhone;
}

void AddressEntry::setEmail(const string& newEmail) {
    email = newEmail;
}

ostream& operator<<(ostream& outstream, const AddressEntry* entry) {
    outstream << endl
              << entry->fullName << endl
              << entry->phoneNumber << endl
              << entry->email << endl;

    return outstream;
}
