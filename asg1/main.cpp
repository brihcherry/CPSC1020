// 
// BRIANNA CHERRY
//
// cpsc1020 project 1: covid self-assessment checker
// expected time to code: 7 hours
// actual time to code: probably about 10 hours
//
// DESCRIPTION:
// This program will ask a series of questions to get input from the
// user, then decide if and how long the user should isolate
// based on their answers. This file contains the main function that 
// drives the program. It takes input and stores information in the Date
// class, and also calls Date class functions and the calcDays function
// as necessary. Then, main prints the result to the user.
//
//


#include <iostream>
#include <string>

#include "Date.h"
#include "calcDays.h"

using namespace std;


int main()
{

    // initalize some variables that will be used by main
    int category, isolationTime,
        m1 = 1, d1 = 1, y1 = 3,
        m2 = 1, d2 = 1, y2 = 3,
        m3 = 1, d3 = 1, y3 = 3;

    // Date testDay, vaccination, exposureDate;

    // get first input
    bool testResult;
    cout << "What was your test result?\n1 - positive\n0 - negative\n"; cin >> testResult;


    // the conditional statements below will determine which types of input
    // to gather from the user. 
    if (testResult){
        cout << "Enter the date you tested positive." << endl;
        cout << "Month: "; cin >> m1;
        cout << "Day: "; cin >> d1;
        cout << "Year: "; cin >> y1;
        // categorize the result so that the correct output can be chosen
        isolationTime = 5;
        category = 1;
    }
    else{
        bool exposed;
        cout << "Were you exposed to a positive case?" << endl << "1 - yes\n0 - no\n";
        cin >> exposed;



        if (exposed){
            cout << "Enter the date you were exposed"<< endl;
            cout << "Month: "; cin >> m3;
            cout << "Day: "; cin >> d3;
            cout << "Year: "; cin >> y3;
    
            bool vaccinated;
            cout << "Second vaccination dose received?\n1 - yes\n0 - no" << endl;
            cin >> vaccinated;

            if (vaccinated){
                cout << "Enter the date you received the second dose of the vaccine:"<< endl;
                cout << "Month: "; cin >> m2;
                cout << "Day: "; cin >> d2;
                cout << "Year: "; cin >> y2;
                // categorize the result so that the correct output can be chosen
                category = 3;
            }
            else{
                // categorize the result so that the correct output can be chosen
                isolationTime = 10;
                category = 5;
            }
            
        }
        else{
            // categorize the result so that the correct output can be chosen
            isolationTime = 0;
            category = 2;
        }

    }

    // create Date objects; not all of these will be used, depending on 
    // what the user input was. but they must all be declared in order for
    // the code above to run.

    // testDay.setMonth(m1);  
    // testDay.setDay(d1);  
    // testDay.setYear(y1);

    // vaccination.setMonth(m1);  
    // vaccination.setDay(d1);  
    // vaccination.setYear(y1);

    // exposureDate.setMonth(m1);  
    // exposureDate.setDay(d1);  
    // exposureDate.setYear(y1);

    Date testDay(m1, d1, y1);
    Date vaccination(m2, d2, y2);
    Date exposureDate(m3, d3, y3);

    //
    if (category == 3){
        if (calcDays(vaccination, exposureDate) >= 14){
            // categorize the result so that the correct output can be chosen
            isolationTime = 5;
        }
        else{
            // categorize the result so that the correct output can be chosen
            isolationTime = 10;                
            category = 4;
        }
    }

    // use the categorization determined by the above if statements
    // to determine which output to display to the user.
    if (category == 1){
        cout << endl << "Test result: positive" << endl;
        cout << "Date tested positive: " << testDay.showDate() << endl;
    }
    else if (category == 2){
        cout << endl << "Test result: negative" << endl;
        cout << "Exposed to positive case: No" << endl;
    }
    else if (category == 3){
        cout << endl << "Test result: negative" << endl;
        cout << "Exposed to positive case: Yes" << endl;
        cout << "Date exposed to positive case: " << exposureDate.showDate() << endl;
        cout << "Second vaccination dose received: Yes" << endl;
        cout << "Date second vaccination dose received: " << vaccination.showDate() << endl;
        cout << "Vaccination status at time of exposure: fully vaccinated" << endl;
    }
    else if (category == 4){
        cout << endl << "Test result: negative" << endl;
        cout << "Exposed to positive case: Yes" << endl;
        cout << "Date exposed to positive case: " << exposureDate.showDate() << endl;
        cout << "Second vaccination dose received: Yes" << endl;
        cout << "Date second vaccination dose received: " << vaccination.showDate() << endl;
        cout << "Vaccination status at time of exposure: not fully vaccinated" << endl;
    }
    else if (category == 5){
        cout << endl << "Test result: negative" << endl;
        cout << "Exposed to positive case: Yes" << endl;
        cout << "Date exposed to positive case: " << exposureDate.showDate() << endl;
        cout << "Second vaccination dose received: No" << endl;
        cout << "Vaccination status at time of exposure: not fully vaccinated" << endl;
    }

    cout << "Length of isolation: " << isolationTime << " days" << endl << endl;

    return 0;
}


