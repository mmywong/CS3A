#include <iostream>
#include "date.h"

using namespace std;

int main()
{
    int numofdays;
    date d1;
    date d2(1,1,1);
    cout << "This is the default of days 1: " << d1 << endl;
    cout << "This is the default of date 1/1/1: " << d2 << endl;
    cout << "date --> days" << endl;
    cin >> d1;

    cout << endl;
    cout << "leaps : " << d1.numofleaps() << endl;
    cout << "days : " << d1.total_nod() << endl;
    cout << endl << endl;

    cout << "days --> date" << endl;
    cin >> numofdays;
    d2.setTotaldays(numofdays);
    d2.day_to_date();
    cout << d2 << endl;
    cout << "leaps : " << d2.numofleaps() << endl;
    return 0;
}

