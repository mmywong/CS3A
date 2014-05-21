#include <iostream>
#include "string.h"
using namespace std;

int main()
{

    String s1;
    String s2;

    cout << "###testing cin###" << endl;
    cout << "s1 : ";
    cin >> s1;
    cout << endl << endl;
    cout << "###testing cout###" << endl;
    cout << "s1 again : " << s1 << endl << endl;

//    s2 = s1;
//    cout << "s2 : " << s2 << endl << endl;

    cout << "###testing StrLen###" << endl;
    cout << "strLen: " << s1.StrLen() << endl << endl;

    cout << "###testing StrCat###" << endl;
    s1.StrCat(" wong");
    cout << "strCat: " << s1 << endl << endl;

    cout << "###testing StrCpy###" << endl;
    s1.StrCpy("another name here");
    cout << "strCpy: " << s1<< endl << endl;

    cout << "###testing StrCmp###" << endl;
    cout << "s2 : ";
    cin >> s2;
    cout << "s1.StrCmp(s2) : ";
    int res = s1.StrCmp(s2);
    cout << res << endl << endl;

    cout << "###testing SubStr###" << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s3 = s1.SubStr(2,5); start pos: 2; length: 5;" << endl;
    String s3;
    s3 = s1.SubStr(2,5);
    cout << "s3 : " << s3 << endl << endl;

    return 0;
}

