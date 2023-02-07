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
    int dayDiff1 = 365 * (date1.getYear() - 2021) + 31 * (date1.getMonth() - 1) + (date1.getDay() - 1);
    int dayDiff2 = 365 * (date2.getYear() - 2021) + 31 * (date2.getMonth() - 1) + (date2.getDay() - 1);

    for (int i = date1.getMonth(); i < date2.getMonth(); i++)
    {
        if (i == 2) 
            {dayDiff1 -= 3;}
        else if (i == 4 || i == 6 || i == 9 || i == 11)
            {dayDiff1 -= 1;}
    }

    return abs(dayDiff2 - dayDiff1);
}


