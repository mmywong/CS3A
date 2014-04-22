#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    stack A;
        A.Push(2);
        A.Push(3);
        A.Push(65);
        A.Push(99);
        A.Print();
        cout << "\npop A : " << A.Pop() << endl;
        A.Print();
        cout << "\npop A : " << A.Pop() << endl;
        A.Print();
        A.Push(100);
        A.Push(200);
        A.Push(300);
        A.Print();
        cout << endl;
    return 0;
}

