#include <iostream>
#include "polyterm.h"
#include "polynomial.h"

using namespace std;

int main()
{
    polyterm p1, p2;
    cout << "input polyterm in format '2x^4' " << endl;
    cout << "p1 : ";
    cin >> p1;
    cout << "p2 : ";
    cin >> p2;
    cout << endl << endl;
    cout << "p1 : " << p1 << endl;
    cout << "p2 : " << p2 << endl;

    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p1 - p2 = " << p1 - p2 << endl;
    cout << "p1 * p2 = " << p1 * p2 << endl;
    cout << "(p1 == p2)? : " << (p1 == p2) << endl;
    cout << "(p1 < p2)? : " << (p1 < p2) << endl;
    cout << "(p1 > p2)? : " << (p1 > p2) << endl;

    cout << endl << endl;
//    cout << "================ polynomial ================" << endl;

//    polynomial polylist;

//    cout << "polylist : " << endl;
//    cout << "polylist + p1 = ";
//    polylist.InsertPoly(p1);
//    polylist.PrintPoly();
//    cout << endl;
    return 0;
}

