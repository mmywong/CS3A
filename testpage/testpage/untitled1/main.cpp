#include <iostream>

using namespace std;

int main()
{
    char A[] = "Andy";
    int i = 0;
    while(A[i] != '\0')
    {
        cout << A[i];
        i++;
    }
    cout << endl << endl;

    for(int i = 0; i<5; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}

