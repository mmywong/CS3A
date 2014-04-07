#include "date.h"

date::date()
{
    totaldays = 1;
    day_to_date();
}

date::date(int total_days)
{
    totaldays = total_days;

}

date::date(int new_day, int new_month, int new_year)
{
    day = new_day;
    month = new_month;
    year = new_year;
}

//wrong function
//date date::operator +(const date &d1, const date &d2)
//{
//    date result;
//    result.totaldays = d1.totaldays + d2.totaldays;
//    result.day_to_date();
//    return result;
//}

date operator +(date &d1, int num)
{
    d1.totaldays = d1.total_nod();
    d1.totaldays += num;
    cout << d1.totaldays << endl;
    d1.day_to_date();
    return d1;
}

int operator -(const date &d1, const date &d2)
{
    if((d1.totaldays - d2.totaldays) < 0) // means that difference is negative
        cout << "error. the first date is behind the second date";

    int result;
    result = d1.totaldays - d2.totaldays;
    return result;
}

date operator -(date &d1, int num)
{
    d1.totaldays -= num;
    d1.day_to_date();
    return d1;
}

date& operator ++(date& d1) // prefix
{
    // date to days, then days++, then days to date
    d1.totaldays = d1.total_nod();
    d1.totaldays += 1;
    d1.day_to_date();
    return d1;
}

date operator ++(date& d1, int) //postfix
{
    date temp;
    temp = d1;
    d1.totaldays = d1.total_nod();
    d1.totaldays += 1;
    d1.day_to_date();
    return temp;
}

//---  date --> days  ---//     (includes only first day, not the last day)
int date::nod_years()
{
    int leapyears;
    leapyears = numofleaps();
    return (365*(year-1) + leapyears);
}

int date::nod_months()
{
    if(leapyear(year) == true)
        return monthA[month-1];
    else
        return monthA_leap[month-1];
}

int date::total_nod() // date --> days
{
    totaldays = (nod_years() + nod_months() + day); // total number of days INCLUDING today
    return totaldays;
}

//---  days --> date  ---// (includes first and last day)
void date::day_to_date()
{
    day = 0;
    month = 0;
    year = 1;
    int leaps = 0;
    while(totaldays >= (365 + leapyear(year)))
    {
        totaldays -= 365;
        if(leapyear(year) == true)
            totaldays--; // subtract 1 day if that year has 366 days
        year++;
    }

    if(leapyear(year) == true)
    {
        while(totaldays > monthA_leap[month])
            month++;
        totaldays -= monthA_leap[month-1];
    }
    else
    {
        while(totaldays > monthA[month])
            month++;
        totaldays -= monthA[month-1];
    }

    day = totaldays; //including first and last day
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
    out<<date3.day<<"/"<<date3.month<<"/"<<date3.year;
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





