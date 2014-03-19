#include <iostream>

using namespace std;


int countpounds(int numofdays, int period , int initpopulation)
{
    int i = numofdays/period; //i is how many cycles, or total num of elementsR
    int j=0;
    int value[10]; // value is the value of the jth element
    value[0] = 1;
    value[1] = 1;
    for (int j = 0; j < i; j++)
    {
    value[j+2] = value[j] + value[j+1];
    pounds = initpopulation*value[j];
    cout << pounds << "  ";
    }
    cout << endl;
}


int main()
{
    int initpopulation = 10, numofdays, pounds, period = 5; // i = 0,1,2,3...
//    Integer sequence[100];

    cout << "initial population : ";
    cin >> initpopulation;
    cout << endl;
    cout << "number of days : ";
    cin >> numofdays;
    cout << endl;

    countpounds(numofdays,period,initpopulation);


    return 0;
}

