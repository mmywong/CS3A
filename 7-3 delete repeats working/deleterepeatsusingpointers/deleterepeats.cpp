#include <iostream>

using namespace std;

int find(char key, char *s, int startPos);
void deleterepeats(char A[]);
int strLen(char sub[]);

int main()
{
    char A[] = "AABACBDCCAEDCCBAA";

    cout<< A <<endl;

    deleterepeats(A);

    return 0;
}

void deleterepeats(char A[])
{
    int i = 0;
    int size = strLen(A);
    char *iPtr = new char[size]; //
    *iPtr = A[i];

    for (int i=0; i<size; i++)
    {
        int j=0;
        int posfound = find(A[i], iPtr, 0);
        if (posfound != -1)
        {
            char[j] = A[posfound];
            j++;
        }
    }


    // Method 2: Using pointers completely (no need for new array)
    /*
    for (int i=0; i<size; i++)
    {
        int posfound = find(A[i], *iPtr, 0);
        if (posfound != -1)
        {
            *iPtr = A[posfound];
            iPtr++;
        }
    }  */
    cout<<iPtr;
    delete[]iPtr;
}

/*  Modified find function
int find(char key, char *s, int startPos)
{
    int i=0;
    while (*s != '\0')
    {
        if(*(s+startPos) == key)
            return i;
        s++;
        i++;
    }
    return -1;
} */

int find(char key, char s[], int startPos)
{
   int i=startPos;
   for(i=startPos; i < strLen(s); i++)
       if(s[i] == key)
           return i; //char found at position i
   return -1; // char not found
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
