#include <../../../../Dropbox/myheaderfiles/TwoDpointerfx.h>
#include <iostream>

using namespace std;

int main()
{
    int max_row = 10;
    int **TwoD;

    int sizes[] = {5,6,4,3,0}; // array filled with the number of columns for each pointer

    int rowindicator;

    char row_title[] = "row";

    TwoD = Allocate(max_row, sizes); // calls the double pointer function, not *Allocate
    cout << endl;
    Print(TwoD, sizes, row_title);

    return 0;
}

