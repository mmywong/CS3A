#include <iostream>

using namespace std;

int strLen(char sub[]);
void Reverse(char *s);
void Swap(char a, char b);

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

    return 0;
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

void Swap(char a, char b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

int strLen(char sub[])
{
    int i=0;
    while(sub[i] != '\0')
        i++;
    return i;
}
