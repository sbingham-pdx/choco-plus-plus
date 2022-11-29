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
int pnumber = 0;

int pterminal() {
	int selection = 0;

  cout << "Enter your provider number\n";
  cin >> pnumber;
  cout << "\nHello!\n-------------\n";

	// get initial selection
	cout << "\nEnter an integer for (1)Directory, (2)Weekly Report, (3)New Service\n";
	cin >> selection;

	switch(selection) {
		case 1:
			cout << "\nProvider Directory\n";
      provider_reporter.provider_directory("pdirectory");
      cout << "\nOutput provider directory to pdirectory.csv\n-------------\n";
      return 1;
			break;
		case 2:
			cout << "\nWeekly Report\n";
      provider_reporter.run(pnumber, "wreport");
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
	char new_num[10] = "";
	char new_date[40] = "";
  char new_service[10] = "";
	char new_comment[100] = "";
  int confirmation = 0;

  visit new_visit;

  new_visit.provider_id = database.getID("provider", to_string(pnumber));

	// get member number
  cout << "\nEnter member number for new service\n";
  cin >> new_num;
  new_visit.member_id = database.getID("member", new_num);
  cin.clear();

	// get date of service
  cout << "\nEnter date of service in the format\nYYYY-MM-DD\n";
  cin >> new_date;
  new_visit.date = new_date;
  cin.clear();

	// get service code
  cout << "\nEnter service code\n";
  cin >> new_service;
  new_visit.service_id = database.getID("service", new_service);
  cin.clear();

	// get comments
  cout << "\nEnter comments\n";
  cin >> new_comment;
  new_visit.comment = new_comment;
  cin.clear();

  cout << "\nWrite service to database? (1)yes or (2)no\n";
  cin >> confirmation;

  switch(confirmation){
    case 1:
      cout << "\nWriting to database\n-------------\n";
      new_visit.insert();
      cin.clear();
      return 1;
    case 2:
      cout << "Cancelling\n-------------\n";
      cin.clear();
      return 0;
    default:
      cout << "Invalid option, cancelling\n-------------\n";
      cin.clear();
      return 0;
  }
}
