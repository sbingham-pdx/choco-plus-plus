#include <iostream>
#include "oterminal.h"
using namespace std; 

int main(){

	int run = 1;
	int selection = 0;
	oterminal operator_terminal;
    
	

	while(run){

		scrBrk();
		cout << "Welcome to Choco Plus Plus\nPlease select from the options below:" << endl;
		scrBrk();
		cout << "[1] Manager Terminal\n"
			<< "[2] Operator Terminal\n"
			<< "[3] Provider Terminal\n"
			<< "[4] Exit" << endl;
		
	
		cin >> selection;

		switch(selection) {
			case 1:
				cout << "Manager Terminal\n";
				management_terminal(); 
				break;
			case 2:
				cout << "Operator Terminal\n";
				operator_terminal.useTerminal();
				break;
			case 3:
				cout << "Provider Terminal\n";
				pterminal();
				break;
			case 4:
				cout << "Exiting..." << endl;
				run = 0;
				break;
			default:
				cout << "Invalid entry." << endl;
				//return 2;
		}
	}

	return 1;
}
