#include <iostream>
#include <string>
using namespace std;

struct visit 
{
    // Variables
    string date;
    int provider_id;    
    int member_id;
    int service_id;
    float fee;
    string comment;

    // Class Methods
    bool read(const string date, const int provider_id, const int service_id, const int member_id, const string comment, const float fee);
    bool operator<(visit & operand);
    bool compare(visit & operand);
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

    // Class Methods
    bool read(const int id, const string name, const string street, const string city, const string state, const string zip);
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

    // Class Methods
    bool read(const int id, const string name, const string street, const string city, const string state, const string zip);
};

struct service
{
    // Variables
    int number;
    string name;
    float fee;

    // Class Methods
    bool read(const int number, const string name, const float fee);
    bool operator<(service & operand);
};