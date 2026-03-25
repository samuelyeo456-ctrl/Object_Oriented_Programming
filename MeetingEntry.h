#ifndef MEETINGENTRY_H
#define MEETINGENTRY_H

#include "PhoneLogEntry.h"

class MeetingEntry : public PhoneLogEntry {
public:
    MeetingEntry();
    MeetingEntry(const std::string& contactName, const std::string& contactNumber, const std::string& date, const std::string& time, const std::string& location);
    MeetingEntry(const MeetingEntry& src); // Copy constructor
    MeetingEntry& operator=(const MeetingEntry& src); // Copy assignment operator
    ~MeetingEntry(); // Destructor

    void display() const;
    void interact();
    std::string getdata()const override;
    const std::string& getDate() const {
        return date;
    }
    const std::string& getTime() const {
        return time;
    }

private:
    std::string date;
    std::string time;
    std::string location;
};

#endif