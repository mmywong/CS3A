#ifndef STRING_H
#define STRING_H
#include <iostream>

using namespace std;

class String
{
public:
    String();
    String(char *s);
    String(const String& CopyThis);
    ~String(); // destructor

    String& operator =(const String& rhs);

    friend ostream& operator <<(ostream& outs, const String& s);
    friend istream& operator >>(istream& ins, String& s);
    friend String operator +(const String& s1, const String s2); // concatenate : s3 = s1 + s2

    //---friend strfx---//
    friend void StrCpy(char *dest, char *source);
    friend void StrCat(char *&dest, char *source);

    void Set(char *s); // strcopy
    void Append(const String& appendthis); // s1.append(s2)

    //---getter and setter---//
    int getLen() const;
    void setLen(int value);

    char *getStr() const;
    void setStr(char *value);

private:
    int StrLen(char *iPtr);
    int len;
    char* str;
};

#endif // STRING_H
