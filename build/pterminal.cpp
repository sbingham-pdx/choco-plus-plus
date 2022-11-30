// Lily Machamer
// Provider Terminal

#include <iostream>
#include <cstring>
#include <string>
#include "oterminal.h"

using namespace std;

//hheh global variabls
cadb database;
provider_report provider_reporter;
string pnumber = "";

int pterminal() {
  string pname;
	string selection = "";
  int selectionint = 0;
  int provGood = 0;

  while (!provGood){
      clearcin();
      cin.ignore(1000, '\n');
      cout << "Welcome to the Provider Terminal\nPlease enter your provider number below.\n"
          << "If you do not know your provider number, please use the demo number: 555554444" << endl;
      cout << "Provider Number:";
      getline(cin, pnumber);
      if (!database.getID("provider", pnumber)){
        //clear();
        cout << "\n\nError - Invalid Provider number, please try again." << endl;
        cin.get();
      }
      else{
        pname = database.getString("provider", "provider_number", pnumber, "provider_name");
        provGood = 1;
      }
      clearcin();
  }
  cout << "\nHello " << pname << "!\n-------------\n";

	// get initial selection
	cout << "\nPlease select from the options below:\n"
    << "[1] Provider Directory - (Directory of Available Services)\n"
    << "[2} Weekly Report - (Report of all services provided by " << pname << ")\n"
    << "[3] New Member Visit" << endl;
  getline(cin, selection);
  clearcin();

  selectionint = stoi(selection);

	switch(selectionint) {
		case 1:
			cout << "\nProvider Directory (Directory of Available Services)\n";
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
			cout << "\nNew Member Visit\n";
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
