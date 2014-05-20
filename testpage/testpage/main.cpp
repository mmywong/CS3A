#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
//#include <../../../../Dropbox/CS3A Assignments/stringlibrary/stringfx.h>

using namespace std;

int main()
{
    //two ways to use string.

    //1
    string s;
    cin >> s;
    cout << "s : " << s;

    //2
    string s1("hello");
    cout << "s1 : " << s1;

    string s2(s1);
    cout << "s2 : " << s2;

    return 0;
}
