// Lily Machamer
// Provider Terminal

#include <iostream>
#include <cstring>
#include <string>
#include "pterminal.h"

using namespace std;

//hheh global variabls
cadb database;
provider_report provider_reporter;
string pnumber = "";

int pterminal() {
	string selection = "";
  int selectionint = 0;

  clearcin();
  cin.ignore(1000, '\n');
  cout << "Enter your provider number\n";
  getline(cin, pnumber);
  clearcin();
  cout << "\nHello!\n-------------\n";

	// get initial selection
	cout << "\nEnter an integer for (1)Directory, (2)Weekly Report, (3)New Service\n";
  getline(cin, selection);
  clearcin();

  selectionint = stoi(selection);

	switch(selectionint) {
		case 1:
			cout << "\nProvider Directory\n";
      provider_reporter.provider_directory("pdirectory");
      cout << "\nOutput provider directory to pdirectory.csv\n-------------\n";
      return 1;
			break;
		case 2:
			cout << "\nWeekly Report\n";
      provider_reporter.run(stoi(pnumber), "wreport");
      cout << "\nOutput provider directory to wreport.csv\n-------------\n";
      return 1;
			break;
		case 3:
			cout << "\nNew Service\n";
      pterminal_service();
			break;
		default:
			cout << "\nInvalid option, exiting.\n-------------\n";
			return 2;
	}
	return 1;
}


int pterminal_service(){
	// new service inputs
  string entry = "";
	string new_num = "";
	string new_date = "";
  string new_service = "";
	string new_comment = "";
  string confirmation = "";
  int confirmationint = 0;

  visit new_visit;

  new_visit.provider_id = database.getID("provider", pnumber);

	// get member number
  cout << "\nEnter member number for new service\n";
  getline(cin, entry);
  cout << entry << endl;
  new_visit.member_id = database.getID("member", entry);
  entry = "";
  clearcin();

	// get date of service
  cout << "\nEnter date of service in the format\nYYYY-MM-DD\n";
  getline(cin, entry);
  new_visit.date = entry;
  entry = "";
  clearcin();

	// get service code
  cout << "\nEnter service code\n";
  getline(cin, entry);
  new_visit.service_id = database.getID("service", entry);
  entry = "";
  clearcin();

	// get comments
  cout << "\nEnter comments\n";
  getline(cin, entry);
  new_visit.comment = entry;
  entry = "";
  clearcin();

  cout << "\nWrite service to database? (1)yes or (2)no\n";
  getline(cin, entry);
  confirmationint = stoi(entry);
  entry = "";
  clearcin();

  switch(confirmationint){
    case 1:
      cout << "\nWriting to database\n-------------\n";
      new_visit.insert();
      return 1;
    case 2:
      cout << "Cancelling\n-------------\n";
      return 0;
    default:
      cout << "Invalid option, cancelling\n-------------\n";
      return 0;
  }
}

void clearcin(){
  cin.clear();
  //cin.ignore(1000, '\n');
  return;
}
