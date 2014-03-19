#include <iostream>

using namespace std;

void shiftLeft(char A[], int index);
int strLen(char A[]);
int find(char key, char s[], int startPos);
void deleteall(char A[], char key, int start);
void deleterepeats(char A[]);

int main()
{
    char A[] = "AABACBDCCAEDCCBAA";

    cout<< A <<endl;

    deleterepeats(A);

    cout<< A <<endl;
    return 0;
}

void deleterepeats(char A[])
{
    for (int i=0; i<strLen(A); i++)
    {
        deleteall(A, A[i], i+1);
        //start deleting from position i+1 because the character at position i is the first of its kind
        //as i increments, A[i] will be a new unique character because all the repeating characters have been erased
    }
}

void deleteall(char A[], char key, int start)
{
    int index = 0;
    int i=0;
    while (A[i] != '\0')
    {
        index = find(key, A, start); //finds the position of the repeat character
        if(index != -1) //if char is found at position index
            shiftLeft(A, index);  //shiftleft to delete the character at position index
        i++;
    }
}

void shiftLeft(char A[], int index)
{
    //index is the position which will be "deleted" or replaced
    int size = strLen(A);
    for(int i=index; i<size; i++)
    {
        A[i]=A[i+1];
    }
    A[size]='\0';
}

int find(char key, char s[], int startPos)
{
    int i=startPos;
    for(i=startPos; i < strLen(s); i++)
        if(s[i] == key)
            return i; //char found at position i
    return -1; // char not found
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
