#include <iostream>
#include "counter.h"
#include <stdlib.h>

using namespace std;

int main()
{
    counter A;
    char manipulator;
    manipulator = '0';

    cout<<"'0-9' sets a new int"<<endl;
    cout<<"'a' : add"<<endl;
    cout<<"'s' : subtract"<<endl;
    cout<<endl;

    while(manipulator)
    {
        switch (manipulator)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            A.set(manipulator - 48);
            break;
        case 'a':
            A.increase();
            A.print(cout);
            cout<<endl;
            break;
        case 's':
            A.decrease();
            A.print(cout);
            cout<<endl;
            break;
        default :
            A.print(cout);
            cout<<endl;
            break;
        }
        cin>>manipulator;
    }

    cout << "Hello World!" << endl;
    return 0;
}

