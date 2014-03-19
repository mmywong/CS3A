#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
    // random default rationals which will be replaced by input values
    rational A(3,4);
    rational B(5,9);
    rational C;

    cout<<": ";
    A.input(cin);
    cout<<": ";
    B.input(cin);
    cout << endl;

    //display the fractions:
    cout<<"rational 1: ";
    A.output(cout);
    cout<<endl;
    cout<<"rational 2: ";
    B.output(cout);
    cout<<endl << endl;

    //addition
    A.output(cout);
    cout<<" + ";
    B.output(cout);
    cout<<" = ";
    C = A.add(B);
    C.output(cout);
    cout << endl << endl;

    //subtraction
    A.output(cout);
    cout<<" - ";
    B.output(cout);
    cout<<" = ";
    C = A.sub(B);
    C.output(cout);
    cout << endl << endl;

    //multiplication
    A.output(cout);
    cout<<" x ";
    B.output(cout);
    cout<<" = ";
    C = A.mul(B);
    C.output(cout);
    cout << endl << endl;

    //division
    cout<<"(";
    A.output(cout);
    cout<<") / (";
    B.output(cout);
    cout<<") = ";
    C = A.add(B);
    C.output(cout);
    cout << endl << endl;

    //less than
    if(A.less(B) == true)
    {
        A.output(cout);
        cout<<" < ";
        B.output(cout);
        cout<<endl<<endl;
    }
    else if(B.less(A) == true)
    {
        A.output(cout);
        cout<<" > ";
        B.output(cout);
        cout<<endl<<endl;
    }
    else
        cout << "check if equal" << endl << endl;


    //equal
    if(A.equal(B) == true)
    {
        A.output(cout);
        cout<<" = ";
        B.output(cout);
        cout<<endl<<endl;
    }
    else
    {
        A.output(cout);
        cout<<" != ";
        B.output(cout);
        cout << endl << endl;
    }


    //negative
    cout<<"-A: ";
    A.neg();
    A.output(cout);
    cout << endl << endl;
    return 0;
}




/*void Demo(rational &R1, rational &R2)
{
    rational result;
    char choice;
    choice = 'A';
    while (choice == 'A' || choice == 'B')
    {
        cout<<"A : ";
        A.print(cout);
        cout<<endl;
        cout<<"B : ";
        B.print(cout);

        result = A.Add(B);
        A.print(cout);
        cout << " + ";
        B.print(cout);
        cout << " = ";
        result.print(cout);
        cout << endl;

        result = A.Sub(B);
        A.print(cout);
        cout << " - ";
        B.print(cout);
        cout << " = ";
        result.print(cout);
        cout << endl;

        result = A.Mul(B);
        A.print(cout);
        cout << " x ";
        B.print(cout);
        cout << " = ";
        result.print(cout);
        cout << endl;

        result = A.Div(B);
        A.print(cout);
        cout << " / ";
        B.print(cout);
        cout << " = ";
        result.print(cout);
        cout << endl;

        cout << endl;
        cout << "which letter do you want to change?" << endl;
        cin >> choice;

        switch(choice)
        {
            case 'A':
            case 'a':
            A.input(cin);
            break;

            case 'B':
            case 'b':
            B.input(cin);
            break;
        }

    }
}*/
