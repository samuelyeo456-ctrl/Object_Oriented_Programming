#include "MeetingEntry.h"
#include <iostream>

using namespace std;

MeetingEntry::MeetingEntry() {
    date = "";
    time = "";
    location = "";
}
MeetingEntry::MeetingEntry(const string& contactName, const string& contactNumber, const string& date, const string& time, const string& location)
    : PhoneLogEntry(contactName, contactNumber), date(date), time(time), location(location) {}

// Copy constructor
MeetingEntry::MeetingEntry(const MeetingEntry& src)
    : PhoneLogEntry(src) {

    // Copy derived class members
    this->date = src.date;
    this->time = src.time;
    this->location = src.location;
}

// Copy assignment operator
MeetingEntry& MeetingEntry::operator=(const MeetingEntry& src) {
    if (this != &src) {
        // Copy base class members
        PhoneLogEntry::operator=(src);

        // Copy derived class members
        this->date = src.date;
        this->time = src.time;
        this->location = src.location;
    }
    return *this;
}

// Destructor
MeetingEntry::~MeetingEntry() {
}
void MeetingEntry::display() const {
    cout << "Meeting with: " << name << ", Date: " << date << ", Time: " << time << ", Location: " << location;
}

void MeetingEntry::interact() {
    cout << "Meeting entry logged with: " << name << ", Date: " << date << ", Time: " << time << ", Location: " << location;
    // Add interaction logic here
}
string MeetingEntry::getdata() const
{
    string onesentence;
    onesentence = "date    : " + date + "\n         time    : " + time + "\n         location: " + location;
    return onesentence;
}
