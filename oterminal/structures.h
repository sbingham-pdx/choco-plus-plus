#include <iostream>
#include <string>
#include "reports.h"
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
    void insert();
};

struct provider 
{   
    // Variables
    string name;
    string street;
    string city;
    string state;
    string zip;
    string provider_number;

    // Class Methods
    bool read(const string number, const string name, const string street, const string city, const string state, const string zip);
    void insert();
};

struct member
{
    // Variables
    string name;
    string street;
    string city;
    string state;
    string zip;
    string number;

    // Class Methods
    bool read(const string number, const string name, const string street, const string city, const string state, const string zip);
    void insert();
};

struct service
{
    // Variables
    string number;
    string name;
    float fee;

    // Class Methods
    bool read(const string number, const string name, const float fee);
    bool operator<(service & operand);
    void insert();
};
