#include <iostream>

using namespace std;

int StrLen(char *iPtr);
void StrCpy(char *dest, char *source);
void StrCat(char *&dest, char *source);
int StrCmp(char *Ptr1, char *Ptr2);
void SubStr(char *&main, char *sub, int start, int length);
int Find(char a, char *iPtr, int startPos);
int FindStr(char str[], char *iPtr, int startPos);

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

void SubStr(char *&main, char *sub, int start, int length) //creates a substring which takes a block of main and puts it into sub, starting from position "start" for a given length
{
    char *walker;
    walker = main+start;

    for(int i=0; i<length; i++)
        *sub++ = *walker++;

//   for (int i=0; i<length; i++)
//        *(sub+i) = *(main+start+i);
    *sub = NULL;
    main = sub-length; //resets main to the front, so you can print out from the front and do stuff with it later.
}

int StrCmp(char *Ptr1, char *Ptr2) //compares two strings. returns 0 if they are exactly the same
{
    do
    {
        if(*Ptr1 == *Ptr2)
        {
            Ptr1++;
            Ptr2++;
        }
        else if(*Ptr1 > *Ptr2)
            return 1;
        else
            return -1;

    }while(*Ptr1 != NULL || *Ptr2 != NULL);
}

void StrCat(char *&dest, char *source)//concatenates one string to the end of the other. puts source behind dest
{
    char *temp = new char[50];

    int index;
    index = StrLen(dest);
    StrCpy(temp, dest); //copies one into the new array

    temp = temp + index; //moves temp to position at the end of one
    StrCpy(temp,source);

    temp = temp - index; // moves temp back to the front position

    delete [] dest;//clear the old dest to make space for new string
    dest = temp;

    /* Old StrCat:
    dest = dest + StrLen(dest);
    StrCpy(dest,source); */
}

void StrCpy(char *dest, char *source)//copies source to dest
{
    int i = 0;
    while(*source)
      *dest++ = *source++;
    *dest = NULL;

//    while(*(source+i) != NULL)
//    {
//        *(dest+i) = *(source+i);
//        i++;
//    }
//    *(dest+i) = NULL;
}

int FindStr(char str[], char *iPtr, int startPos) // finds a string within a string
{
    if(StrLen(str) > StrLen(iPtr)) // makes sure that the miniarray is shorter than the main array
        return -1;

    char *mainwalker, *miniwalker;
    int posfirstchar;
    posfirstchar = Find(str[0], iPtr, 0);

    if (posfirstchar == -1)
        return -1; // we didn't even find the first letter

        for(int j=0; j<StrLen(iPtr); j++) // goes through the main iPtr string
        {
            mainwalker = iPtr + posfirstchar + j; //sets mainwalker to a position to start matching miniwalker with. also resets mainwalker after while loop
            miniwalker = str; //assigns miniwalker to point to str array
            while(*mainwalker == *miniwalker && *miniwalker != NULL) // compares miniwalker to mainwalker. also makes sure we are not at the end of the miniwalker
            {
                mainwalker++;
                miniwalker++;
            }
            if (*miniwalker == NULL) //reached the end of miniarray and everything compared are the same
                return mainwalker-StrLen(str)-iPtr; //at this point, mainwalker has incremented, so we need to minus strlen of string to reset it to the front of miniwalker.
                                                        //minus iptr to get the difference between where mainwalker is and the front of the main string.
        }
        return -1; // string is not found in the main
}

int Find(char a, char *iPtr, int startPos) // finds char a in iPtr starting from startPos
{
    char *walker;
    walker = iPtr;
    for(int i=startPos; i<StrLen(iPtr); i++)
    {
        if(*walker == a)
            return i;
        walker++;
    }
    return -1;
}

int StrLen(char *iPtr)
{
    int index = 0;
    while (*(iPtr+index) != '\0')
         index++;
    return index;
}
