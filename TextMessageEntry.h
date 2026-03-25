#ifndef TEXTMESSAGEENTRY_H
#define TEXTMESSAGEENTRY_H

#include "PhoneLogEntry.h"

class TextMessageEntry : public PhoneLogEntry {
public:
    TextMessageEntry();
    TextMessageEntry(const std::string& contactName, const std::string& contactNumber, const std::string& message);
    TextMessageEntry(const TextMessageEntry& src); // Copy constructor
    TextMessageEntry& operator=(const TextMessageEntry& src); // Copy assignment operator
    ~TextMessageEntry(); // Destructor

    void display() const;
    void interact();
    std::string getdata()const override;
private:
    std::string message;
};

#endif