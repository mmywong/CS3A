#include <iostream>

using namespace std;

void q1_doublenumber(int A[]);
void q2_read(int A[], int size);
void q3_readpositiveonly(int A[], int size);
void q4_display(int A[], int size);

int main()
{
    int A1[10];
    int A2[5];
    int A3[100];

    char choice;
    char repeat;

    cout << "===Menu===" <<endl;
    cout << "1: Question 1"<<endl;
    cout << "2: Question 2 and 4"<<endl;
    cout << "3: Question 3"<<endl;

    cin>>choice;

    switch (choice)
    {
     case '1':
        q1_doublenumber(A1);
        q4_display(A1, 10);
        break;
     case '2':
        cout<<"input 5 numbers:"<<endl;
        q2_read(A2, 5);
        q4_display(A2, 5);
        break;
     case '3':
        q3_readpositiveonly(A3, 100);
        break;
    }
     return 0;
}

void q1_doublenumber(int A[])
{
    A[0]=1;

    for (int i=0; i<10; i++)
     A[i+1]=2*(A[i]);
}

void q2_read(int A[], int size)
{
    for (int i=0; i<size; i++)
     cin>>A[i];
}

void q3_readpositiveonly(int A[], int size)
{
    int n;
    int i=0;
    cout<<":";
    cin>>n;
    while(n>0)
    {
        A[i]=n;
        i++;
        cout<<" ";
        cin>>n;
    }
}

void q4_display(int A[], int size)
{
    for(int i=0; i<size; i++)
        cout<<A[i]<<" ";
}
