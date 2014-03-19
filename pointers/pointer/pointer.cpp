#include <iostream>

using namespace std;

void Reverse(char *s);
void Swap(char &a, char &b);
void Swap2(char *a, char *b);
int strLen(char sub[]);
int find(char key, char *s, int startPos);
void DeleteRepeat(char A[]);
void DeleteAll(char A[], char key, int start);
void shiftLeft(char A[], int index);

int main()
{

    cout << "~~~testing Reverse~~~" << endl;
    char B[] = "R E V E R S E";
    char *cPtr;
    cPtr = B;
    cout << "Array : " << B << endl;
    cout << "processing Reverse(cPtr)... " << endl;
    Reverse(cPtr);
    cout << "Array : " << B << endl << endl << endl;

//    cout << "~~~testing Swap~~~"<<endl;
//    char x = 'x';
//    char y = 'y';
//    cout << "x: " << x << " , y: " << y << endl;
//    cout << "processing Swap(x,y)..."<< endl;
//    Swap(x,y);
//    cout << "x: "<< x << " , y: " << y << endl << endl << endl;

//    cout << "~~~testing DeleteRepeat~~~" << endl; // note: delete repeat not yet fixed
//    char A[] = "AABBACDEBACDEACBBCECAAD";
//    cout << "Array : " << A << endl;
//    cout << "processing DeleteRepeat(A)..." << endl;
//    DeleteRepeat(A);
//    cout << "Array : " << A << endl;


    return 0;
}

void DeleteRepeat(char A[])
{
     for (int i=0; i<strLen(A); i++)
        DeleteAll(A, *(A+i), i+1);
}
/*
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

*/

void DeleteAll(char A[], char key, int start) // deletes all "key" characters from the array
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

void Reverse(char *s)
{
    char *front, *back;
    front = s;
    back = s+strLen(s)-1;
    while(front < back)
    {
        Swap(*front, *back);
        front++;
        back--;
    }
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

void Swap(char &a, char &b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

void Swap2(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

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
