#ifndef STRINGFX_H
#define STRINGFX_H

int StrLen(char *iPtr);
void StrCpy(char *dest, char *source);
void StrCat(char *&dest, char *source);
int StrCmp(char *Ptr1, char *Ptr2);
void SubStr(char *&main, char *sub, int start, int length);
int Find(char a, char *iPtr, int startPos);
int FindStr(char str[], char *iPtr, int startPos); // iPtr is the main array, str[] is the array we want to find
void toUpper(char *s); // note: old function from CS2. change to pointer later to keep consistency
void toLower(char s[]);

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

int FindStr(char str[], char *iPtr, int startPos) // finds a string str within a string iPtr
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

void toUpper(char* s)
{
    int i=0;

    while(*(s+i) != '\0')
    {
        switch(*(s+i))
        {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':

                *(s+i)-=32;
                i++;
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
            case ' ':
                i++;
                break;
            }
        }
}

//10: To Lower
void toLower(char s[])
{
    int i=0;

    while(s[i] != '\0')
    {
        switch(s[i])
        {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
            case ' ':
                s[i]=s[i];
                i++;
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                s[i]=s[i]+32;
                i++;
                break;
            }

    }
}




#endif // STRINGFX_H
