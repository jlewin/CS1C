#include <iostream>
#include "AddressEntry.h"

using namespace std;

int AddressEntry::instanceCount = 0;

AddressEntry::AddressEntry() {
    // dbg instances
    #ifdef LOG_VERBOSE
        cout << "AddressEntry(" << instanceCount << ")" << endl;
    #endif
    instanceId = instanceCount++;
}

AddressEntry::AddressEntry(const AddressEntry& other) {
    // dbg instances
    #ifdef LOG_VERBOSE
        cout << "AddressEntry Copy(" << instanceCount << ")" << endl;
    #endif

    this->fullName = other.fullName;
    this->phoneNumber = other.phoneNumber;
    this->email = other.email;

    instanceId = instanceCount++;
}

AddressEntry::AddressEntry(string fullName, string phoneNumber, string email) {
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

void AddressEntry::setFullName(string newName) {
    fullName = newName;
}

void AddressEntry::setPhoneNumber(string newPhone) {
    phoneNumber = newPhone;
}

void AddressEntry::setEmail(string newEmail) {
    email = newEmail;
}


void AddressEntry::print() {
    cout << "Name: " << fullName << endl;
    cout << phoneNumber << endl;
    cout << email << endl << endl;
}


ostream& operator<<(ostream& outstream, const AddressEntry* entry) {
    outstream << endl
              << entry->fullName << endl
              << entry->phoneNumber << endl
              << entry->email << endl;

    return outstream;
}

