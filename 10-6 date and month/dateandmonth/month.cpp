#include "month.h"
#include "../../../CS3A Assignments/stringlibrary/stringfx.h" // for findstring function
#include <sstream> // for string stream, to convert char to string
#include <string> // for c_str()
#include <cstring> //for c_str()
#include <iostream>
#include <string.h> //for strcpy

Month::Month()
{
    month = 1;
    letter1 = 'j';
    letter2 = 'a';
    letter3 = 'n';
}

Month::Month(int monthnum)
{
    month = monthnum;
}

Month::Month(char new_letter1, char new_letter2, char new_letter3)
{
    letter1 = new_letter1;
    letter2 = new_letter2;
    letter3 = new_letter3;
}

void Month::read(int monthnum)
{
    month = monthnum;
    string s;
    s = inttostring(month);
    letter1 = s[0];
    letter2 = s[1];
    letter3 = s[2];
}

void Month::read(char new_letter1, char new_letter2, char new_letter3)
{
    letter1 = new_letter1;
    letter2 = new_letter2;
    letter3 = new_letter3;
    int i;
    i = stringtoint(new_letter1,new_letter2, new_letter3);
    month = i;
}

//string Month::combineletters(char new_letter1, char new_letter2, char new_letter3) //tested and working
//{
//    stringstream ss;
//    string s;
//    ss<<new_letter1<<new_letter2<<new_letter3;
//    ss>>s;
//    return s;
//}

string Month::inttostring(int monthnum)
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
    case 3:
        s = "mar";
        break;
    case 4:
        s = "apr";
        break;
    case 5:
        s = "may";
        break;
    case 6:
        s = "jun";
        break;
    case 7:
        s = "jul";
        break;
    case 8:
        s = "aug";
        break;
    case 9:
        s = "sep";
        break;
    case 10:
        s = "oct";
        break;
    case 11:
        s = "nov";
        break;
    case 12:
        s = "dec";
        break;
    default:
        break;
    }
    return s;
}

int Month::stringtoint(char new_letter1, char new_letter2, char new_letter3) //tested and working
{
    //--to concatenate 3 chars into 1 string--//
    stringstream ss;
    string monthname;
    ss<<new_letter1<<new_letter2<<new_letter3;
    ss>>monthname;

    //list of all the months in a year
    string monthlist = "janfebmaraprmayjunjulaugsepoctnovdec";

    //--converting string to char arrays so we can use FindStr--//
    char monthnameA[5];
    char monthlistA[40];
    strcpy(monthnameA, monthname.c_str()); // c_str() creates a c-string pointer copy of the string
    strcpy(monthlistA, monthlist.c_str());

    int month = (FindStr(monthnameA, monthlistA, 0))/3 +1; //formula to get the month number
    return month;
}

void Month::prints(ostream &outstring)
{
    int i;
    i = stringtoint(letter1,letter2,letter3);
    outstring << i;
}

void Month::printi(ostream &outint)
{
    string s;
    s = inttostring(month);
    outint << s;
}

Month Month::next()
{
     Month nextmonth;

     month += 1;
     nextmonth.read(month);
     return nextmonth;
}

int Month::getmonth()
{
    return month;
}
