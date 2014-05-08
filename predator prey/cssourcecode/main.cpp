#include <iostream>
#include "map.h"

using namespace std;

int main()
{
    char option;
    Map dust;
    dust.initialize();
    dust.random();
    dust.show();

    cin>>option;

    while(option != 'x')
    {
        switch(option)
        {
        case 's':
            dust.step();
            dust.show();
            break;
        default:
            break;
        }
        cin>>option;
    }

    return 0;
}

