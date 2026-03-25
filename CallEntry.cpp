#include "CallEntry.h"
#include "CallEntry.h"
#include <iostream>

using namespace std;

CallEntry::CallEntry() {

}
CallEntry::CallEntry(const string& contactName, const string& contactNumber, int duration)
    : PhoneLogEntry(contactName, contactNumber), duration(duration) {}

// Copy constructor
CallEntry::CallEntry(const CallEntry& src)
    : PhoneLogEntry(src) {
    this->duration = src.duration;
}

// Copy assignment operator
CallEntry& CallEntry::operator=(const CallEntry& src) {
    if (this != &src) {
        // Copy base class members
        PhoneLogEntry::operator=(src);

        // Copy derived class members
        this->duration = src.duration;
    }
    return *this;
}

// Destructor
CallEntry::~CallEntry() {
}
void CallEntry::display() const {
    cout << "Call to: " << name << ", Duration: " << duration << " minutes";
}

void CallEntry::interact() {
    cout << "Call entry to: " << name << ", Duration: " << duration << " minutes";
    // Add interaction logic here
}

string CallEntry::getdata() const
{
    return to_string(duration);
}
