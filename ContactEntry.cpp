#include "ContactEntry.h"
#include "PhoneLogEntry.h"
#include "ContactEntry.h"
#include <iostream>
#include <stdexcept> // try catch
#include <limits> // try catch

using namespace std;

ContactEntry::ContactEntry() {
    name = "";
    phoneNumber = "";
}

ContactEntry::ContactEntry(const string& name, const string& phoneNumber) : PhoneLogEntry(name, phoneNumber) {}

string ContactEntry::getName() const {
    return name;
}
ContactEntry::~ContactEntry() {
}

string ContactEntry::getPhoneNumber() const {
    return phoneNumber;
}

void ContactEntry::display() const {

    cout << "Contact Name: " << getName() << ", Phone Number: " << getPhoneNumber();
}

void ContactEntry::interact() {

    cout << "";
}

// with try catch
void ContactEntry::addContact() {
    try {
        string newName, newPhoneNumber;

        // Prompt the user for contact details
        cout << "Enter new contact's name: ";
        cin.ignore();
        getline(cin, newName);

        cout << "Enter new contact's phone number: ";
        cin >> newPhoneNumber;

        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            throw invalid_argument("Invalid input for phone number. Please enter a valid number.");
        }

        // Create a new ContactEntry object and add it to the contacts list
        ContactEntry newContact(newName, newPhoneNumber);

        // Display the newly added contact
        newContact.display();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

