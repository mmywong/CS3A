#include <iostream>
#include <fstream>
#include "date.h"

using namespace std;

int main()
{
    /*
    int numofdays;
    date d1;
    ofstream fout("../date3/output.txt");
    date d2(1,1,1);
    cout << "This is the default of days d1: " << d1 << endl;
    cout << "This is the default of date d2: " << d2 << endl;
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
    */

    cout << endl << endl;
    cout << "#==== test operators ====#" << endl;
    date d3;
    cin >> d3;
    cout << d3;
    cout << "date++ : " << endl;
    d3++;
    cout << d3 << endl << endl;
    cout << "++date : " << endl;
    ++d3;
    cout << d3 << endl;




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

