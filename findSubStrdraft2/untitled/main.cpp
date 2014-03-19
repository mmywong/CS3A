#include <iostream>

using namespace std;

bool match(char main[], char sub[], int start);
int findSubStr(char main[], char sub[], int start);
int strLen(char sub[]);
int strCmp(char main[], char sub[], int start);
int posFirstChar(char main[], char sub[], int start);

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

    ans = findSubStr(main,sub,start);
    cout<<"sub string found in main string at position : "<<ans;
    return 0;
}

int findSubStr(char main[], char sub[], int start)
{
    int i=start;
    int positionfound = posFirstChar(main,sub,start);
    for(i=0; i<strLen(main); i++)
    {
        if (match(main,sub,start)==true)
            return positionfound;
    }
}


int strCmp(char main[], char sub[], int start)
{
    int i=0;
    int j=posFirstChar(main,sub,start);
    do
    {
        if(main[j]==sub[i])
        {
            i++;
            j++;
        }
        else if(main[j]>sub[i])
            return 1;
        else
            return -1;
    }while((main[j] != '\0')||(sub[i]) != '\0');
}



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

bool match(char main[], char sub[], int start)
{
    int positionfound = posFirstChar(main, sub, start);
    for(int i=positionfound; i<(positionfound+strLen(sub)); i++)
    {
        if(strCmp(main, sub, positionfound)==0)
            return true;
        else
            return false;
    }

}

int posFirstChar(char main[], char sub[], int start)
{
    int i=start;
    while(main[i])
    {
        if(main[i]==sub[0])
            return i;
    }
    i++;
}
