#include <iostream>
#include <string>
using namespace std;

struct p_service 
{
    // Variables
    string sdate;
    string rdate;
    string mname;
    int mnumber;
    int service_code;
    float fee;

    // Class Methods
    float display();
    float write(ostream &);
    void read(string &, string &, string &, int, int, float);
    bool operator<(p_service &);
    bool compare(p_service &);
};

struct provider 
{   
    // Variables
    string name;
    int scount;
    int number;

    // Class Methods
    float display(char, int &);
    float write(char, ostream &, int &);
    void read(string &, int, int, float);
};

struct service
{
    // Variables
    string date;
    string service_name;
    string provider;

    // Class Methods
    void display();
    void write(ostream &);
    void read(string &, string &, string &);
    bool operator<(service &);
    bool compare(service &);
};