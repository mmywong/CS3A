#include <iostream>
#include "month.h"

using namespace std;

int main()
{
    char L1 = 'j';
    char L2 = 'a';
    char L3 = 'n';
    int month = 1;
    char choice;
    char repeat = 'Y';


    Month testint;
    Month testchars;


    while (repeat == 'Y' || repeat == 'y')
    {
        cout << "1 : int to string" << endl;
        cout << "2 : string to int" << endl;
        cout << "3 : next month" << endl;
        cin >> choice;
        switch(choice)
        {
        case '1':
            cout << "month number : " << endl;
            cin >> month;
            testint.read(month);
            testint.printi(cout);
            cout << endl << endl;
            break;
        case '2':
            cout << "month name : " << endl;
            cin >> L1 >> L2 >> L3;
            testchars.read(L1,L2,L3);
            testchars.prints(cout);
            cout << endl << endl;
            break;
        case '3':
            cout << "current month : ";
            testint.printi(cout);
            cout << endl;
            cout << "current month 2 : ";
            testchars.prints(cout);
            cout<<endl;

            testint.next();
            testchars.next();
            testint.read(testint.getmonth());
            testchars.read(testchars.getmonth());

            cout << "next month : ";
            testint.printi(cout);
            cout << endl;
            cout << "next month 2: ";
            testchars.prints(cout);
            cout << endl;
            break;



        }
        cout << "repeat? Y:yes" << endl;
        cin >> repeat;
    }




    return 0;
}

