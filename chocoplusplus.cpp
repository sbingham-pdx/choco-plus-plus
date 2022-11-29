#include <iostream>
#include "pterminal.h"
//#include "reports/reports.h"
using namespace std; 


int main(){

	int selection = 0;
    
	cout << "Welcome to Choco Plus Plus\n\n";
	cout << "Please enter an integer for\n(1)Manager, (2)Operator, or (3)Provider terminals\n";
	
	cin >> selection;

	switch(selection) {
		case 1:
			cout << "\nManager Terminal\n";
			break;
		case 2:
			cout << "\nOperator Terminal\n";
			break;
		case 3:
			cout << "\nProvider Terminal\n";
			pterminal();
			break;
		default:
			cout << "\nInvalid entry, goodnight\n";
			return 2;
	}

	return 1;
}
