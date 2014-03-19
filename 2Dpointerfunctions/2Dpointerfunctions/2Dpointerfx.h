#ifndef 2DPOINTERFX_H
#define 2DPOINTERFX_H

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
void Print(int** TwoD, int* sizes);


int** Allocate(int row_size, int* sizes) // creates rows
{
    int **TwoD; // defines the double pointer
    int **walker;

    TwoD = new int*[row_size]; // creates the dynamic pointer array (vertical array)
    walker = TwoD;
    for(int i=0; i<row_size; i++) // calls *Allocate function repeatedly to create columns for each row
    {
        *walker++ = Allocate(*sizes);
        sizes++; //for each row to have a diff number of columns, we move through the sizes array
    }
    return TwoD;
}

int* Allocate(int col_size) // creates columns
{
    int *miniwalker; //points to the start of miniarray
    int *front; // moving pointer
    miniwalker = new int[col_size];
    front = miniwalker;

    for(int i = 0; i < col_size; i++){ // goes through from beginning of mini array to end of mini array (horizontal array)
        *miniwalker = 0; // puts in zeroes into all the miniarrays
        miniwalker++;
    }
    return front;
}

void Print(int **TwoD, int *sizes) //couts everything
{
    int **walker;
    int *miniwalker;
    walker = TwoD;

    while(*sizes != 0) // goes through vertical array. for each element of sizes, there exists a row that corresponds to it
    {
        miniwalker = *walker; // makes miniwalker pointing at the first element of the array
        for(int i = 0; i < *sizes; i++) // goes through horizontal array
        {
            cout << *miniwalker << "  ";
            miniwalker++;
        }
        cout<<endl;
        sizes++;
        walker++;
    }
}

bool Verify(int row, int col, int* sizes) // checks to see if that position is valid
{
    int counter = 0; // gives you the number of rows

    while (*sizes != 0)
    {
        if(row>counter && col>*sizes)
            return false;
        counter++; // counter is now the number of rows
        sizes++;
    }
    if(row>0 && col>0)
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



#endif // 2DPOINTERFX_H
