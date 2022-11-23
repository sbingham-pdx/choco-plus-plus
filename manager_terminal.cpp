#ifndef _MANAGER
# define _MANAGER

//Include modular files 
#include "reports.h"
//#include "cadb.h"

//Function prototype 
void to_report(string &);   //Grabs the file name 
void to_id(int & a_id);     //Grabs an ID

int
main()
{

    //Local variables 
    int choice, exception, id; 
    management_report manage_report; 
    string report; 

    do{
        //The different options the manager terminal will carry out 
        cout  << "\n0 = Exit the manager terminal"
              << "\n1 = Display all providers"
              << "\n2 = Display a specific provider"
              << "\n3 = Dispaly all members "
              << "\n4 = Display a specific member"
              << "\n5 = Display the account payable report"
              << "\n6 = Display the electronic fund transfer"
              << "\n7 = Display the provider directoy\n";
 
        cout << "\nPlease choose from the menu above: ";
        cin >> choice; cin.ignore(100,'\n');

        //Execute the code based on the choice 
        switch(choice){
            
            //Exits the manager terminal be setting choice to zero 
            case 0:
                choice = 0;
                break;
            //Displays all the providers via .csv file 
            case 1:
                to_report(report);
                manage_report.all_providers(report);
                break; 
            //Displays an individual provider via .csv file 
            case 2:
                to_report(report);
                to_id(id); 
                manage_report.individual_provider(id, report); 
                break; 
            //Displays all members via .csv file
            case 3:
                to_report(report);
                manage_report.all_members(report); 
                break; 
            //Displays an individual member via .csv file 
            case 4:
                to_report(report);
                to_id(id);
                manage_report.individual_member(id, report); 
                break; 
            //Displays the account apyables information via .csv file 
            case 5:
                to_report(report);
                manage_report.ap_report(report); 
                break;
            //Displays the electronic fund transfer via .csv file 
            case 6: 
                to_report(report);
                manage_report.eft_report(report); 
                break;
            //Displays the provider directory via .csv file 
            case 7:
                to_report(report);
                manage_report.provider_directory(report);
                break; 
            //Default when none of the cases are true
            default: /* ? */
                cout << "\nNo matches found, ERROR NUMBER: " << choice << endl;
                //system_error(errno, "No matches found", choice); 
                break; 
        }
        
    } while(choice != 0);

    return 1;
    
}
//Function definition 
void
to_report(string & a_report){

    //Exception handling in case the file is invalid
    try{

        cout << "\nPlease enter the name of the file to write to: ";
        getline(cin , a_report); 


        if(a_report.empty()){
            throw 0; 
        }
    }
    catch(...){
        cout << "\nAn invalid file, ERROR FILE: INVALID " << endl; 

    }
}
void 
to_id(int & a_id)
{
    //Exception handling in case the ID is not valid 
    try{

        cout << "\nPlease enter the ID: ";
        cin >> a_id; //cin.ignore(100, '\n'); 

        if(a_id < 6 || a_id > 7){
            throw a_id;
        }
    }
    catch(int a_id){
        cout << "\nAn invalid ID # format (Must be 6 digits) , ERROR NUMBER: " << a_id << endl; 

    }
}
#endif // _MANAGER