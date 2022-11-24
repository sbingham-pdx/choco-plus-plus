#ifndef _MANAGER
# define _MANAGER

//Include modular files 
#include "reports.h"


//DEFINED Macros
#define ERROR
//Function prototypes 
void to_report(string &);   //Grabs the file name 
void to_id(int &);     //Grabs an ID
void to_visit(int &);

//int manager(); 

int
main()
{

    //Local variables 
    int choice, id; 
    management_report manage_report; 
    string report; 

    do{
        //The different options the manager terminal will carry out 
        cout  << "\n0 = Exit the manager terminal"
              << "\n1 = Display all providers to a file"
              << "\n2 = Display a specific provider to a file"
              << "\n3 = Dispaly all members to a file"
              << "\n4 = Display a specific member to a file"
              << "\n5 = Display the account payable report to a file"
              << "\n6 = Display the electronic fund transfer to a file"
              << "\n7 = Display the provider directoy to a file"
              << "\n8 = Display the paid visits to a file"
              << "\n9 = Mark a visit a paid\n"; 
 
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
            //Displays the reports to be paid 
            case 8:
                to_report(report); 
                manage_report.batch_mark_paid(report);
            //Marks a visit as paid based on the transaction ID
            case 9: 
                to_visit(id); 
                manage_report.mark_paid(id); 
            //Default when none of the cases are true
            default: /* ? */
                cout << "\nNo matches found, ERROR NUMBER: " << choice << endl;
                //system_error(errno, "No matches found", choice); 
                break; 
        }
        
    } while(choice != 0);

    return 1;
    
}
#ifdef ERROR
//Function definitions
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
        cout << "\nAn invalid file (Must Exist), ERROR FILE: INVALID " << endl; 
        to_report(a_report);
    }
}
void 
to_id(int & a_id)
{ 
    //Exception handling in case the ID is not valid 
    try{

        cout << "\nPlease enter the ID: ";
        cin >> a_id; //cin.ignore(100, '\n'); 

        if(a_id < 9 || a_id > 9){
            throw a_id;
        }
    }
    catch(int a_id){
        cout << "\nAn invalid ID # format (Must Be 9 Digits) , ERROR NUMBER: " << a_id << endl;
        to_id(a_id); 
    }
}
void
to_visit(int & a_id)
{
    //Exception handling in case the transaction ID is not valid 
    try{

        cout << "\nPlease enter the ID: ";
        cin >> a_id; //cin.ignore(100, '\n'); 

        if(a_id < 6 || a_id > 6){
            throw a_id;
        }
    }
    catch(int a_id){
        cout << "\nAn invalid ID # format (Must Be 6 Digits) , ERROR NUMBER: " << a_id << endl;
        to_visit(a_id); 
    }
}
#endif // ERROR

#endif // _MANAGER
