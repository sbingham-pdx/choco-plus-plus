#include "oterminal.h"

#include <iostream>
using namespace std;

oterminal::oterminal() {}

oterminal::~oterminal() {}

void oterminal::printMenu() {
    cout << "Welcome to Choco-Plus-Plus!\n---\n";
    cout << "Please enter a selection:\n";
    cout << "(1) Add new provider (2) Add new member (3) Add new service\n";
    cout << "(4) Update provider status (5) Update member status (6) Update service status\n";
    cout << "Enter any other integer to quit.\n";
}

int oterminal::validateInputInteger() {
    int num;
    cout << " >>> ";
    while(!(cin >> num)) {
        // Error message
        cout << "Invalid integer input. Try again.\n";
        // Clear previous input
        cin.clear();
        // Discard previous input
        cin.ignore(10000, '\n');
        cout << " >>> ";
    }
    return num;
}

float oterminal::validateInputFloat() {
   float num;
    cout << " >>> ";
    while(!(cin >> num)) {
        // Error message
        cout << "Invalid float input. Try again.\n";
        // Clear previous input
        cin.clear();
        // Discard previous input
        cin.ignore(10000, '\n');
        cout << " >>> ";
    }
    return num; 
}

string oterminal::validateInputString() {
    string s;
    cout << " >>> ";
    while(!(getline(cin, s))) {
        // Error message
        cout << "Invalid string input. Try again.\n";
        // Clear previous input
        cin.clear();
        // Discard previous input
        cin.ignore(10000, '\n');
        cout << " >>> ";
    }
    return s;
}

provider oterminal::inputProvider() {
    provider newProvider;
    cout << "Enter provider name";
    newProvider.name = validateInputString();
    cout << "Enter street name of provider";
    newProvider.street = validateInputString();
    cout << "Enter city name of provider";
    newProvider.city = validateInputString();
    cout << "Enter state abbreviation of provider";
    newProvider.state = validateInputString();
    cout << "Enter zip code of provider";
    newProvider.zip = validateInputString();
    cout << "Enter provider number";
    newProvider.provider_number = validateInputString();
    return newProvider;
}

member oterminal::inputMember() {
    member newMember;
    cout << "Enter member name";
    newMember.name = validateInputString();
    cout << "Enter street name of member";
    newMember.street = validateInputString();
    cout << "Enter city name of member";
    newMember.city = validateInputString();
    cout << "Enter state abbreviation of member";
    newMember.state = validateInputString();
    cout << "Enter zip code of member";
    newMember.zip = validateInputString();
    cout << "Enter member ID";
    newMember.number = validateInputString();
    return newMember;
}

service oterminal::inputService() {
    service newService;
    cout << "Enter service number";
    newService.number = validateInputString();
    cout << "Enter service name";
    newService.name = validateInputString();
    cout << "Enter service fee";
    newService.fee = validateInputFloat();
    return newService;
}

// 1 for status active
// 0 status suspended
// -1 for ID not found
// -2 : invalid table information passed to function
// -3: member or provider found but isDeleted
void oterminal::interpretProviderStatus(const int status, const string providerToEdit) {
    switch(status) {
        case 1: {
            cadb tempDatabase;
            cout << "This provider status is ACTIVE.\n";
            cout << "Would you like to suspend this provider?\n";
            cout << "(1) Yes (2) No\n";
            int choice = validateInputInteger();
            if (choice == 1) {
                tempDatabase.setCell("provider", "provider_number", providerToEdit, "provider_status", "0");
            }
        } break;
        case 0: {
            cadb tempDatabase;
            cout << "This provider status is SUSPENDED.\n";
            cout << "Would you like to activate this provider?\n";
            cout << "(1) Yes (2) No\n";
            int choice = validateInputInteger();
            if (choice == 1) {
                tempDatabase.setCell("provider", "provider_number", providerToEdit, "provider_status", "1");
            }
        } break;
        case -1: {
            cout << "This provider ID was not found.\n";
        } break;
        case -2: {
            cout << "ERROR: Invalid table information passed to function.\n";
        } break;
        case -3: {
            cout << "ERROR: Member or provider found, but was deleted and cannot be edited.\n";
        } break;
        default: {
            cout << "ERROR: Status of provider was unattainable at this time. Try again later.\n";
        } break;
    }
}

void oterminal::interpretMemberStatus(const int status, const string memberToEdit) {
    switch(status) {
        case 1: {
            cadb tempDatabase;
            cout << "This members status is ACTIVE.\n";
            cout << "Would you like to suspend this member?\n";
            cout << "(1) Yes (2) No\n";
            int choice = validateInputInteger();
            if (choice == 1) {
                tempDatabase.setCell("member", "member_number", memberToEdit, "member_status", "0");
            }
        } break;
        case 0: {
            cadb tempDatabase;
            cout << "This members status is SUSPENDED.\n";
            cout << "Would you like to activate this member?\n";
            cout << "(1) Yes (2) No\n";
            int choice = validateInputInteger();
            if (choice == 1) {
                tempDatabase.setCell("member", "member_number", memberToEdit, "member_status", "1");
            }
        } break;
        case -1: {
            cout << "This member ID was not found.\n";
        } break;
        case -2: {
            cout << "ERROR: Invalid table information passed to function.\n";
        } break;
        case -3: {
            cout << "ERROR: Member was found, but was deleted and cannot be edited.\n";
        } break;
        default: {
            cout << "ERROR: Status of member was unattainable at this time. Try again later.\n";
        } break;
    }
}

void oterminal::interpretServiceStatus(const int status, const string serviceToEdit) {
    switch(status) {
        case 1: {
            cadb tempDatabase;
            cout << "This service status is ACTIVE.\n";
            cout << "Would you like to suspend this member?\n";
            cout << "(1) Yes (2) No\n";
            int choice = validateInputInteger();
            if (choice == 1) {
                tempDatabase.setCell("service", "service_number", serviceToEdit, "service_status", "0");
            }
        } break;
        case 0: {
            cadb tempDatabase;
            cout << "This service status is SUSPENDED.\n";
            cout << "Would you like to activate this member?\n";
            cout << "(1) Yes (2) No\n";
            int choice = validateInputInteger();
            if (choice == 1) {
                tempDatabase.setCell("service", "service_number", serviceToEdit, "service_status", "1");
            }
        } break;
        case -1: {
            cout << "This service ID was not found.\n";
        } break;
        case -2: {
            cout << "ERROR: Invalid table information passed to function.\n";
        } break;
        case -3: {
            cout << "ERROR: Service was found, but was deleted and cannot be edited.\n";
        } break;
        default: {
            cout << "ERROR: Status of service was unattainable at this time. Try again later.\n";
        } break;
    }
}

int oterminal::useTerminal() {
	int selection = 0;
    bool run = true;
    while (run) {
        printMenu();
        selection = validateInputInteger();
        cin.ignore(10000, '\n');
        switch(selection) {
            case 1: {
                cout << "Adding new provider . . .\n";
                // Creating new provider
                provider newProvider = inputProvider();
                // Validating provider can be inserted
                if (newProvider.read(newProvider.provider_number,newProvider.name,newProvider.street,newProvider.city,newProvider.state,newProvider.zip)) {
                    // Success
                    cout << "New provider will be entered into database.\n";
                    newProvider.insert();
                } else {
                    // Failure
                    cout << "Invalid user input.\n";
                }
            }
                // Returns to main terminal
                cout << "Returning to main menu.\n---\n";
                break;
            case 2: {
                cout << "Adding new member . . .\n";
                // Creating new member
                member newMember = inputMember();
                // Validating member can be inserted
                if (newMember.read(newMember.number,newMember.name,newMember.street,newMember.city,newMember.state,newMember.zip)) {
                    // Success
                    cout << "New member will be entered into database.\n";
                    newMember.insert();
                } else {
                    // Failure
                    cout << "Invalid user input.\n";
                }
            }
                // Returns to main terminal
                cout << "Returning to main menu.\n---\n";
                break;
            case 3: {
                // TODO
                cout << "Adding new service . . .\n";
                // Creating new service
                service newService = inputService();
                // Validating service can be inserted
                if (newService.read(newService.number,newService.name,newService.fee)) {
                    cout << "New service will be entered into database.\n";
                    newService.insert();
                } else {
                     cout << "Invalid user input.\n";
                }
            }
                // Returns to main terminal
                cout << "Returning to main menu.\n---\n";
                break;
            case 4: {
                // TODO
                cadb tempDatabase;
                cout << "Updating provider status . . .\n";
                cout << "Enter provider number\n";
                int provider_id_tocheck = tempDatabase.getID("provider", to_string(validateInputInteger()));
                int status = tempDatabase.getStatus("provider", provider_id_tocheck);
                interpretProviderStatus(status, to_string(provider_id_tocheck));
            }
                // Returns to main terminal
                cout << "Returning to main menu.\n---\n";
                break;
            case 5: {
                // TODO
                /*
                cout << "Updating member status . . .\n";
                cout << "Enter member number\n";
                int memberToEdit = validateInputInteger();
                // int status = database.getStatus("member", memberToEdit);
                interpretMemberStatus(status, memberToEdit);
                */
            }   
                // Returns to main terminal
                cout << "Returning to main menu.\n---\n";
                break;
            case 6: {
                // TODO
                /*
                cout << "Updating service status . . .\n";
                cout << "Enter service number\n";
                int serviceToEdit = validateInputInteger();
                int status = database.getStatus("service", serviceToEdit);
                interpretServiceStatus(status, serviceToEdit);
                */
            }
                // Returns to main terminal
                cout << "Returning to main menu.\n---\n";
                break;
            default: {
                cout << "Exiting Choco-Plus-Plus.\n";
                run = false;
            }          
                break;
        }
    }
    return 1;
}
