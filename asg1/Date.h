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
  int day, month, year;

  public:
  Date();
  Date(int m, int d, int y);
  bool setDay (int d);
  bool setMonth (int m);
  bool setYear (int y);
  int getDay() const;
  int getMonth() const;
  int getYear() const;
  string showDate();
};

#endif
