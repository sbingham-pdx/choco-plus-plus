#include <iostream>
#include "oterminal.h"
using namespace std; 

int main(){

	int selection = 0;
    
	cout << "Welcome to Choco Plus Plus\n";
	cout << "Please enter an integer for\n(1)Manager, (2)Operator, or (3)Provider terminals\n";
	
	cin >> selection;

	switch(selection) {
		case 1:
			cout << "Manager Terminal\n";
			break;
		case 2:
			cout << "Operator Terminal\n";
			oterminal();
			break;
		case 3:
			cout << "Provider Terminal\n";
			break;
		default:
			cout << "Invalid entry, I will die now :(\n";
			return 2;
	}

	return 1;
}
