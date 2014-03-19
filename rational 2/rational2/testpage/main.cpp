#include <iostream>

using namespace std;

int main()
{
    const int monthArray[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},
                                   {31,29,31,30,31,30,31,31,30,31,30,31}};
    for(int i=0; i<12; i++)
        cout<<monthArray[0][i]<<"  ";
    for(int i=0; i<12; i++)
        cout<<monthArray[1][i]<<"  ";
    return 0;
}

