#include <iostream>
#include <string>
using namespace std;

struct appointments 
{
    public:
        // Variables
        string date;
        int provider_id;    
        int member_id;
        int service_id;

        // Class Methods
        bool set_comment(string comment);
        string get_comment();

    private:
        string comment;

    
};

struct provider 
{   
    // Variables
    string name;
    string street;
    string city;
    string state;
    string zip;
    int provider_id;
};

struct member 
{
    // Variables
    string name;
    string street;
    string city;
    string state;
    string zip;
    int member_id;
};