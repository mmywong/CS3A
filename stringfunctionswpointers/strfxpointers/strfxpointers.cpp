#include <iostream>
#include <../../../../Dropbox/CS3A Assignments/stringlibrary/stringfx.h>

using namespace std;

int main()
{
    char *one = new char[10];
    char *two = new char[10];

    StrCpy(one, "hello");
    StrCpy(two," world!");

    cout<<"###testing StrLen###"<<endl;
    cout<<"string one: "<<one<<endl;
    cout<<"StrLen(one)..."<<endl;
    int length = StrLen(one);
    cout<<"string length = "<<length<<endl<<endl<<endl;

    cout<<"###testing StrCpy###"<<endl;
    cout<<"string one before: "<<one<<endl;
    cout<<"StrCpy(one, \"bye bye\")..."<<endl;
    StrCpy(one,"bye bye");
    cout<<"string one after : "<<one<<endl<<endl<<endl;

    cout<<"###testing StrCat###"<<endl;
    cout<<"string one : "<<one<<endl;
    cout<<"string two : "<<two<<endl;
    cout<<"StrCat(one,two)... "<<endl;
    StrCat(one, two);
    cout<<"one cat two : "<<one<<endl<<endl<<endl;


    char comp1[] = "hello";
    char comp2[] = "hellfire";
    cout<<"###testing StrCmp###"<<endl;
    cout<<"string comp1 : "<<comp1<<endl;
    cout<<"string comp2 : "<<comp2<<endl;
    cout<<"StrCmp(comp1, comp2)... "<<endl;
    int cmp = StrCmp(comp1, comp2);
    cout<<"StrCmp : "<<cmp<<endl;
    cout<<"StrCmp(comp2, comp1)..."<<endl;
    cmp = StrCmp(comp2, comp1);
    cout<<"StrCmp : "<<cmp<<endl;
    cout<<"StrCmp(comp1, comp1)..."<<endl;
    cmp = StrCmp(comp1, comp1);
    cout<<"StrCmp : "<<cmp<<endl<<endl<<endl;


    char *mainstr = new char[20];
    StrCpy(mainstr,"substring function");
    char substr[10];
    cout<<"###testing SubStr###"<<endl;
    cout<<"main string : "<<mainstr<<endl;
    cout<<"taking out \"string\" from \"substring function\"..."<<endl;
    cout<<"SubStr(mainstr, substr, 3, 6)..."<<endl;
    SubStr(mainstr, substr, 3, 6);
    cout<<"substring : "<<substr<<endl<<endl<<endl;


    cout<<"###testing Find###"<<endl;
    int pos;
    char *mainstr2 = new char[20];
    StrCpy(mainstr2, "find function");
    cout<<"string : "<<mainstr2<<endl;
    cout<<"character : u"<<endl;
    pos = Find('u', mainstr2, 0);
    cout<<"pos : "<<pos<<endl<<endl<<endl;

    cout<<"###testing FindStr###"<<endl;
    int pos2;
    char *mainstr3 = new char[20];
    StrCpy(mainstr3, "find string from this");
    cout<<"main string : "<<mainstr3<<endl;
    char A[] = "string";
    cout<<"string : "<<A<<endl;
    pos2 = FindStr(A, mainstr3, 0);
    cout<<"pos : "<<pos2<<endl<<endl<<endl;

    return 0;
}
