#ifndef PHONELOGENTRY_H
#define PHONELOGENTRY_H

#include <string>

class PhoneLogEntry {
public:
    PhoneLogEntry();
    PhoneLogEntry(const std::string& name, const std::string& phoneNumber);
    virtual ~PhoneLogEntry(); // Virtual destructor
    PhoneLogEntry(const PhoneLogEntry& src); // Copy constructor
    PhoneLogEntry& operator=(const PhoneLogEntry& src); // Copy assignment operatora

    virtual void display() const = 0;
    virtual void interact() = 0;
    std::string getContactNo() const;
    virtual std::string getdata() const;
protected:
    std::string name;
    std::string phoneNumber;
};

#endif