#ifndef CONTACTENTRY_H
#define CONTACTENTRY_H

#include "PhoneLogEntry.h"
#include <vector>

class ContactEntry : public PhoneLogEntry {
public:
    ContactEntry();
    ContactEntry(const std::string& name, const std::string& phoneNumber);
    ~ContactEntry();
    std::string getName() const;
    std::string getPhoneNumber() const;

    void addContact();
    void display() const override;
    void interact() override;

private:


};

#endif