#include <iostream>
#include "map.h"

using namespace std;

int main()
{
    srand (time(NULL));
    Map dust;
    dust.initialize();
    dust.random();
    dust.show();


    bool done = true;
    while(done) {
        dust.step();
        dust.show();
        cin.get();
    }

    return 0;
}

