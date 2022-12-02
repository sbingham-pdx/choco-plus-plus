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
      termHeader(3);
      cout << "Please enter your provider number below.\n"
          << "If you do not know your provider number, please use the demo number: 555554444" << endl;
      cout << "Provider Number: ";
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
  termHeader(3);
  cout << "Hello " << pname << "." << endl;
  scrBrk();
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
  int numgood = 0;

  visit new_visit;

  new_visit.provider_id = database.getID("provider", pnumber);
  while (!numgood){
    termHeader(3);
    // get member number
    cout << "Please enter member number below.\n"
        << "If you do not have a member number with you, please use the demo number: 333333333" << endl;
    scrBrk();
    cout << "Member Number: ";
    getline(cin, entry);
    cout << entry << endl;
    if (!database.getID("member", entry)){
      cout << "\n\nError - Invalid Member Number, please try again." << endl;
      cin.get();
    }
    else{
      new_visit.member_id = database.getID("member", entry);
      entry = "";
      clearcin();
      numgood = 1;
    }
  }
  
  numgood = 0;
  while(!numgood){
    termHeader(3);
    // get date of service
    cout << "\nEnter date of service in the format\nYYYY-MM-DD\n";
    scrBrk();
    getline(cin, entry);
    if(!validate_date(entry)){
      cout << "\n\nError - Invalid Date Entered, please try again." << endl;
      cin.get();
    }
    else{
      new_visit.date = entry;
      entry = "";
      clearcin();
      numgood = 1;
    }
  }

  numgood = 0;
  while (!numgood){
    termHeader(3);
	  // get service code
    cout << "Please enter service number below.\n"
        << "If you do not know a service number, please use the demo number: 555444" << endl;
    scrBrk();
    cout << "Service Number: ";
    getline(cin, entry);
    if (!database.getID("service", entry)){
      cout << "\n\nError - Invalid Service Number, please try again." << endl;
      cin.get();
    }
    else{
      new_visit.service_id = database.getID("service", entry);
      entry = "";
      clearcin();
      numgood = 1;
    }
  }

  termHeader(3);
	// get comments
  cout << "\nEnter comments\n";
  scrBrk();
  getline(cin, entry);
  new_visit.comment = entry;
  entry = "";
  clearcin();

  termHeader(3);
  cout << "Write visit to database?" << endl;
  scrBrk();
  cout << "[1] Yes\n"
      << "[2] No" << endl;
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
