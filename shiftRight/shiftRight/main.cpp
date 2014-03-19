#include <iostream>

using namespace std;

void shiftRight(char A[], int index);
int strLen(char A[]);

int main()
{
    char A[50];
    int index;

    cout<<"string: ";
    cin>>A;
    cout<<"start position: ";
    cin>>index;

    shiftRight(A,index);
    cout<<A<<endl;
    return 0;
}

void shiftRight(char A[], int index)
{
    int size = strLen(A);
    int i=size;
    while(i>=index)
    {
        A[i+1]=A[i];
        i--;
    }
    A[index]='X';
    A[size+1]='\0';
}

int strLen(char A[])
{
    int i=0;
    while (A[i] != '\0')
    {
        i++;
    }
    return i;
}
