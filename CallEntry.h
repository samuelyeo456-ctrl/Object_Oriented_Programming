#ifndef CALLENTRY_H
#define CALLENTRY_H

#include "PhoneLogEntry.h"

class CallEntry : public PhoneLogEntry {
public:
    CallEntry(); // default constructor
    CallEntry(const std::string& contactName, const std::string& contactNumber, int duration);
    CallEntry(const CallEntry& src); // Copy constructor
    CallEntry& operator=(const CallEntry& src); // Copy assignment operator
    ~CallEntry(); // Destructor

    void display() const;
    void interact();
    std::string getdata()const override;
private:
    int duration;
};

#endif