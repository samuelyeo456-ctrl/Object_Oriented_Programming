#include "LogManager.h"
#include <iostream>
#include "TextMessageEntry.h"
#include "CallEntry.h"
#include "MeetingEntry.h"
#include <limits> // try catch
#include <stdexcept> // try catch
#include <regex>
#include <iomanip>

using namespace std;

void LogManager::listAllContacts() const {
    cout << "All Contacts:\n";
    for (const ContactEntry& contact : contactList) {
        cout << "Contact Name: " << left << setw(12) << contact.getName() << ",  Phone Number: " << contact.getPhoneNumber() << endl;
    }
}
void LogManager::addContact(const string& contactName, const string& contactPhoneNumber) {
    ContactEntry newContact(contactName, contactPhoneNumber);
    this->contactList.push_back(newContact);
    totalcontacts = contactList.size();
}


// Default constructor 
LogManager::LogManager() {
}
// Destructor
LogManager::~LogManager() {
}
// Copy Constructor
LogManager::LogManager(const LogManager& src) {
    this->contactList = src.contactList;
    this->messageList = src.messageList;
    this->calllist = src.calllist;
    // Copy meetingList
    this->meetinglist = src.meetinglist;
}
// Copy Assignment Operator
LogManager& LogManager::operator=(const LogManager& src) {
    if (this != &src) {
        //clear existing content
        this->contactList.clear();
        this->messageList.clear();
        this->calllist.clear();
        this->meetinglist.clear();

        this->contactList = src.contactList;
        this->messageList = src.messageList;
        this->calllist = src.calllist;
        this->meetinglist = src.meetinglist;
    }
    return *this;
}
void LogManager::performActions() {
    try {
        if (this->contactList.empty()) {
            cout << "No contacts available. Please add contacts first." << endl;
            return;
        }

        cout << "\nChoose a contact to perform actions with:" << endl;
        for (size_t i = 0; i < contactList.size(); i++) {
            cout << i + 1 << ". " << contactList[i].getName() << endl;
        }
        cout << "Enter the contact number: ";
        int contactChoice;
        cin >> contactChoice;

        if (contactChoice >= 1 && contactChoice <= static_cast<int>(contactList.size())) {
            // Selected a valid contact
            int actionChoice;
            cout << "\nPerform actions with " << contactList[contactChoice - 1].getName() << ":\n";
            cout << "1. Send a Message\n";
            cout << "2. Make a Call\n";
            cout << "3. Schedule a Meeting\n";
            cout << "Enter your choice: ";
            cin >> actionChoice;

            if (actionChoice == 1) {
                // Send a message
                string message;
                cout << "\nEnter the message: ";
                cin.ignore();
                getline(cin, message);
                TextMessageEntry textMessage(contactList[contactChoice - 1].getName(), contactList[contactChoice - 1].getPhoneNumber(), message);
                addMessageToLog(textMessage);
                cout << endl;
                textMessage.interact();
            }
            else if (actionChoice == 2) {
                // Make a call
                int duration;
                srand((unsigned)time(NULL)); // seed random with time
                int random = 1 + (rand() % 100); // generate rand num between 1 and 100
                duration = random;
                CallEntry call(contactList[contactChoice - 1].getName(), contactList[contactChoice - 1].getPhoneNumber(), duration);
                addCallToLog(call);
                cout << endl;
                call.interact();
            }
            else if (actionChoice == 3) {
                // Schedule a meeting
                string date, time, location;
                cout << "\nEnter meeting date(dd/mm/yyyy): ";
                cin.ignore();
                getline(cin, date);
                cout << "Enter meeting time(24hour clock): ";
                getline(cin, time);
                cout << "Enter meeting location: ";
                getline(cin, location);
                MeetingEntry meeting(contactList[contactChoice - 1].getName(), contactList[contactChoice - 1].getPhoneNumber(), date, time, location);
                combine(date, time, location);
                addToMeeting(meeting);
                if (validateDateFormat(date) == true && validateTimeFormat(time) == true)
                    meeting.interact();
            }
            else {
                cout << "Invalid action choice." << endl;
            }
        }
        else {
            cout << "Invalid contact choice." << endl;
        }
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
void LogManager::addMessageToLog(const TextMessageEntry& message) {
    messageList.push_back(message);
}

void LogManager::addCallToLog(const CallEntry& call)
{
    calllist.push_back(call);
}

void LogManager::addToMeeting(const MeetingEntry& meeting) {
    if (validateDateFormat(meeting.getDate()) && validateTimeFormat(meeting.getTime()))
    {
        meetinglist.push_back(meeting);
    }
    else {
        cout << "Invalid format, please type again." << endl;
    }
}

bool LogManager::validateDateFormat(const string& date) {
    regex dateRegex("^(0[1-9]|[1-2][0-9]|3[0-1])/(0[1-9]|1[0-2])/(\\d{4})$");
    if (regex_match(date, dateRegex)) {
        return true;
    }
    else {
        return false;
    }
}
bool LogManager::validateTimeFormat(const string& time) {
    regex timeRegex("(0[0-2]|1[0-9]|2[0-3])[0-5][0-9]");
    if (regex_match(time, timeRegex)) {
        return true;
    }
    else {
        return false;
    }
}

string LogManager::combine(const string dates, const string time, const string location)
{
    string ss = "dates: " + dates + "\ntime: " + time + "\nlocation: ";
    return ss;
}

void LogManager::deleteContact() {
    if (contactList.empty()) {
        cout << "No contacts available to delete." << endl;
        return;
    }

    // Display current contacts
    cout << "Current Contacts:\n";
    for (size_t i = 0; i < contactList.size(); i++) {
        cout << i + 1 << ". " << contactList[i].getName() << ", " << contactList[i].getPhoneNumber() << endl;
    }

    // Get user input for contact to delete
    cout << "Enter the number of the contact to delete: ";
    int contactToDelete;
    cin >> contactToDelete;

    // Validate user input
    if (contactToDelete >= 1 && contactToDelete <= static_cast<int>(contactList.size())) {
        // Delete the selected contact
        contactList.erase(contactList.begin() + contactToDelete - 1);
        cout << "Contact deleted successfully!\n";
        totalcontacts--;
    }
    else {
        cout << "Invalid contact number.\n";
    }
}
void LogManager::showall()
{
    cout << endl;
    for (const ContactEntry& contact : contactList)
    {
        cout << "-----------------------------------\n";
        cout << contact.getName() << endl;
        cout << "-----------------------------------\n";
        for (const TextMessageEntry& message : messageList) // check the messagelist vector for all message
        {
            if (message.getContactNo() == contact.getPhoneNumber()) // if statement for checking the verifying contact's number
            {
                cout << "Message: " << message.getdata() << endl; // list all message linked to the contact's
            }
        }
        for (const CallEntry& call : calllist)
        {
            if (call.getContactNo() == contact.getPhoneNumber())
            {
                cout << "call duration: " << call.getdata() << " minutes" << endl;
            }
        }
        for (const MeetingEntry& meeting : meetinglist)
        {
            if (meeting.getContactNo() == contact.getPhoneNumber())
            {
                cout << "meeting: " << meeting.getdata() << endl;
            }
        }
        cout << endl;
    }
}
int LogManager::GetTotalContacts()
{
    return totalcontacts;
}