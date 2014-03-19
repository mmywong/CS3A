#include <iostream>

using namespace std;

bool match(char main[], char sub[], int start);
int findSubStr(char main[], char sub[], int start);
int strLen(char sub[]);
int find(char key, char s[], int startPos);
int strCmp(char main[], char sub[], int positionfound);

int main()
{
    char main[50], sub[50];
    int start;
    cout<<"main string : ";
    cin>>main;
    cout<<"sub string : ";
    cin>>sub;
    cout<<"starting position : ";
    cin>>start;

    cout<<"sub string found in main string at position : "<<findSubStr(main, sub, start);
    return 0;
}

bool match(char main[], char sub[], int start, int& positionfound)
{
    int positionfound = find(sub[0], main, start);
    for(int i=positionfound; i<(positionfound+strLen(sub); i++))
    {
        j=0;
        if (match(main,sub,start,positionfound)==true)
            return positionfound;
        else
    }


        while (main[i]!= '\0')
        {
            if(main[i]==sub[0])
            {
                positionfound = i;
                return true;
            }
            else
                i++;
        }
        return false;

}

int findSubStr(char main[], char sub[], int start)
{



    int i=0;
        while(main[i])
        {
            if(match == true)
            {

                return positionfound;
            }
            else
                i++;
        }
        return -1;
}

/*
int find(char key, char s[], int startPos)
{
    int i=startPos;
    for(i=startPos; i < strLen(s); i++)
        if(s[i] == key)
            return i;
    return -1;

}


int strCmp(char main[], char sub[], int positionfound)
{
    int i=0;
    int j=positionfound;
    do
    {
        if(main[j]==sub[i])
            i++;
        else if(main[i]>sub[i])
            return 1;
        else
            return -1;
    }while((main[i] != '\0')||(sub[i]) != '\0');
}
*/


//using strLen to find out the end point of sub string.
int strLen(char sub[])
{
    int i=0;
    while(sub[i] != '\0')
    {
        i++;
    }
    return i;
}
