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

  cin.ignore(1000, '\n');

  while (!provGood){
      clearcin();
      termHeader(3);
      cout << "Please enter your provider number below.\n"
          << "If you do not know your provider number, please use the demo number: 555554444" << endl;
      cout << "Provider Number: ";
      getline(cin, pnumber);
      if (!database.getID("provider", pnumber)){
        //clear();
        cout << "\n\nError - Invalid Provider number, please try again." << endl;
      }
      else if(!database.getStatus("provider", database.getID("provider", pnumber)))
      {
        cout << "\n\nError - Suspended Provider" << endl;
        return 1;
      }
      else{
        pname = database.getString("provider", "provider_number", pnumber, "provider_name");
        provGood = 1;
      }
      clearcin();
  }
  do
  {
    termHeader(3);
    cout << "Hello " << pname << "." << endl;
    scrBrk();
    // get initial selection
    cout << "\nPlease select from the options below:\n"
         << "[0] Exit Provider Terminal" << endl
         << "[1] Provider Directory - (Directory of Available Services)\n"
         << "[2] Weekly Report - (Report of all services provided by " << pname << ")\n"
         << "[3] Check Member Status \n"
         << "[4] New Member Visit" << endl;
    getline(cin, selection);
    clearcin();

    selectionint = stoi(selection);

    switch (selectionint)
    {
    case 1:
      cout << "\nProvider Directory (Directory of Available Services)\n";
      provider_reporter.provider_directory(date(0)+"provider_directory");
      cout << "\nOutput provider directory\n-------------\n";
      break;
    case 2:
      cout << "\nWeekly Report\n";
      provider_reporter.run(stoi(pnumber), date(0)+"_"+pnumber+"_report");
      cout << "\nOutput provider weekly report\n-------------\n";
      break;
    case 3: 
      cout << "\nMember Stauts\n"; 
      member_status();
      break;
    case 4:
      cout << "\nNew Member Visit\n";
      pterminal_service();
      break;
    case 0:
      return 2;
    default:
      cout << "\nInvalid option, exiting.\n-------------\n";
      break;
    }
  } while (selectionint != 0);
  return 1;
}

int member_status()
{
   string entry;
   int numgood = 0;

  while (!numgood){
    termHeader(3);
    // get member number
    cout << "Please enter member number below.\n"
        << "If you do not have a member number with you, please use the demo number: 333333333" << endl;
    scrBrk();
    cout << "Member Number: ";
    getline(cin, entry);
    if (!database.getID("member", entry)){
      cout << "\n\nError - Invalid Member Number, please try again." << endl;
    }
    else if(!database.getStatus("member",database.getID("member", entry)))
    {
      cout << "\n\nError - Suspended Member, do not provide service" << endl;
      return 1;
    }
    else{
      clearcin();
      cout << "\n\n Active Member, go ahead with service\n";
      return 1;
    }
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
    if (!database.getID("member", entry)){
      cout << "\n\nError - Invalid Member Number, please try again." << endl;
    }
    else if(!database.getStatus("member",database.getID("member", entry)))
    {
      cout << "\n\nError - Suspended Member, do not provide service" << endl;
      return 1;
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
      clearcin();
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
    }
    else if(!database.getStatus("service", database.getID("service", entry)))
    {
      cout << "\n\nError - Inactive Service, no longer covered by ChocoAn." << endl;
      return 1;
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
  do
  {
    cout << "Write visit to database?" << endl;
    scrBrk();
    cout << "[1] Yes\n"
         << "[2] No" << endl;
    getline(cin, entry);
  }while (entry != "1" && entry != "2");

  confirmationint = stoi(entry);
  entry = "";
  clearcin();

  switch (confirmationint)
  {
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
