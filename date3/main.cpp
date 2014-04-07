#include <iostream>
#include "date.h"

using namespace std;

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


//    cout << "This is the default: " << d1 << endl;

    /*
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
    cout << endl << endl;

    cout << ++d2 << endl;
    cout << ++d2 << endl;
    */
    return 0;
}

