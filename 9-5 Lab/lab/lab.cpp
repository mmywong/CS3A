#include <iostream>
#include <cstring>

//Create functions :
int** Allocate(int row_size, int* sizes);
int* Allocate(int size);

//Check / Gather info functions :
bool Verify(int row, int col, int* sizes);
int* Search(int** TwoD, int &row, int &col, int* sizes, int item); //row and col here is the position found, not the input row and col
int Find(int *iPtr, int item, int columnsize);
int Read(int** TwoD, int row, int col);

//Modify functions :
void Write(int** TwoD, int row, int col, int item);
void Delete(int** TwoD, int row, int col); // doesn't take into account of what the item is, just delete it

//Display functions :
void Print(int** TwoD, int* sizes, char row_title[]);

using namespace std;

int main()
{
    int max_row = 4;
    int** TwoD;

    int row = 0;
    int col = 0;
    int item = 0;

    int sizes[] = {5,6,4,3,0}; // array filled with the number of columns for each pointer

    int rowindicator;

    char row_title[] = "lab";

    cout << "Lab Number          Computer Station Numbers";
    TwoD = Allocate(max_row, sizes); // calls the double pointer function, not *Allocate
    cout << endl;
    Print(TwoD, sizes, row_title);



    char choice = 'Y';
    while(choice == 'y' || choice == 'Y')
    {
        cout << endl << endl;
        cout << "~~~~~Menu~~~~~" << endl;
        cout << "1 : Login " << endl;
        cout << "2 : Logout " << endl;
        cout << "3 : Search " << endl;
        cout << "4 : Availability " << endl;

    char input;
    cin >> input;

        switch(input)
        {
        case '1' : //Verify, read (make sure it's not taken) and write, then print
            cout << "~Login~" << endl << endl;
            cout << "row : ";
            cin >> row;
            cout << endl << "col : ";
            cin >> col;
            if ((Verify(row, col, sizes) == true) && (Read(TwoD, row, col) == 0))
            {
                cout << "item : ";
                cin >> item;
                Write(TwoD, row, col, item);
                Print(TwoD, sizes, row_title);
            }
            else
                cout << "Sorry, either that station does not exist or has already been filled."<< endl << endl;
            break;
        case '2' : //verify and delete, then print
            cout << "~Logout~" << endl << endl;
            cout << "row : ";
            cin >> row;
            cout << endl << "col : ";
            cin >> col;
            if (Verify(row, col, sizes) == true)
            {
                Delete(TwoD, row, col);
                Print(TwoD, sizes, row_title);
            }
            else
                cout << "Sorry, that station does not exist." << endl << endl;
            break;
        case '3' :
            cout << "~Search~" << endl << endl;
            cout << "item : ";
            cin >> item;
            int* searchres;
            searchres = Search(TwoD, row, col, sizes, item);

            if(searchres != NULL)
            {
                cout<<"address found : "<<searchres<<endl;
                cout<<"item found : "<<*searchres<<endl;
                cout<<"row : "<<row<<"   col : "<<col<<endl;
            }
            else
                cout<<"searched item is not found"<< endl << endl;
            break;
        case '4' : // verify and read
            cout << "~Availability~" << endl << endl;
            cout << "row : ";
            cin >> row;
            cout << endl << "col : ";
            cin >> col;

            if ((Verify(row, col, sizes) == true) && (Read(TwoD, row, col) == 0))
                cout << "the station is available" << endl << endl;
            else if ((Verify(row, col, sizes) == true) && (Read(TwoD, row, col) != 0))
                cout << "the station is not available" << endl << endl;
            else
                cout << "the station does not exist" << endl << endl;
            break;

        }
        cout << "repeat?" << endl;
        cout << "'Y' for yes" << endl;
        cin >> choice;
    }
    return 0;
}


int** Allocate(int row_size, int* sizes) // creates rows
{
    int **TwoD; // defines the double pointer
    int **walker;

    TwoD = new int*[row_size]; // creates the dynamic pointer array (vertical array)
    walker = TwoD;
    for(int i=0; i <row_size; i++) // calls *Allocate function repeatedly to create columns for each row
    {
        *walker++ = Allocate(*sizes);
        sizes++; //for each row to have a diff number of columns, we move through the sizes array
    }
    return TwoD;
}

int* Allocate(int col_size) // creates columns
{
    int *miniwalker; // moving pointer
    int *front; //points to the start of miniarray
    front = new int[col_size];
    miniwalker = front;

//    for(int i = 0; i < col_size; i++){ // goes through from beginning of mini array to end of mini array (horizontal array)
//        *miniwalker = 0; // puts in zeroes into all the miniarrays
//        miniwalker++;
//    }
    //alternative way:
    memset(front,0,col_size*sizeof(*front)); //memset is a function which allocates the same value to a whole array. sizeof is the size of memory allocated to the variable.
    //we do col_size*sizeof to find the total size of the memory allocated to this array.
    return front;
}

void Print(int **TwoD, int *sizes, char row_title[]) //couts everything
{
    int **walker;
    int *miniwalker;
    walker = TwoD;
    int rowindicator = 0;

    while(*sizes != 0) // goes through vertical array. for each element of sizes, there exists a row that corresponds to it
    {
        miniwalker = *walker; // makes miniwalker pointing at the first element of the array

        cout<<row_title<<" "<<rowindicator<<"               ";
        rowindicator++; // to increment the row 1, row 2, row 3...
        for(int i = 0; i < *sizes; i++) // goes through horizontal array
        {
            //standard output:
            //cout << *miniwalker << "  ";

            //modified output for Lab:
            if(*miniwalker == 0)
                cout << i << " : empty\t";
            else
                cout << i << " : " << *miniwalker << "\t";

            miniwalker++;
        }
        cout<<endl;
        sizes++;
        walker++;
    }
    cout << endl;
}

bool Verify(int row, int col, int* sizes) // checks to see if that position is valid
{
    int counter = 0; // gives you the number of rows

    while (*sizes != 0)
    {
        if(row>=counter && col>=*sizes)
            return false;
        counter++; // counter is now the number of rows
        sizes++;
    }
    if(row>=0 && col>=0)
        return true;
    else
        return false;
}

int* Search(int** TwoD, int &row, int &col, int* sizes, int item) //gives the address of the searched item
{
    int** walker = TwoD;
    int* miniwalker; // REMEMBER TO RESET MINIWALKER!!! PUT THIS IN LOOP
    int findresult;
    row = 0;
    col = 0;

    while(*sizes != 0) // to find the column size so we can call find -- > sizes+i
    {
        miniwalker = *walker;
        findresult = Find(miniwalker, item, *sizes);

        if(findresult != -1) //found the item
        {
            col = findresult;
            miniwalker += findresult;
            return miniwalker;
        }
        row++;
        sizes++;
        walker++;
    }
    return NULL;
}

int Find(int *iPtr, int item, int columnsize) // finds item in iPtr. returns an int which represents the position, NOT THE ADDRESS. columnsize is the value inside sizes array
{
    int *miniwalker;
    miniwalker = iPtr;
    for(int i=0; i<columnsize; i++)
    {
        if(*miniwalker == item)
            return i; // the column value. which column it is in
        miniwalker++;
    }
    return -1;
}

void Write(int** TwoD, int row, int col, int item)
{
    int** walker = TwoD;
    walker += row; // sets walker to point at the row we want to change

    int* miniwalker = *walker; // sets miniwalker to the beginning of that row
    miniwalker += col; // sets miniwalker to the column we want to change

    *miniwalker = item; // changes the destination position to the item we want
}


void Delete(int** TwoD, int row, int col)
{
    int** walker = TwoD;
    walker += row; // sets walker to point at the row we want to change

    int* miniwalker = *walker; // sets miniwalker to the beginning of that row
    miniwalker += col; // sets miniwalker to the column we want to change

    *miniwalker = 0; // changes the destination position to the item we want
}

int Read(int** TwoD, int row, int col)
{
    int** walker = TwoD;
    walker += row; // sets walker to point at the row we want to read

    int* miniwalker = *walker;// sets miniwalker to the beginning of that row
    miniwalker += col; // sets miniwalker to the column we want to read

    return *miniwalker;
}
