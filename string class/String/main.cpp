#include <iostream>
#include "string.h"
using namespace std;

int main()
{

    String s1;
    String s2;

    cout << "s1 : ";
    cin >> s1;
    cout << "s1 again : " << s1 << endl;

    cout << "strLen: " << s1.StrLen() << endl;

    s1.StrCat(" wong");
    cout << "strCat: " << s1 << endl;

    s1.StrCpy("another name");
    cout << "strCpy: " << s1<< endl;

    return 0;
}

