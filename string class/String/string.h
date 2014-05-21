#ifndef STRING_H
#define STRING_H
#include <iostream>

using namespace std;

class String
{
public:
    String                            ();
    String                            (char* text);
//    String                            (int i);
    //---big three---//
//    String                            (String &copythis); // copy constructor
    String &operator =                (const String &right); //assignment operator
    ~String                           ();  //destructor

    friend istream& operator >>(istream& in, String& s);
    friend ostream& operator <<(ostream& out, const String& s);

    int StrLen                        ();
    int StrLen                        (char* source);
    void StrCpy                       (String source);
    void StrCpy                       (char* source);
    void StrCat                       (String source);
    void StrCat                       (char* source);
    int StrCmp                        (String comparethis);
    String SubStr                     (int start, int length);
    int Find(char a, char *iPtr, int startPos);
    int FindStr(char str[], char *iPtr, int startPos); // iPtr is the main array, str[] is the array we want to find
    void toUpper(char *s); // note: old function from CS2. change to pointer later to keep consistency
    void toLower(char *s);


private:
    char* str;
};

#endif // STRING_H
