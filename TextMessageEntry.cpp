#include "TextMessageEntry.h"
#include <iostream>

using namespace std;

TextMessageEntry::TextMessageEntry() {
    message = "";
}
TextMessageEntry::TextMessageEntry(const string& contactName, const string& contactNumber, const string& message)
    : PhoneLogEntry(contactName, contactNumber), message(message) {}
// Copy constructor
TextMessageEntry::TextMessageEntry(const TextMessageEntry& src)
    : PhoneLogEntry(src) {
    this->message = src.message;
}

// Copy assignment operator
TextMessageEntry& TextMessageEntry::operator=(const TextMessageEntry& src) {
    if (this != &src) {
        // Copy base class members
        PhoneLogEntry::operator=(src);

        // Copy derived class members
        this->message = src.message;
    }
    return *this;
}

// Destructor
TextMessageEntry::~TextMessageEntry() {
    // Your destructor implementation, if needed
}
void TextMessageEntry::display() const {
    cout << "Text Message to: " << name << ", Message: " << message;
}

void TextMessageEntry::interact()
{
    cout << "Text message sent to: " << name << ", Message: " << message;
}
string TextMessageEntry::getdata() const
{
    return message;
}
