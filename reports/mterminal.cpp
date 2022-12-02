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
        scrBrk();
        cout  << "Welcome to the Manager Terminal.\nPlease choose from the options below:" << endl;
        scrBrk();
        //The different options the manager terminal will carry out 
        cout  << "[0] Exit the manager terminal\n"
            << "[1] Create weekly report for all providers\n"
            << "[2] Create weekly report for an individual provider\n"
            << "[3] Create weekly report for all members\n"
            << "[4] Create weekly report for an individual member\n"
            << "[5] Create weekly accounts payable report\n"
            << "[6] Create weekly electronic fund transfer report\n"
            << "[7] Create provider directory report\n"
            << "[8] Update transaction payment status" << endl;
 
        choice = validateInputInteger();

       //Execute the code based on the choice 
        switch(choice){
            
            //Exits the manager terminal be setting choice to zero 
            case 0:
                choice = 0;
                break;
            //Displays all the providers via .csv file 
            case 1:
                if(manage_report.all_providers())
                    cout << "SUCCESS" << endl;
                break; 
            //Displays an individual provider via .csv file 
            case 2:
                to_id(id,1); 
                if(manage_report.individual_provider(id))
                    cout << "SUCCESS" << endl;
                break; 
            //Displays all members via .csv file
            case 3:
                if(manage_report.all_members())
                    cout << "SUCCESS" << endl;
                break; 
            //Displays an individual member via .csv file 
            case 4:
                to_id(id,2);
                if(manage_report.individual_member(id))
                    cout << "SUCCESS" << endl;
                break; 
            //Displays the account apyables information via .csv file 
            case 5:
                if(manage_report.ap_report())
                    cout << "SUCCESS" << endl;
                break;
            //Displays the electronic fund transfer via .csv file 
            //Creates 2 files 
            //Once approved AP, submit back to case 8, then mark paid 
            case 6: 
                if(manage_report.eft_report())
                    cout << "SUCCESS" << endl;
                break;
            //Displays the provider directory via .csv file 
            case 7:
                if(manage_report.provider_directory())
                    cout << "SUCCESS" << endl;
                break; 
            //Allign with case 6
            //Get's file that case 6 outputs
            case 8:
                update_payment_status(manage_report);
                cout << "SUCCESS" << endl;
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

void update_payment_status(management_report & obj)
{
    int choice = 0;
    string to_update = "";
    int tran_id = 0;
    scrBrk(); 
    cout  << "Welcome to the Manager Terminal.\nPlease choose from the options below:" << endl;
    scrBrk();
    cout << "Please Select From the Below Options: \n"
         << "[1] Update payment status to paid for individual transaction\n"
         << "[2] Update payment status to paid for multiple transactions via eft detailed report file\n"
         << "[3] Update payment status to unpaid for individual transaction\n"
         << "[4] Update payment status to unpaid for multiple transactions via eft detailed report file\n"
         << "[0] return to manager terminal\n";

    choice = validateInputInteger(); 

    switch(choice)
    {
        case 1: to_id(tran_id,3); 
                obj.mark_paid(tran_id, 1);
                return;
        case 2: to_report(to_update);
                if(!obj.batch_mark_paid(to_update))
                    cout << "ERROR: Invalid File" << endl;
                return;
        case 3: to_id(tran_id,3); 
                obj.mark_paid(tran_id,0);
                return;
        case 4: to_report(to_update);
                if(!obj.batch_mark_paid(to_update,0))
                    cout << "ERROR: Invalid File" << endl;
                return;
        case 0: 
        default: return; 
    }

    return; 
}

void
to_report(string & a_report)
{
    ifstream file;
    //Exception handling in case the file is invalid
    try{

        cout << "\nPlease enter the name of the detailed eft report containing visits to be marked as paid: ";
        cout << " >>> ";
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
to_id(int & a_id, int type)
{ 
    cadb obj;
    //Exception handling in case the ID is not valid 
    try{
        if(type == 3)
            cout << "\nPlease enter the 3 digit transaction ID ";
        else
            cout << "\nPlease enter the 9 digit member or provider ID ";
        a_id = validateInputInteger();
        if(type == 1 && !obj.getID("provider",to_string(a_id)))
            throw a_id;
        else if(type == 2 && !obj.getID("member", to_string(a_id))) 
            throw a_id;
        else if(type == 3 && !obj.findMatch("transaction", "id", to_string(a_id)))
            throw a_id; 
    }
    catch(...){
        if(type == 3)
            cout << "\nInvalid ID # format (Must Be 3 Digits) , ERROR NUMBER: " << a_id << endl;
        else
            cout << "\nInvalid ID # format (Must Be 9 Digits) , ERROR NUMBER: " << a_id << endl;
        to_id(a_id,type); 
    }

    return;
}


int validateInputInteger() {
    int num;
    cout << " >>> ";
    while(!(cin >> num)) {
        // Error message
        cout << "Invalid integer input. Try again.\n";
        // Clear previous input
        cin.clear();
        // Discard previous input
        cin.ignore(10000, '\n');
        cout << " >>> ";
    }
    cin.ignore(10000, '\n');
    return num;
}


#endif // ERROR

#endif // _MANAGER
