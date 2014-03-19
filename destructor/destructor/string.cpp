#include "../../../../Dropbox/myheaderfiles/stringfx.h"
#include "string.h"

using namespace std;

String::String()
{
}

String::String(char* s)
{
    str = s;
    len = StrLen(str);
}

String::String(const String &CopyThis) // strcopy (copy constructor) (1)
{
    StrCpy(str, CopyThis.str);
}

String::~String() // (destructor) (2)
{
    if(str != NULL)
        delete [] str;
}

String &String::operator =(const String &rhs) // strcopy (assignment operator) (3)
{
    String temps;
    temps.len = rhs.len;
    temps.str = new char [temps.len];
    StrCpy(temps.str, rhs.str);
    return temps;
}

//---friend fx and operators---//
String operator +(const String &s1, const String& s2) // strcat
{
    String temp;
    temp.setLen(s1.getLen() + s2.getLen());
    temp.Set(s1.getStr());
    temp.Append(s2.getStr());
    return temp;
}

istream& operator >>(istream &ins, String &s)
{
    ins >> s.str;
    return ins;
}

ostream& operator <<(ostream &outs, const String &s) // print
{
    outs << s.str;
    return outs;
}

void String::Set(char *s) // strcopy
{
    str = new char [StrLen(s)];
    StrCpy(str,s);
}

void String::Append(const String &appendthis) // strcat
{
    StrCat(str,appendthis.str);
}

//---getters and setters for private vars---//
int String::getLen() const
{
    return len;
}

void String::setLen(int value)
{
    len = value;
}

char *String::getStr() const
{
    return str;
}

void String::setStr(char *value)
{
    str = value;
}

int String::StrLen(char *iPtr)
{
    return StrLen(iPtr);
}
