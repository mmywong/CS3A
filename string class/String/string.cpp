#include "string.h"
#include <iostream>

using namespace std;

String::String()
{
    str = NULL;
}

String::String(char* text)
{
    str = text;
}

String::String(String &copythis)
{
    StrCpy(copythis);
}

const String &String::operator =(String &right)
{
    StrCpy(right);
}

String::~String()
{
    char* walker = str;
    while(*walker != '\0')
    {
        delete walker;
        walker++; // check this!
    }
    str = NULL;
}

istream& operator >>(istream &in, String &s)
{
    char temp[50];
    in >> temp;
    s.str = temp;
    return in;
}

ostream& operator <<(ostream &out, const String &s)
{
    out << s.str;
    return out;
}

int String::StrLen()
{
    int index = 0;
    while (*(str+index) != '\0')
         index++;
    return index;
}

void String::StrCpy(String source)
{
    int i = 0;
    char* walker = str;
    while(*(source.str))
      *walker++ = *source.str++;
    *walker = NULL;
}

void String::StrCat(String source)
{
//    char *temp = new char[50];
    String temp;
    int index;
    char* strhead = str;

    StrCpy(source); //copies one into the new array
    index = StrLen(); //
    str = str + index;
    StrCpy(source);
    str = strhead;
}

