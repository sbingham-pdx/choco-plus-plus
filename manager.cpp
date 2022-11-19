#ifndef _MAIN
# define _MAIN

//Include Steven's file to access provider struct 
#include "structures.h"
//#include "cadb.h"
//#include "reports.h"

using namespace std; 

//Function prototype
void display(provider_info);
bool info(int &, string &, string &, string &, string &, string &);

//Where the program begins 
int
main()
{
    int choice = 0;

        
    //Create an object of provider struct
    provider_info a_provider; 
    //provider_report a_provide_report; 
    //management_report a_report; 
    //accountant_report a_accountant; 
    string p_n, p_t, p_c, p_s, p_z;
    string to_create;               //This will create the file to write to 
    int p_id = 0;
    bool created = false; 
   // string to_create; 

    /*
    provider t_provider =
    {
        "Chocan",
        "Chocoland",
        "Portland",
        "Oregon",
        "97422",
        103302
    };
    cout<<t_provider.name<<t_provider.street<<t_privder.city<<t_provider.state
        <<t_provider.zip<<t_provider.provider_id << endl; 
    */

    do{
        cout  << "\n0 = Exit the manager terminal"
              << "\n1 = Enter provider information"
              << "\n2 = Display provider information"
              << "\n3 = Display AP report\n";
 
        cout << "\nPlease choose from the menu above: ";
        cin >> choice; cin.ignore(100,'\n');

        switch(choice){

            case 0:

                choice = 0;
                break;
            case 1:
                //info(p_id, p_n, p_t, p_c, p_s, p_z); 
                if(info(p_id, p_n, p_t, p_c, p_s, p_z)){
                    a_provider.read(p_id, p_n, p_t, p_c, p_s, p_z);
                }
                    //if(verify){
                        //cout << "\nSuccess";
                   // }
                   /*
                   if()
                // }
                created = true; 
                */ 
                break; 
            case 2:
                if(created){
                    display(a_provider);
                }
                break; 
            case 3:
            /*
                a_report(to_create);
                if(a_report.(to_create))
            */ 
            default: /* ? */
                cout << "\nNo matches found\n";
                break; 
        }
        
    } while(choice != 0); 


    return 1;
}

//Function definitions
void 
display(provider_info p)
{
   cout << "\n\tID: " << p.provider_id << "\tName : " << p.name << "\tStreet: " << p.street << "\tCity : " << p.city
        << "\tState: " << p.state << "\tZip: " << p.zip  
        << endl; 

}
bool 
info(int & p_ID, string & p_name, string & p_street, string & p_city, string & p_state, string & p_zip)
{

    cout << "\nPlease enter the provider's ID: ";
    cin >> p_ID; cin.ignore(100,'\n'); 

    cout << "\nPlease enter the provider's name: ";
    getline(cin, p_name); //cin.ignore(100,'\n'); 

    cout << "\nPlease enter the provider's street: ";
    getline(cin, p_street); //cin.ignore(100,'\n'); 

    cout << "\nPlease enter the provider's city: ";
    getline(cin, p_city); //cin.ignore(100,'\n'); 

    cout << "\nPlease enter the provider's state: ";
    getline(cin, p_state);// cin.ignore(100,'\n'); 

    cout << "\nPlease enter the provider's zip: ";
    getline(cin, p_zip); //cin.ignore(100,'\n');  

    return true; 
}

#endif //_MAIN
