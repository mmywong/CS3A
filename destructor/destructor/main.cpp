#include <iostream>
#include "string.h"
using namespace std;

int main()
{
    String firstname, lastname, fullname;

    cout << "first name: ";
    cin >> firstname;
    cout << "last name: ";
    cin >> lastname;

    cout << "full name: ";
    firstname = (firstname + lastname);
    cout << firstname;

    cout << endl;
    return 0;
}

