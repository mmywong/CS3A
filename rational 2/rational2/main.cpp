#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
    rational A(3,4);
    rational B(5,9);
    rational C;

    cout<<": ";
    cin >> A;
    cout<<": ";
    cin >> B;
    cout << endl;

    //display the fractions:
    cout << "rational 1: " << A << endl;
    cout << "rational 2: " << B << endl;
    cout << endl << endl;

    //addition
    C = A + B;
    cout << "A + B = " << C << endl;
    cout << endl << endl;

    //subtraction
    C = A - B;
    cout << "A - B = " << C << endl;
    cout << endl << endl;

    //multiplication
    C = A * B;
    cout << "A x B = " << C << endl;
    cout << endl << endl;

    //division
    C = A / B;
    cout << "A / B = " << C << endl;
    cout << endl << endl;

    //less than
    if(A < B)
        cout << "A < B" << endl << endl;
    else if(A > B)
        cout << "A > B" << endl << endl;
    else
        cout << "check if equal" << endl << endl;

    //equal
    if(A == B)
    {
        cout << "A = B" << endl;
        cout << A << " = " << B << endl << endl;
    }
    else
    {
        cout << "A != B" << endl;
        cout << A << " != " << B << endl << endl;
    }

    //negative
    A.neg();
    cout<<"-A: " << A << endl << endl;

    return 0;
}
