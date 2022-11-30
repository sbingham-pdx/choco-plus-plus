#include "oterminal.h"

#include <iostream>
using namespace std;

void scrBrk(){
    cout << "=================================================================================================" << endl;
}


oterminal::oterminal() {}

oterminal::~oterminal() {}

void oterminal::printMenu() {
    scrBrk();
    cout << "Welcome to the Operator Terminal.\nPlease choose from the options below:" << endl;
    scrBrk();
    cout << "[0] Exit\n"
        << "[1] Add new provider\n"
        << "[2] Add new member\n"
        << "[3] Add new service\n"
        << "[4] Update provider status\n"
        << "[5] Update member status\n"
        << "[6] Update service status" << endl;
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

// STATUS
// 1 for status active
// 0 status suspended
// -1 for ID not found
// -2 : invalid table information passed to function
// -3: member or provider found but isDeleted
// DELETED
// 0 for not deleted
// 1 for deleted
void oterminal::interpretProviderStatus(const int status, const string providerToEdit) {
    switch(status) {
        case 1: {
            cadb tempDatabase;
            cout << "This provider status is ACTIVE.\n";
            cout << "Would you like to suspend or delete this provider?\n";
            cout << "(1) Suspend (2) Delete (3) Neither\n";
            int choice = validateInputInteger();
            if (choice == 1) {
                tempDatabase.setCell("provider", "id", providerToEdit, "provider_status", "0");
                cout << "This provider has been suspended.\n";
            } else if (choice == 2) {
                tempDatabase.setCell("provider", "id", providerToEdit, "isDeleted", "1");
                cout << "This provider has been deleted.\n";
            }
        } break;
        case 0: {
            cadb tempDatabase;
            cout << "This provider status is SUSPENDED.\n";
            cout << "Would you like to activate or delete this provider?\n";
            cout << "(1) Activate (2) Delete (3) Neither\n";
            int choice = validateInputInteger();
            if (choice == 1) {
                tempDatabase.setCell("provider", "id", providerToEdit, "provider_status", "1");
                cout << "This provider has been activated.\n";
            } else if (choice == 2) {
                tempDatabase.setCell("provider", "id", providerToEdit, "isDeleted", "1");
                cout << "This provider has been deleted.\n";
            }
        } break;
        case -1: {
            cout << "This provider ID was not found.\n";
        } break;
        case -2: {
            cout << "ERROR: Invalid table information passed to function.\n";
        } break;
        case -3: {
            cadb tempDatabase;
            cout << "This provider was found, but was deleted.\n";
            cout << "Would you like to reenable this provider?\n";
            cout << "(1) Yes (2) No\n";
            int choice = validateInputInteger();
            if (choice == 1) {
                tempDatabase.setCell("provider", "id", providerToEdit, "isDeleted", "0");
                cout << "This provider has been reenabled.\n";
            }
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
            cout << "Would you like to suspend or delete this member?\n";
            cout << "(1) Suspend (2) Delete (3) Neither\n";
            int choice = validateInputInteger();
            if (choice == 1) {
                tempDatabase.setCell("member", "id", memberToEdit, "member_status", "0");
                cout << "This member has been suspended.\n";
            } else if (choice == 2) {
                tempDatabase.setCell("member", "id", memberToEdit, "isDeleted", "1");
                cout << "This member has been deleted.\n";
            }
        } break;
        case 0: {
            cadb tempDatabase;
            cout << "This members status is SUSPENDED.\n";
            cout << "Would you like to activate or delete this member?\n";
            cout << "(1) Activate (2) Delete (3) Neither\n";
            int choice = validateInputInteger();
            if (choice == 1) {
                 tempDatabase.setCell("member", "id", memberToEdit, "member_status", "1");
                cout << "This member has been activated.\n";
            } else if (choice == 2) {
                 tempDatabase.setCell("member", "id", memberToEdit, "isDeleted", "1");
                cout << "This member has been deleted.\n";
            }
        } break;
        case -1: {
            cout << "This member ID was not found.\n";
        } break;
        case -2: {
            cout << "ERROR: Invalid table information passed to function.\n";
        } break;
        case -3: {
            cadb tempDatabase;
            cout << "Member was found, but was deleted.\n";
            cout << "Would you like to reenable this member?\n";
            cout << "(1) Yes (2) No\n";
            int choice = validateInputInteger();
            if (choice == 1) {
                tempDatabase.setCell("member", "id", memberToEdit, "isDeleted", "0");
                cout << "This member has been reenabled.\n";
            }
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
            cout << "Would you like to suspend or delete this member?\n";
            cout << "(1) Suspend (2) Delete (3) Neither\n";
            int choice = validateInputInteger();
            if (choice == 1) {
                tempDatabase.setCell("service", "id", serviceToEdit, "service_status", "0");
                cout << "This service has been suspended.\n";
            } else if (choice == 2) {
                // no isDelete for services?
                // tempDatabase.setCell("service", "id", serviceToEdit, "isDeleted", "0");
                // cout << "This service has been deleted.\n";
            }
        } break;
        case 0: {
            cadb tempDatabase;
            cout << "This service status is SUSPENDED.\n";
            cout << "Would you like to activate or delete this member?\n";
            cout << "(1) Activate (2) Delete (3) Neither\n";
            int choice = validateInputInteger();
            if (choice == 1) {
                tempDatabase.setCell("service", "id", serviceToEdit, "service_status", "1");
                cout << "This service has been activated.\n";
            } else if (choice == 2) {
                // no isDelete for services?
                // tempDatabase.setCell("service", "id", serviceToEdit, "isDeleted", "1");
                // cout << "This service has been deleted.\n";
            }
        } break;
        case -1: {
            cout << "This service ID was not found.\n";
        } break;
        case -2: {
            cout << "ERROR: Invalid table information passed to function.\n";
        } break;
        case -3: {
            cadb tempDatabase;
            cout << "Service was found, but was deleted.\n";
            cout << "Would you like to reenable this service?\n";
            cout << "(1) Yes (2) No\n";
            int choice = validateInputInteger();
            if (choice == 1) {
                // tempDatabase.setCell("service", "id", serviceToEdit, "isDeleted", "0");
                // cout << "This service has been reenabled\n";
            }
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
                cadb tempDatabase;
                cout << "Updating provider . . .\n";
                cout << "Enter provider number\n";
                int provider_id_tocheck = tempDatabase.getID("provider", to_string(validateInputInteger()));
                int status = tempDatabase.getStatus("provider", provider_id_tocheck);
                interpretProviderStatus(status, to_string(provider_id_tocheck));
            }
                // Returns to main terminal
                cout << "Returning to main menu.\n---\n";
                break;
            case 5: {
                cadb tempDatabase;
                cout << "Updating member . . .\n";
                cout << "Enter member number\n";
                int member_id_tocheck = tempDatabase.getID("member", to_string(validateInputInteger()));
                int status = tempDatabase.getStatus("member", member_id_tocheck);
                interpretMemberStatus(status, to_string(member_id_tocheck));
            }   
                // Returns to main terminal
                cout << "Returning to main menu.\n---\n";
                break;
            case 6: {
                cadb tempDatabase;
                cout << "Updating service . . .\n";
                cout << "Enter service number\n";
                int service_id_tocheck = tempDatabase.getID("service", to_string(validateInputInteger()));
                int status = tempDatabase.getStatus("service", service_id_tocheck);
                interpretServiceStatus(status, to_string(service_id_tocheck));
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
