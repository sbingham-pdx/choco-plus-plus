#include "structures.h"

// Implementations of class methods for visit

// This function will read in input from the user and set up the struct for use. A boolean will return
// true or false indicating whether or not the input was valid. For example, if the comment is too long,
// false is returned.
bool visit::read(const string date, const int provider_id, const int service_id, const int member_id, const string comment, const float fee)
{
    // Check to see if the comment length meets the constraints
    if(comment.length() > 100 || provider_id < 0 || member_id < 0 || service_id < 0 || fee < 0)
    {
        // Invalid input
        this->date = "00-00-0000";
        this->provider_id = 0;
        this->member_id = 0;
        this->service_id = 0;
        this->fee = 0;
        this->comment = "";
        return false;
    }
    else
    {
        // Everything checks out
        this->date = date;
        this->provider_id = provider_id;
        this->member_id = member_id;
        this->service_id = service_id;
        this->fee = fee;
        this->comment = comment;
        return true;
    }
}

void visit::insert() 
{
    // void insertVisit(const string date, const int provider_id, const int service_id, const int member_id)
    
    // Convert datatypes
    string p_number = to_string(provider_id);
    string m_number = to_string(member_id);
    string service_number = to_string(service_id);
    
    // Insert
    insertProvider(date, p_number, service_number, m_number);
}

// COMPARE NOT IMPLEMENTED YET FOR VISIT, ARE WE COMPARING SERVICE ID OR DATE? WHAT FORMAT IS DATE?

// Implementations of class methods for provider

// This function will read in input from the user and set up the struct for use. A boolean will return
// true or false indicating whether or not the input was valid.
bool provider::read(const int id, const string name, const string street, const string city, const string state, const string zip)
{
    if(id < 0) 
    {
        // Invalid input
        this->provider_id = 0;
        this->name = "";
        this->street = "";
        this->city = "";
        this->state = "";
        this->zip = "";
        return false;
    }
    else 
    {
        // Everything checks out
        this->provider_id = id;
        this->name = name;
        this->street = street;
        this->city = city;
        this->state = state;
        this->zip = zip;
        return true;
    }
}

void provider::insert()
{
    // void insertProvider(const string number, const string name, const string street, const string city, const string state, const string zip)
    
    // Convert datatypes
    string number = to_string(provider_id);
    
    // Insert
    insertProvider(number, name, street, city, state, zip);
}

// Implementations of class methods for member

// This function will read in input from the user and set up the struct for use. A boolean will return
// true or false indicating whether or not the input was valid.
bool member::read(const int id, const string name, const string street, const string city, const string state, const string zip)
{
    if(id < 0) 
    {
        // Invalid input
        this->member_id = 0;
        this->name = "";
        this->street = "";
        this->city = "";
        this->state = "";
        this->zip = "";
        return false;
    }
    else 
    {
        // Everything checks out
        this->member_id = id;
        this->name = name;
        this->street = street;
        this->city = city;
        this->state = state;
        this->zip = zip;
        return true;
    }
}

void member::insert() 
{
    // void insertMember(const string number, const string name, const string street, const string city, const string state, const string zip)
    
    // Convert datatypes
    string number = to_string(member_id);
    
    // Insert
    insertProvider(number, name, street, city, state, zip);
}

// Implementations of class methods for service

// This function will read in input from the user and set up the struct for use. A boolean will return
// true or false indicating whether or not the input was valid.
bool service::read(const int number, const string name, const float fee)
{
    if(number < 0 || fee < 0) 
    {
        // Invalid input
        this->number = 0;
        this->fee = 0;
        this->name = "";
        return false;
    }
    else 
    {
        // Everything checks out
        this->number = number;
        this->fee = fee;
        this->name = name;
        return false;
        return true;
    }

    
}

// Compare services by their service number
bool service::operator<(service & operand)
{
    return number < operand.number;
}

void service::insert()
{
    // void insertService(const string number, const string name, const string cost)
    
    // Convert datatypes
    string service_number = to_string(number);
    string cost = to_string(fee);
    
    // Insert
    insertProvider(service_number, name, cost);
}