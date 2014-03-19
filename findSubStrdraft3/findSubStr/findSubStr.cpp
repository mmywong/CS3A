#include <iostream>

using namespace std;

bool match(char main[], char sub[], int start);
int findSubStr(char main[], char sub[], int start);
int strLen(char sub[]);

int main()
{
    char main[50], sub[50];
    int start;
    int ans;
    cout<<"main string : ";
    cin>>main;
    cout<<"sub string : ";
    cin>>sub;
    cout<<"starting position : ";
    cin>>start;

    ans = findSubStr(main, sub, start);
    cout<<"sub string found in main string starting from position : "<<ans<<endl;
    return 0;
}

int findSubStr(char main[], char sub[], int start)
{
    //int index = start; //initially, they are the same. however, start is the starting position to be compared. index is a moving reference point.
    for(int i=start; i<strLen(main); i++)
    {
        if(match(main, sub, i) == true)
            return i;
    }
    return -1;
}

bool match(char main[], char sub[], int index)
{
    for(int i=0; i< strLen(sub); i++)
    {
        if(main[index+i]==sub[i]) //a section of main matches completely with sub
            return true;
        else
            return false;
    }
}

int strLen(char sub[])
{
    int i=0;
    while(sub[i] != '\0')
    {
        i++;
    }
    return i;
}
