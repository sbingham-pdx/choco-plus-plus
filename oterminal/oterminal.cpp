#include "oterminal.h"

#include <iostream>
using namespace std;

int oterminal() {
	int selection = 0;
	
	// get provider number

	// get initial selection
	cout << "Enter an integer for (1)Directory, (2)Weekly Report, (3)New Service\n";
	cin >> selection;

	switch(selection) {
		case 1:
			cout << "Provider Directory\n";
			break;
		case 2:
			cout << "Weekly Report\n";
			break;
		case 3:
			cout << "New Service\n";
			break;
		default:
			cout << "oof ouchie my bones :(\n";
			return 2;
	}
	return 1;
}
