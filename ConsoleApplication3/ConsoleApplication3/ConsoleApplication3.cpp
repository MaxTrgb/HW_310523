#include <iostream>
#include <string>

using namespace std;

// Structure to represent a phone book entry
struct Entry {

    string name;
    string phone;
};

// Function to add a new entry to the phone book
void addEntry(Entry*& entries, int& size, const string& name, const string& phone) {

    Entry* newEntries = new Entry[size + 1];  // Create a new array with increased size

    // Copy existing entries to the new array
    for (int i = 0; i < size; i++) {

        newEntries[i] = entries[i];
    }

    // Add the new entry to the end of the array
    newEntries[size].name = name;
    newEntries[size].phone = phone;

    delete[] entries;  // Delete the old array

    entries = newEntries;  // Point to the new array
    size++;  // Increase the size of the array
}

// Function to search for entries by name
void searchByName(const Entry* entries, int size, const string& name) {

    bool found = false;
    for (int i = 0; i < size; i++) {

        if (entries[i].name == name) {

            cout << "Name: " << entries[i].name << ", Phone: " << entries[i].phone << endl;
            found = true;
        }
    }
    if (!found) {

        cout << "No matching name found." << endl;
    }
}

// Function to search for entries by phone number
void searchByPhone(const Entry* entries, int size, const string& phone) {

    bool found = false;
    for (int i = 0; i < size; i++) {

        if (entries[i].phone == phone) {

            cout << "Name: " << entries[i].name << ", Phone: " << entries[i].phone << endl;
            found = true;
        }
    }
    if (!found) {

        cout << "No matching phone number found." << endl;
    }
}

// Function to change the phone number of an existing entry
void changeData(Entry* entries, int size, const string& name, const string& phone) {

    for (int i = 0; i < size; i++) {

        if (entries[i].name == name) {

            entries[i].phone = phone;
            cout << "Data changed successfully." << endl;
            return;
        }
    }
    cout << "No matching name found. Unable to change data." << endl;
}

int main() {

    Entry* phoneBook = nullptr;  // Pointer to store the phone book entries
    int size = 0;  // Size of the phone book array

    int choice;
    while (true) {

        // Display menu options
        cout << "To add a contact, enter 1. To change a contact, press 2. To search, enter 3. To exit, press 4." << endl;
        cin >> choice;

        if (choice == 1) {

            string name, phone;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> phone;
            addEntry(phoneBook, size, name, phone);  // Add a new entry to the phone book
        }
        else if (choice == 2) {

            string name, phone;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter new phone number: ";
            cin >> phone;
            changeData(phoneBook, size, name, phone);  // Change the phone number of an existing entry
        }
        else if (choice == 3) {

            int searchChoice;
            cout << "Search by name, press 1. Search by phone number, press 2." << endl;
            cin >> searchChoice;
            if (searchChoice == 1) {

                string name;
                cout << "Enter the name: ";
                cin >> name;
                searchByName(phoneBook, size, name);  // Search for entries by name
            }
            else if (searchChoice == 2) {

                string phone;
                cout << "Enter the phone number: ";
                cin >> phone;
                searchByPhone(phoneBook, size, phone);  // Search for entries by phone number
            }
        }
        else if (choice == 4) {

            break;  // Exit the program
        }
        else {

            cout << "Invalid choice. Please try again." << endl;
        }
    }

    delete[] phoneBook;  // Free the memory allocated for the phone book array

    return 0;
}
