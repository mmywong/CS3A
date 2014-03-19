#include "date.h"

date::date()
{
    totaldays = 1;
    day_to_date();
}

date::date(int new_day, int new_month, int new_year)
{
    day = new_day;
    month = new_month;
    year = new_year;
    totaldays = total_nod();
}

//---  date --> days  ---//
int date::nod_years()
{
    int leapyears;
    leapyears = numofleaps();
    return (365*(year-1) + leapyears);
}

int date::nod_months()
{
    if(leapyear(year) == true)
        return monthA_leap[month-1];
    else
        return monthA[month-1];
}

int date::total_nod() // date --> days
{
    // Note: Counting days up to current year is already working
    // BUG : Reducing not leap year by the end of the year, instead of after february
    // FIXED : line 28 , first should be monthA_leap instead of monthA
    totaldays = (nod_years() + nod_months() + day); // total number of days INCLUDING today
    return totaldays;
}

//---  days --> date  ---//
void date::day_to_date()
{
    int temp_days = totaldays; // i dont want to change totaldays
    day = 1;
    month = 1;
    year = 1;
    while(temp_days > (365 + leapyear(year))) {
        temp_days -= 365;
        if(leapyear(year) == true)
            temp_days--; // subtract 1 day if that year has 366 days
        year++;
    }
//    temp_days--; //why - 1 here?

    if(leapyear(year) == true) {
        while(temp_days > monthA_leap[month])
            month++;
        temp_days -= monthA_leap[month-1];
    }
    else {
        while(temp_days > monthA[month])
            month++;
        temp_days -= monthA[month-1];
    }
    day = temp_days;
}


//--- leaps ---//
bool date::leapyear(int year_num)
{
    if((year_num%400 == 0) || ((year_num%4 == 0)&&(year_num%100 != 0)))
        return true;
    else
        return false;
}

int date::countdaysinyear() //not really used
{
    if (leapyear(year) == true)
        return 366;
    else
        return 365;
}

int date::numofleaps()
{
    int counter=0;
    for(int i=1; i<year; i++)
        if(leapyear(i) == true)
            counter++;
    // because we want to count number of days until that year, subtract 1 year (that year)
    return counter;
}

//---input and output---//
istream& operator >>(istream &in, date &date1)
{
    char slash;
    in>>date1.day>>slash>>date1.month>>slash>>date1.year;
    return in;
}

ostream& operator <<(ostream &out, const date &date3)
{
    out<<date3.day<<"/"<<date3.month<<"/"<<date3.year << " ,days : " << date3.totaldays;
    return out;
}

//---setters and getters---//
int date::getTotaldays() const
{
    return totaldays;
}
void date::setTotaldays(int value)
{
    totaldays = value;
}
int date::getDay() const
{
    return day;
}
void date::setDay(int value)
{
    day = value;
}
int date::getMonth() const
{
    return month;
}
void date::setMonth(int value)
{
    month = value;
}
int date::getYear() const
{
    return year;
}
void date::setYear(int value)
{
    year = value;
}





