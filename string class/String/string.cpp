#include "string.h"
#include <iostream>

using namespace std;

String::String()
{
    str = NULL;
}

String::String(int i)
{
    str = new char[i];
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
    String temp(50);
    int index;
    char* strhead = str;

    StrCpy(source); //copies one into the new array
    index = StrLen(); //
    str = str + index;
    StrCpy(source);
    str = strhead;
}

