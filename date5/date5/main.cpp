#include <iostream>
#include <fstream>
#include "date.h"

using namespace std;

int main()
{
    /*
    date d1;
    ofstream fout("../date3/output.txt");
    date d2(1,1,1);
    cout << "This is the default of days d1: " << d1 << endl;
    cout << "This is the default of date d2: " << d2 << endl;
    */
    date d1, d2;
    int numofdays;
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
    cout << "leaps : " << d2.numofleaps() << endl << endl;
    cout <<"=========================================================";

    cout << endl << endl;
    cout << "#==== test ++ operators ====#" << endl;

    date d4(29,4,2014);
    cout << "current date : " << endl;
    cout << d4 << endl << endl;
    cout << "date++ : " << endl;
    d4++;
    cout << d4 << endl << endl;
    cout << "++date : " << endl;
    ++d4;
    cout << d4 << endl << endl << endl;

    cout << "#==== test 'date1 = date2 + int' ====#" << endl;
    date d5(29,4,2014);
    cout << "current date : " << endl;
    cout << d5 << endl << endl;
    cout << "making a new date : " << endl;
    date d6;
    cout << d6 << endl << endl;
    cout << "test newdate = olddate + 7" << endl;
    d6 = d5 + 7;
    cout << d6 << endl << endl;
    cout << "test newdate = olddate - 10" << endl;
    d6 = d5 - 10;
    cout << d6 << endl << endl;
    cout << "test daysbetween = d2 - d1" << endl;
    date date1(8,8,2013);
    date date2(16,8,2013);
    cout << "date 1 : " << date1 << endl;
    cout << "date 2 : " << date2 << endl;
    int daysbetween = date2 - date1;
    cout << "days between date 1 and date 2 : " << daysbetween << endl << endl;

    cout << "test cin, cout" << endl;
    cout << "cin date: ";
    date inputdate;
    cin >> inputdate;
    cout << "cout date: " << inputdate << endl << endl;

    //DEBUG TO FILE
//    int start,step;
//    cout << "Set the starting days to debug : "; cin >> start;
//    d1.setTotaldays(start);
//    d1.day_to_date();
//    cout << "How many days you want to go forward : "; cin >> step;
//    cout << "\nCheck output file for DEBUG\n";
//    for (int i = 0; i < step; ++i) {
//        fout << d1 << endl;
//        d1.setTotaldays(++start); //from 1 - 2 - 3
//        d1.day_to_date(); // convert totaldays(1) to 1/1/1
//    }
//    fout.close();
    return 0;
}

