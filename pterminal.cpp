// Lily Machamer
// Provider Terminal

#include <iostream>

using namespace std;

int pterminal();

int pterminal() {
	int selection = 0;
	int pnumber = 0;

	provider this_provider;
	
	// get provider number
	cout << "Please enter your provider number:\n";
	cin >> pnumber;
	
	// find provider in db, attach to this_provider

	// get initial selection
	cout << "Enter an integer for (1)Directory, (2)Weekly Report, (3)New Service\n";
	cin >> selection;

	switch(selection) {
		case 1:
			cout << "Provider Directory\n";
			// print directory
			// return
			break;
		case 2:
			cout << "Weekly Report\n";
			// print weekly report
			// return
			break;
		case 3:
			cout << "New Service\n";
			// get member number
			// check member number
			// if invalid or suspended, ask for member number again
			// get date of service
			// get service code
			// get comments
			// print information given, y/n confirmation
			// if no, clear out new class
			// if yes, write to db
			// return out of pterminal
			break;
		default:
			cout << "Invalid option, exiting.\n";
			return 2;
	}
	return 1;
}
