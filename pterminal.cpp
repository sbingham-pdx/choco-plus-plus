// Lily Machamer
// Provider Terminal

#include <iostream>
#include <cstring>
#include "pterminal.h"

using namespace std;

int pterminal() {
	int selection = 0;
	int pnumber = 0;

	provider_report provider_reporter;	

	// get initial selection
	cout << "Enter an integer for (1)Directory, (2)Weekly Report, (3)New Service\n";
	cin >> selection;

	switch(selection) {
		case 1:
			cout << "Provider Directory\n";
      provider_reporter.provider_directory("pdirectory");
      cout << "Output provider directory to pdirectory.csv\n";
      return 1;
			break;
		case 2:
			cout << "Weekly Report\n";
			cout << "Building weekly report\n";
      provider_reporter.run(pnumber, "wreport");
      cout << "Output provider directory to wreport.csv\n";
      return 1;
			break;
		case 3:
			cout << "New Service\n";
      pterminal_service();
			break;
		default:
			cout << "Invalid option, exiting.\n";
			return 2;
	}
	return 1;
}


int pterminal_service(){
	// new service inputs
  char pnumber[9] = "";
	char new_num[9] = "";
	char new_date[30] = "";
  int new_service = 0;
	char new_comment[100] = "";
  char confirmation[2] = "";

  visit new_visit;
  cadb database;

	// get provider number
	cout << "Please enter your provider number:\n";
	cin >> pnumber;
  new_visit.provider_id = database.getID("provider", pnumber);

	// get member number
  cout << "Enter member number for new service\n";
  cin >> new_num;
  new_visit.member_id = database.getID("member", new_num);

	// get date of service
  cout << "Enter date of service\n";
  cin >> new_date;
  new_visit.date = new_date;

	// get service code
  cout << "Enter service code\n";
  cin >> new_service;
  new_visit.service_id = database.getID("service", new_num);

	// get comments
  cout << "Enter comments\n";
  cin >> new_comment;
  new_visit.comment = new_comment;

  cout << "Write service to database? [y/n]\n";
  cin >> confirmation;

  if (!strcmp(confirmation, "y")){
    cout << "Writing to database\n";
    new_visit.insert();
    return 1;
  } else if (!strcmp(confirmation, "n")){
    cout << "Cancelling\n";
    return 0;
  } else {
    cout << "Invalid option, cancelling\n";
    return 0;
  }
}
