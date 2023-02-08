//
// This file contains the function definition for the calcDays()
// function, which will take two dates and determine the number
// of days between them. It does this by finding the number of
// days between each date and 01/01/2021, then comparing the
// two differences. calcDays() will be used to determine if
// the user has been fully vaccinated within a given time frame.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#include "calcDays.h"
#include "Date.h"

int calcDays(const Date &date1, const Date &date2)
{
    int dayDiff1 = 0, 
        dayDiff2 = 0,
        i = 0, 
        j = 0;

    int d1 = date1.getDay(),
        m1 = date1.getMonth(),
        y1 = date1.getYear(),
        d2 = date2.getDay(),
        m2 = date2.getMonth(),
        y2 = date2.getYear();

    // static int monthLength[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    static int monthLength[] = { 0, 31, 28, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31 };

    // find dayDiff2, the number of days since jan 1 2021
    if (y1 == 2022)
        dayDiff1 = 365;

    while (i <= m1)
    {
        if (i == 0)
            {dayDiff1 += d1;}
        else 
            {dayDiff1 += monthLength[m1-i];}
        i++;
    }

    // find dayDiff2, the number of days since jan 1 2021
    if (y2 == 2022)
        dayDiff2 = 365;

    while (j <= m2)
    {
        if (j == 0)
            {dayDiff2 += d2;}
        else 
            {dayDiff2 += monthLength[m2-j];}
        j++;
    }

    // debugging statements
    // cout << "dayDiff1 contains " << dayDiff1 << endl;
    // cout << "dayDiff2 contains " << dayDiff2 << endl;
    // cout << "difference is " << dayDiff2-dayDiff1 << endl;

    return (dayDiff2-dayDiff1);
}

