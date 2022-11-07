#include "structures.h"

// Implementation of class methods for Appointments

// Implementation of set_comment
bool appointments::set_comment(string comment)
{
    // Check to see if the comment length meets the constraints
    if(comment.length() > 100)
    {
        // Comment is too long
        return false;
    }
    else
    {
        // Comment meets the length
        this->comment = comment;
        return true;
    }
}

// Implementation of get_comment
string appointments::get_comment()
{
    // Return the comment
    return comment;
}