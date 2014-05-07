#include <iostream>
#include "map.h"

using namespace std;

int main()
{
    Map dust;
    dust.initialize();
    dust.random();
    dust.show();
    char option;
    cin>>option;
    while(option != 'x')
    {
        dust.step();
        dust.show();
        cin>>option;
    }

    return 0;
}

