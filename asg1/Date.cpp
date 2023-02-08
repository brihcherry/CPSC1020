// 
// This file contains definitions for the Date class. 
// 

#include <iostream>
#include <string>

#include "Date.h"

using namespace std;

// getter functions
int Date::getDay() const {return day;}
int Date::getMonth() const {return month;}
int Date::getYear() const {return year;}


// below are the setter functions:
// setDay, setMonth, and setYear all check if the input is valid
// if it is valid, they should set the day, month, or year variable
// to the user's input. If not, they simply return false and do not
// modify the variable.

bool Date::setDay (int d) {

    if (d > 0)
    {
        if (month == 2) 
        {
            if (d > 28) {return false;}
            else {day = d; return true;}
        }
        else if ( (month == 1) || (month == 3) || (month == 5) || (month == 7) ||
                  (month == 8) || (month == 10) || (month == 12) )
        {
            if (d > 31) {return false;}
            else {day = d; return true;}
        }
        else
        {
            if (d > 30) {return false;}
            else {day = d; return true;}
        }
    }
    else return false;

}


bool Date::setMonth(int m) {
    if (m >= 1 && m <= 12) {
        month = m;
        return true;
    }

    return false;
}


bool Date::setYear (int y) {
    if (y == 2021 || y == 2022) {
        year = y;
        return true;
    }
    return false;  
}


// the showDate function will print the date stored in 
// the Date class object as a string with correct formatting
string Date::showDate(){

    string dd, mm, yyyy, date;

    if (day < 10 )
        dd = '0'+ to_string(day);
    else 
        dd = to_string(day);

    if (month < 10 )
        mm = '0'+ to_string(month);
    else 
        mm = to_string(month);

    yyyy = to_string(year);

    date = mm + '/' + dd + '/' + yyyy;
    
    return date;

}