#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <../../../../Dropbox/CS3A Assignments/stringlibrary/stringfx.h>

using namespace std;

//string combineletters(char new_letter1, char new_letter2, char new_letter3);
int stringtoint(char new_letter1, char new_letter2, char new_letter3);
string inttostring(int monthnum);

int main()
{
    string s;
    string x;
    char a,b,c;
    a = 'f';
    b = 'e';
    c = 'b';

    int value = stringtoint(a,b,c);
    cout<<value<<endl;


    int monthnum;
    cin>>monthnum;
    string newstr = inttostring(monthnum);
    cout<<newstr<<endl;

    return 0;
}

//string combineletters(char new_letter1, char new_letter2, char new_letter3)
//{
//    stringstream ss;
//    string s;
//    ss<<new_letter1<<new_letter2<<new_letter3;
//    ss>>s;
//    return s;
//}
int stringtoint(char new_letter1, char new_letter2, char new_letter3)
{
    stringstream ss;
    string monthname;
    ss<<new_letter1<<new_letter2<<new_letter3;
    ss>>monthname;

  string monthlist = "janfebmaraprmayjunjulaugsepoctnovdec";

  //converting string to char arrays:
  char monthnameA[5];
  char monthlistA[40];
  strcpy(monthnameA, monthname.c_str()); // c_str() creates a c-string pointer copy of the string
  strcpy(monthlistA, monthlist.c_str());

  int month = (FindStr(monthnameA, monthlistA, 0))/3 +1;
  return month;
}

string inttostring(int monthnum)
{
    string s;
    switch (monthnum)
    {
    case 1:
        s = "jan";
        break;
    case 2:
        s = "feb";
        break;
    default:
        break;
    }
    return s;
}
