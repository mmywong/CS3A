#include <iostream>
#include "date.h"

using namespace std;

int BusinessDays(date fromDate, date toDate);
int Weekends(date fromDate, date toDate);
date inXbusinessdays(date fromDate, int num);
bool isBusday(date d);
bool isWeekend(date d);

int main()
{
    int numofdays;
    date d1;
    date d2(4,5,2014);
    cout << "DEBUG: Total days d1 : " << d1.getTotaldays() << endl;
    cout << "DEBUG: Total days d2 : " << d2.getTotaldays() << endl;

    cout << "d1 : " << d1 << endl;
    cout << "d2 : " << d2 << endl;
    cout << "d2 + 6 : " << d2+6 << endl;
    cout << "DEBUG: Total days d2 : " << d2.getTotaldays() << endl;
    cout << "d2 - 3 : " << d2-3 << endl;
    cout << "DEBUG: Total days d2 : " << d2.getTotaldays() << endl;
    cout << "d2 - d1 : " << d2-d1 << endl;
    cout << "DEBUG: Total days d2 : " << d2.getTotaldays() << endl;
    cout << "d2 : " << d2 << endl;
    cout << "d2++ : " << d2++ << endl;
    cout << "DEBUG: Total days d2 : " << d2.getTotaldays() << endl;
    cout << "d2 now : " << d2 << endl;
    cout << "++d2 : " << ++d2 << endl;
    cout << "DEBUG: Total days d2 : " << d2.getTotaldays() << endl;
    cout << "d2 now : " << d2 << endl;

    cout << "-------------------------------------" << endl << endl;

    date d3(1,1,1900);
    date d4(4,4,2014);
    cout << "d3 : " << d3 << endl;
    cout << "d4 : " << d4 << endl;
    cout << "check to see if they are weekend : " << endl;
    cout << "d3 weekend? : " << isWeekend(d3) << endl;
    cout << "d4 weekend? : " << isWeekend(d4) << endl;
    cout << "check to see if they are business day: " << endl;
    cout << "d3 bus day? : " << isBusday(d3) << endl;
    cout << "d4 bus day? : " << isBusday(d4) << endl;


    return 0;
}

int BusinessDays(date fromDate, date toDate)
{
    int counter;
    date defdate(1,1,1900);     //setting first day (1/1/1900) as monday

    int from_nod = fromDate.total_nod();
    int to_nod = toDate.total_nod();
    while(from_nod != to_nod)
    {
        if(isBusday(fromDate) == true)
            counter++;
    fromDate++;
    from_nod++;
    }

    // first compare fromDate to first day (1/1/1900)
    // then compare toDate to first day to find out which day they are
    //with reference to monday, take difference and add those days

//    int totaldifference = (toDate - fromDate); //including weekends
//    if(totaldifference%7 <=5)

    return counter;
}

int Weekends(date fromDate, date toDate)
{
    int counter;
    date defdate(1,1,1900);     //setting first day (1/1/1900) as monday

    int from_nod = fromDate.total_nod();
    int to_nod = toDate.total_nod();
    while(from_nod != to_nod)
    {
        if(isWeekend(fromDate) == true)
            counter++;
    fromDate++;
    from_nod++;
    }
    return counter;
}

date inXbusinessdays(date fromDate, int num)
{
//    date defdate(1,1,1900);     //setting first day (1/1/1900) as monday
    int from_nod = fromDate.total_nod();
    while(num != 0)
    {
        if(isBusday(fromDate) == true) // if it's a business day
            num--;
        fromDate++;
    }
    return fromDate;
//    (fromDate-defdate)%7;  // tells us which day it is
}

bool isBusday(date d)
{
    if(((d.total_nod() % 7) < 5) && ((d.total_nod() % 7) >= 0))// weekday
        return true;
    else
        return false;
}

bool isWeekend(date d)
{
    if(((d.total_nod() % 7) == 5) || ((d.total_nod() % 7) == 6)) // weekend
        return true;
    else
        return false;
}
