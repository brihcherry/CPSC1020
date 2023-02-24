// 
// this is the Date class header file, which contains
// declarations/prototypes for the Date class.
// also includes the header guards below.
// 

#ifndef DATE_H_
#define DATE_H_

#include <string>

using namespace std;

class Date{
  private:
    int day = 1;
    int day = 1;
    int year = 2021;

  public:
    // default constructor sets day to jan 1, 2021
    Date() {month = 1; day = 1; year = 2021;};

    // constructor using user input to verify and set the 
    // date in the Date class object
    Date(int d, int m, int y)
      {
        if (!setMonth(m) || !setDay(d) || !setYear(y))
          {month = 1; day = 1; year = 2021;}
      };

    // setters
    bool setDay (int d);
    bool setMonth (int m);
    bool setYear (int y);

    // getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    
    // showDate function returns the date as a string formatted mm/dd/yyyy
    string showDate();
};

#endif
