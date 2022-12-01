#ifndef _MANAGER
# define _MANAGER

//Include modular files
#include "mterminal.h"

//Function definitions
void management_terminal()
{

    //Local variables 
    int choice, id; 
    management_report manage_report; 
    string report; 

    do{
        //The different options the manager terminal will carry out 
        cout  << "[0] Exit the manager terminal\n"
            << "[1] Create weekly report for all providers\n"
            << "[2] Create weekly report for an individual provider\n"
            << "[3] Create weekly report for all members\n"
            << "[4] Create weekly report for an individual member\n"
            << "[5] Create weekly accounts payable report\n"
            << "[6] Create weekly electronic fund transfer report\n"
            << "[7] Create provider directory report\n"
            << "[8] Load File to mark visits as paid" << endl;
 
        cin >> choice; cin.ignore(100,'\n');

       //Execute the code based on the choice 
        switch(choice){
            
            //Exits the manager terminal be setting choice to zero 
            case 0:
                choice = 0;
                break;
            //Displays all the providers via .csv file 
            case 1:
                manage_report.all_providers();
                break; 
            //Displays an individual provider via .csv file 
            case 2:
                to_id(id); 
                manage_report.individual_provider(id); 
                break; 
            //Displays all members via .csv file
            case 3:
                manage_report.all_members(); 
                break; 
            //Displays an individual member via .csv file 
            case 4:
                to_id(id);
                manage_report.individual_member(id); 
                break; 
            //Displays the account apyables information via .csv file 
            case 5:
                manage_report.ap_report(); 
                break;
            //Displays the electronic fund transfer via .csv file 
            //Creates 2 files 
            //Once approved AP, submit back to case 8, then mark paid 
            case 6: 
                manage_report.eft_report(); 
                break;
            //Displays the provider directory via .csv file 
            case 7:
                manage_report.provider_directory();
                break; 
            //Allign with case 6
            //Get's file that case 6 outputs
            case 8:
                to_report(report); 
                if(!manage_report.batch_mark_paid(report))
                    cout << "ERROR INVALID FILE" << endl;
                break;
            //Default when none of the cases are true
            default: /* ? */
                cout << "\nNo matches found, ERROR NUMBER: " << choice << endl;
                //system_error(errno, "No matches found", choice); 
                choice = 0; 
                break; 
        }
        
    } while(choice != 0);
    
    return;
}


#ifdef ERROR

void
to_report(string & a_report)
{
    ifstream file;
    //Exception handling in case the file is invalid
    try{

        cout << "\nPlease enter the name of the detailed eft report containing visits to be marked as paid: ";
        getline(cin , a_report); 

        if(a_report.empty() || !endswith(a_report,"_eft_detailed_report"))
            throw 0; 

        file.open(a_report+".csv");

        if(!file) 
            throw 's'; 

        file.close();
    }
    catch(int error)
    {
        cout << "\n ERROR: Invalid file name (File must be in following format YYYY-MM-DD_eft_detailed_report)" << endl; 
        to_report(a_report);
    }
    catch(char error)
    {
        cout << "\n ERROR: File does not exist" << endl;
        to_report(a_report);
    }

    return; 
}

void 
to_id(int & a_id)
{ 
    cadb obj;
    //Exception handling in case the ID is not valid 
    try{

        cout << "\nPlease enter the ID: ";
        cin >> a_id; //cin.ignore(100, '\n'); 

        if(!obj.getID("provider",to_string(a_id)) && !obj.getID("member", to_string(a_id)))
            throw a_id; 
    }
    catch(...){
        cout << "\nInvalid ID # format (Must Be 9 Digits) , ERROR NUMBER: " << a_id << endl;
        to_id(a_id); 
    }

    return;
}

#endif // ERROR

#endif // _MANAGER
