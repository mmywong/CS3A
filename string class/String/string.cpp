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
        walker++;
    }

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
