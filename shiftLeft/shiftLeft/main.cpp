#include <iostream>

using namespace std;

void shiftLeft(char A[], int index);
int strLen(char A[]);

int main()
{
    char A[50];
    int index;

    cout<<"string: ";
    cin>>A;
    cout<<"start position: ";
    cin>>index;

    shiftLeft(A,index);
    cout<<A<<endl;
    return 0;
}

void shiftLeft(char A[], int index)
{
    int size = strLen(A);
    for(int i=index; i<size; i++)
    {
        A[i]=A[i+1];
    }
    A[size]='\0';
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
