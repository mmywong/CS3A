#include <iostream>

using namespace std;

int strCmp(char main[], char sub[]);

int main()
{
    char main[50];
    char sub[50];
    cout << "string : ";
    cin>>main;
    cin>>sub;

    cout<<":"<<strCmp(main, sub);

    return 0;
}

int strCmp(char main[], char sub[])
{
    int i=0;

    do
    {
        if(main[i]==sub[i])
            i++;
        else if(main[i]>sub[i])
            return 1;
        else
            return -1;
    }while((main[i] != '\0')||(sub[i]) != '\0');
}
