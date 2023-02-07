// 
// This file contains definitions for the Date class. 
// 

#include <iostream>
#include <string>

#include "Date.h"

using namespace std;

// default constructor sets date to 01/01/2021
Date::Date() {
    month = 1;
    day = 1;
    year = 2021;
    }

// this constructor defines month, day, and year based 
// on the user's input. It uses the setter fuctions to 
// verify that valid numbers have been entered. if not, 
// the default constructor is used.
Date::Date(int m, int d, int y){

    if ( !(setMonth(m) && setDay(d) && setYear(y)) )
    {
        day = 1;
        month = 1; 
        year = 2021;
    }

}

// getter functions
int Date::getDay() const {return day;}

int Date::getMonth() const {return month;}

int Date::getYear() const {return year;}

// below are the setter functions:
// setDay, setMonth, and setYear all check if the input is valid
bool Date::setDay (int d) {
    bool valid = true;

    if (d > 0 && d <= 31) 
    {
        if (month == 1 || (month >= 3 && month <= 12)) 
            {day = d;} 
        else if (month == 2 && d <= 28) 
            {day = d;} 
        else if (month == 2 && d > 28)
            {valid = false;}
        else {valid = false;}
    } 
    else {valid = false;}

    if (!valid) {Date();}
    else {}

    return valid;
}

bool Date::setMonth(int m) {
    bool valid = true;

    if (m >= 1 && m <= 12) 
        {month = m;} 
    else {valid = false;}

    return valid;
}

bool Date::setYear (int y) {
    bool valid = false;

    if (y == 2021 || y == 2022) {
        valid = true;
        year = y;
    }

    return valid;  
}


// the showDate function will print the date stored in 
// the Date class object as a string with correct formatting
string Date::showDate(){

    //cout << "in showDay day is " << day << endl;

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