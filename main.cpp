//EDE2012_P1_Group 6 OOP project: PhoneLogSystem
//Done By:
//Huan Shi Yu (2201834)
//Tan Jeng Siang Joel (2201062) 
//Yeo Chin Seng Samuel (2201066)
//Yuan Yu Cheng(2203365)
//Kelvin Hoi Wei Long(2200719)


#include "LogManager.h"
#include <iostream>
#include <stdexcept> // try catch
#include <limits>    // try catch
#include <string> // fileio
#include <fstream> // fileio
#include <iomanip>

using namespace std;

int main() {
    cout << "\n**********************************************" << " /\\_/\\ " << endl;
    cout << "     Welcome to Group 6 PhoneLogSystem        " << "( o.o )" << endl;
    cout << "**********************************************" << " > ^ < " << endl;

    LogManager logManager;

    fstream myFile; // file io

    // Read in contacts to logManager
    myFile.open("contacts.txt", ios::in); // Read mode

    if (myFile.is_open()) {
        string name, phoneNumber;

        while (getline(myFile, name) && getline(myFile, phoneNumber)) {
            // Create a new ContactEntry object and add it to the contacts list
            ContactEntry newContact(name, phoneNumber);
            // Add the new contact to the contactList
            logManager.addContact(name, phoneNumber);
        }

        myFile.close();
    }
    //end 
    int choice;
    while (1) {
        try {
            cout << "\n+----------------------------+\n";
            cout << "|    contacts stored: " << logManager.GetTotalContacts();
            cout << "      |\n+----------------------------+\n";
            cout << "|         Main Menu          |\n";
            cout << "+----------------------------+\n";
            cout << "| 1. List All Contacts       |\n";
            cout << "| 2. Add Contact             |\n";
            cout << "| 3. Perform Actions         |\n";
            cout << "| 4. List All Logs           |\n";
            cout << "| 5. Delete Contacts         |\n";
            cout << "| 6. Exit                    |\n";
            cout << "+----------------------------+\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid input. Please enter a number.");
            }

            if (choice == 1) {

                logManager.listAllContacts();

            }
            else if (choice == 2) {
                string contactName, contactPhoneNumber;
                cout << "Enter contact's name: ";
                cin.ignore();
                getline(cin, contactName);

                // Input and validation for phone number
                bool validPhoneNumber = false;
                while (!validPhoneNumber) {
                    try {
                        cout << "Enter contact's phone number: ";
                        cin >> contactPhoneNumber;

                        size_t pos;
                        // Convert string to integer and check for conversion errors
                        int phoneNumber = stoi(contactPhoneNumber, &pos);

                        // Check if the entire string was converted to a valid integer
                        if (pos == contactPhoneNumber.length()) {
                            validPhoneNumber = true;
                        }
                        else {
                            throw invalid_argument("Invalid input. Please enter a valid number.");
                        }
                    }
                    catch (const invalid_argument& e) {
                        cout << "Error: Please enter numbers only" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                logManager.addContact(contactName, contactPhoneNumber);
            }
            else if (choice == 3) {
                logManager.performActions();
            }
            else if (choice == 4) {

                logManager.showall();

            }
            else if (choice == 5) {
                logManager.deleteContact();
            }
            else if (choice == 6) {
                cout << "Exiting the program." << endl;
                return 0;
            }
            else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
