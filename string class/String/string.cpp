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

//String::String(String copythis)
//{
//    StrCpy(copythis);
//}

String &String::operator =(const String &right)
{
    StrCpy(right);
    return *this;
}

String::~String()
{
    delete [] str;
//    char* walker = str;
//    while(*walker != '\0')
//    {
//        delete walker;
//        walker++; // check this!
//    }
//    str = NULL;
// tombstone method...? need to read more on this
//    char* walker = str;
//    str = NULL;
//    delete str;
}

istream& operator >>(istream &in, String &s)
{
    char* temp = new char[100];
    cin.getline(temp,100);
    /*
    int index = 0;
    while (*(temp+index) != '\0')
         index++;
    *(temp + index) = '\0';*/
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
    return StrLen(str);
}

int String::StrLen(char *source)
{
    if(str == NULL)
        return 0;
    int index = 0;
    while (*(source+index) != '\0')
         index++;
    return index;
}

void String::StrCpy(String source)
{
    StrCpy(source.str);
}

void String::StrCpy(char *source)
{
    str = new char[100];
    char* walker = str;
    while(*source)
      *walker++ = *source++;
    *walker = NULL;
}

void String::StrCat(String source)
{
    StrCat(source.str);
}

void String::StrCat(char *source)
{
    if(str == NULL)
        StrCpy(source);
    else
    {
        char* temp = new char[100];
        char* tempwalker = temp;
        int length = StrLen();
        int counter = 0;
        while(counter++ < length) // first loop copies first part into temp array
            *tempwalker++ = *str++;
        counter = 0;
        int length2 = StrLen(source);
        while(counter++ < length2) // second loop copies second part into temp array
            *tempwalker++ = *source++;
        *tempwalker = NULL;
        str = temp;
//        delete [] temp;
    }
}

int String::StrCmp(String comparethis)
{
    char* walker = str;
    char* cwalker = comparethis.str;
    do
    {
        if(*walker == *cwalker)
        {
            walker++;
            cwalker++;
        }
        else if(*walker > *cwalker)
            return 1;
        else
            return -1;

    }while(*walker != NULL || *cwalker != NULL);
}

String String::SubStr(int start, int length)
{
    char* substring = new char[100];
    char* subwalker = substring;
    char* walker = str + start;
    for(int i = 0; i < length; i++)
        *subwalker++ = *walker++;
    *subwalker = NULL;
    String substr(substring);
    return substr;
}

