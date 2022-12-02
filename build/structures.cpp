#include "structures.h"
#include <sstream>

static cadb database;

// Implementations of class methods for visit

// This function will read in input from the user and set up the struct for use. A boolean will return
// true or false indicating whether or not the input was valid. For example, if the comment is too long,
// false is returned.
bool visit::read(const string in_date, const int in_provider_id, const int in_service_id, const int in_member_id, const string in_comment, const float in_fee)
{
    // Check to see if the comment length meets the constraints
    if(comment.length() > 100 || comment.empty() || in_date.empty() || in_date.length() || in_provider_id <= 1 || in_member_id <= 1 || in_service_id <= 1 || in_fee <= 0)
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
        // Everything checks outgit 
        this->date = in_date;
        this->provider_id = in_provider_id;
        this->member_id = in_member_id;
        this->service_id = in_service_id;
        this->fee = in_fee;
        this->comment = in_comment;
        return true;
    }
}

void visit::insert() 
{
    // void insertVisit(const string date, const int provider_id, const int service_id, const int member_id)
    
    // Convert datatypes
    // string p_number = to_string(provider_id);
    // string m_number = to_string(member_id);
    // string service_number = to_string(service_id);

    // Insert
    database.insertVisit(date, provider_id, service_id, member_id, comment);
}

// COMPARE NOT IMPLEMENTED YET FOR VISIT, ARE WE COMPARING SERVICE ID OR DATE? WHAT FORMAT IS DATE?

// Implementations of class methods for provider

// This function will read in input from the user and set up the struct for use. A boolean will return
// true or false indicating whether or not the input was valid.
bool provider::read(const string in_number, const string in_name, const string in_street, const string in_city, const string in_state, const string in_zip)
{
    if(in_number.length() != 9 || in_name.length() > 25 || in_street.length() > 25 || in_city.length() > 14 || in_state.length() > 2 || in_zip.length() > 5
        || in_number.empty() || in_name.empty() || in_street.empty() || in_city.empty() || in_state.empty() || in_zip.empty())
    {
        // Invalid input
        this->provider_number = "";
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
        this->provider_number = in_number;
        this->name = in_name;
        this->street = in_street;
        this->city = in_city;
        this->state = in_state;
        this->zip = in_zip;
        return true;
    }
}

void provider::insert()
{
    // void insertProvider(const string number, const string name, const string street, const string city, const string state, const string zip)
    
    // Insert
    database.insertProvider(provider_number, name, street, city, state, zip);
}

// Implementations of class methods for member

// This function will read in input from the user and set up the struct for use. A boolean will return
// true or false indicating whether or not the input was valid.
bool member::read(const string in_number, const string in_name, const string in_street, const string in_city, const string in_state, const string in_zip)
{
    if(in_number.length() != 9 || in_name.length() > 25 || in_street.length() > 25 || in_city.length() > 14 || in_state.length() > 2 || in_zip.length() > 5
        || in_number.empty() || in_name.empty() || in_street.empty() || in_city.empty() || in_state.empty() || in_zip.empty()) 
    {
        // Invalid input
        this->number = "";
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
        this->number = in_number;
        this->name = in_name;
        this->street = in_street;
        this->city = in_city;
        this->state = in_state;
        this->zip = in_zip;
        return true;
    }
}

void member::insert() 
{  
    // Insert
    database.insertMember(number, name, street, city, state, zip);
}

// Implementations of class methods for service

// This function will read in input from the user and set up the struct for use. A boolean will return
// true or false indicating whether or not the input was valid.
bool service::read(const string in_number, const string in_name, const float in_fee)
{
    if(in_number.length() != 6 || fee < 0) 
    {
        // Invalid input
        this->number = "";
        this->fee = 0;
        this->name = "";
        return false;
    }
    else 
    {
        // Everything checks out
        this->number = in_number;
        this->fee = in_fee;
        this->name = in_name;
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
  
    // Convert datatypes
    stringstream stream;
    stream << std::fixed << std::setprecision(2) << fee;
    string cost = stream.str();
    
    // Insert
    database.insertService(number, name, cost);
}
