#include <iostream>
#include <../../../../Dropbox/myheaderfiles/TwoDpointerfx.h>
#include <cstring>

using namespace std;

int main()
{
    int max_row = 0;
    int** TwoD;

    int row = 0;
    int col = 0;
    int item = 0;


    int rowindicator;

    char row_title[] = "row";

    cout << "  ~~~~~ Airbus 1337 ~~~~~  " << endl << endl;

    cout << "Number of rows the plane has : ";
    cin >> max_row;

    //int sizes[] = {11,6,4,3,0}; // array filled with the number of columns for each pointer
    int sizes[max_row];
    for(int i = 0; i < max_row; i++)
        sizes[i] = 4;
    sizes[max_row] = 0;



    TwoD = Allocate(max_row, sizes); // calls the double pointer function, not *Allocate
    cout << endl;
    Print(TwoD, sizes, row_title);


    char choice = 'Y';
    while(choice == 'y' || choice == 'Y')
    {
        cout << endl << endl;
        cout << "~~~~~Menu~~~~~" << endl;
        cout << "1 : Reserve " << endl;
        cout << "2 : Cancel " << endl;
        cout << "3 : Availability " << endl<<endl;

        cout << ":";

    char input;
    cin >> input;
    cout << endl << endl;
        switch(input)
        {
        case '1' : //Verify, read (make sure it's not taken) and write, then print
            cout << "~Reserve~" << endl << endl;
            cout << "row : ";
            cin >> row;
            cout << endl << "col : ";
            cin >> col;
            if ((Verify(row, col, sizes) == true) && (Read(TwoD, row, col) == 0))
            {
                Write(TwoD, row, col, 1);
                Print(TwoD, sizes, row_title);
                cout << endl << endl;
            }
            else
                cout << "Sorry, either that seat does not exist or has already been filled."<< endl << endl;
            break;
        case '2' : //verify and delete, then print
            cout << "~Cancel~" << endl << endl;
            cout << "row : ";
            cin >> row;
            cout << endl << "col : ";
            cin >> col;
            if (Verify(row, col, sizes) == true)
            {
                Delete(TwoD, row, col);
                Print(TwoD, sizes, row_title);
                cout << endl << endl;
            }
            else
                cout << "Sorry, that seat does not exist." << endl << endl;
            break;
        case '3' : // verify and read
            cout << "~Availability~" << endl << endl;
            cout << "row : ";
            cin >> row;
            cout << endl << "col : ";
            cin >> col;

            if ((Verify(row, col, sizes) == true) && (Read(TwoD, row, col) == 0))
                cout << "the seat is available" << endl << endl;
            else if ((Verify(row, col, sizes) == true) && (Read(TwoD, row, col) != 0))
                cout << "the seat is not available" << endl << endl;
            else
                cout << "the seat does not exist" << endl << endl; // verify is false
            break;
         default :
            break;
        }
    }
    return 0;
}

