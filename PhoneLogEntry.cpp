#include "PhoneLogEntry.h"
#include <iostream>

using namespace std;

PhoneLogEntry::PhoneLogEntry() {
    name = "";
    phoneNumber = "";
}
PhoneLogEntry::PhoneLogEntry(const string& name, const string& phoneNumber)
    : name(name), phoneNumber(phoneNumber) {}

// Virtual destructor
PhoneLogEntry::~PhoneLogEntry() {
    // Your destructor implementation, if needed
}

PhoneLogEntry::PhoneLogEntry(const PhoneLogEntry& src) {
    this->name = src.name;
    this->phoneNumber = src.phoneNumber;
}

// Properly implemented copy assignment operator
PhoneLogEntry& PhoneLogEntry::operator=(const PhoneLogEntry& src) {
    if (this != &src) {
        // Copy members
        this->name = src.name;
        this->phoneNumber = src.phoneNumber;
    }
    return *this;
}

void PhoneLogEntry::display() const {

    // Default implementation for display
    cout << "Default implementation for display: Contact Name: " << name << ", Phone Number: " << phoneNumber << endl;
}
string PhoneLogEntry::getContactNo() const
{
    return phoneNumber;
}

string PhoneLogEntry::getdata() const
{
    return "";
}