#include <iostream>
#include "../../../CS3A/stringlibrary/stringfx.h"

using namespace std;

void deletenonchar(char *input, int startpos);
int FindNotAny(char charSet[], char s[], int startPos);

void shiftLeft(char* A, int index)
{
    //index is the position which will be "deleted" or replaced
    int size = StrLen(A);
    for(int i=index; i<size; i++)
    {
        *(A+i) = *(A+i+1);
    }
    *(A+size) = '\0';
}

int main()
{
    char* input;
    cin.getline(input,50);
    cout << "input : " << input << endl;
    deletenonchar(input, 3);
    cout << "input again : " << input << endl;
    return 0;
}

void deletenonchar(char *input, int startpos)
{
    char* hash = "#";
    int newstartpoint = FindNotAny(hash, input, startpos);
    for(int i = startpos; i<newstartpoint; i++)
    {
        if(Find('#', input, startpos) != -1) // if '#' is found,
            shiftLeft(input, Find('#', input, startpos));
    }
}
int FindNotAny(char charSet[], char s[], int startPos)
{
    int i = startPos;

    while(s[i] != '\0')
    {
        if(Find(s[i], charSet, 0) == -1)
            return i;
        else
            i++;
    }
    return -1;
}
