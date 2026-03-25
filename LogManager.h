
#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <vector>
#include "ContactEntry.h"
#include "TextMessageEntry.h"
#include "CallEntry.h"
#include "MeetingEntry.h"
class LogManager {
public:
    LogManager(); // Default constructor
    ~LogManager(); // Destructor
    LogManager(const LogManager& src); // Copy constructor
    LogManager& operator=(const LogManager& src); // Copy assignment operator

    void listAllContacts() const;
    void addContact(const std::string& contactName, const std::string& contactPhoneNumber);
    void performActions();
    //void showMessageLog()const;
    void addMessageToLog(const TextMessageEntry& message);
    //void showCallLog();
    void addCallToLog(const CallEntry& call);
    //void showMeetingLog();
    void addToMeeting(const MeetingEntry& meeting);
    std::string combine(const std::string dates, const std::string time, const std::string location);
    void deleteContact();
    void showall();
    int GetTotalContacts();
    bool validateDateFormat(const std::string& date); // Header declaration for date format validation
    bool validateTimeFormat(const std::string& time); // Header declaration for time format validation

private:
    std::vector<ContactEntry> contactList;
    std::vector<TextMessageEntry>messageList;
    std::vector<CallEntry>calllist;
    std::vector<MeetingEntry>meetinglist;
    int totalcontacts;
};
#endif