#ifndef DATE_H
#define DATE_H
#include <iostream>

using namespace std;

class date
{
public:
    date();
    date(int new_day, int new_month, int new_year);

    //---friend functions---//
    friend date operator +(const date& d1,const date& d2);
    friend date operator +(const date& d1, int num);
    friend date operator -(const date& d1, const date& d2);
    friend date operator -(const date& d1, int num);
    friend date operator ++(const date& d1);

    //---date --> days functions---//
    // everythoming with ref to day 0
    int nod_years(); // number of days between years
    int nod_months();
    int total_nod();

    //---days --> date functions---//
    void day_to_date();


    //---dealing with leap years---//
    bool leapyear(int year_num);
    int countdaysinyear(); // not really used
    int numofleaps(); // with ref to day 0

    //---input and output---//
    friend istream& operator >>(istream& in, date& date1); // ok
    friend ostream& operator <<(ostream& out, const date& date3); // ok

    //---setters and getters---//
    int getTotaldays() const;
    void setTotaldays(int value);
    int getDay() const;
    void setDay(int value);
    int getMonth() const;
    void setMonth(int value);
    int getYear() const;
    void setYear(int value);

private:
    int totaldays; //start from 1 , "please do not change this inside function" - By: Tony
    int day; //day here start fr 1
    int month; //month here start from 1 as january
    int year; //start from 1

    //number of days from Jan 1 to the beginning of that month
    int monthA[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365}; // last element is not used
    int monthA_leap[13] = {0,31,60,91,121,152,182,213,244,274,305,335,366}; // last element is not used
};

#endif // DATE_H
