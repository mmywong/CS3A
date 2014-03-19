#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int find(string entrytoDelete, string temp[], int &size);
string *AddEntry(string *dynamicArray, int &size, string newEntry);
string *DeleteEntry(string *dynamicArray, int &size, string entryToDelete);

int main()
{
    cout<<"<++++++++++++Michi's Pokedex+++++++++++++>"<<endl<<endl;

    int size = 0;
    string *Name = NULL; // initializes name
    cout<<"You have encountered a new Pokemon! Articuno will be added to your Pokedex."<<endl;
    Name = AddEntry(Name, size, "Articuno");
    cout<<"You have encountered a new Pokemon! Bulbasaur will be added to your Pokedex."<<endl;
    Name = AddEntry(Name, size, "Bulbasaur");
    cout<<"You have encountered a new Pokemon! Charmander will be added to your Pokedex."<<endl;
    Name = AddEntry(Name, size, "Charmander");
    cout<<endl;
    cout<<"Bulbasaur died. He will be removed from your Pokedex."<<endl;
    Name = DeleteEntry(Name, size, "Bulbasaur");
    return 0;
}

string *AddEntry(string* dynamicArray, int &size, string newEntry)
{
    size++; // increment size to make space for new entry
    string *temp; //declares a pointer pointing to the new temporary array in the freestore
    temp = new string[size]; // initially size is 0. everytime we run addentry, the size must increment by 1 to make space for the new entry.
    int i = 0; //declaration made outside of for loops cause we need i to know the position of where to add the new entry

    for(i=0; i<(size-1); i++) //this for loop copies all the entries from the old array into the new temporary array
        temp[i] = dynamicArray[i];

    *(temp+i) = newEntry; //copies the latest entry or string into the freestore

    /*DISPLAYS*/
    cout<<"===Entry==="<<endl;
    for(i=0; i<size; i++) //this for loop couts the entries
        cout<<"size: "<<size<<setw(10)<<"name: "<<temp[i]<<endl;
    cout<<endl<<endl;

    if(dynamicArray != NULL) // as long as there is some entry in dynamicArray (array is not empty)
        delete [] dynamicArray; // delete dynamicArray (the old array)

    return temp; // returns the address of the freestore
}

string *DeleteEntry(string *dynamicArray, int &size, string entryToDelete)
{
    int positionfound; // position where the entryToDelete is found in the array
    positionfound = find(entryToDelete, dynamicArray, size);

    if(positionfound == -1)
        return dynamicArray;

    /*V if we find entryToDelete in dynamicArray V*/
    size--;
    string *temp;
    temp = new string[size];

    for(int i=0; i<positionfound; i++) //this for loop copies all the entries from the old array into the new temporary array up to positionfound
        temp[i] = dynamicArray[i];
    for(int i=positionfound; i<size; i++)// this sets the blocks from positionfound onward
        *(temp+i) = *(dynamicArray+i+1);

    /*DISPLAYS*/
    cout<<"===Entry==="<<endl;
    for(int i=0; i<size; i++) //this for loop couts the entries
        cout<<"size: "<<size<<setw(10)<<"name: "<<temp[i]<<endl;
    cout<<endl<<endl;

    delete [] dynamicArray; // delete dynamicArray (the old array)

    return temp;
}

int find(string entrytoDelete, string *dynamicArray, int &size)
{
   for(int i=0; i < size; i++)
       if(*(dynamicArray+i) == entrytoDelete)
           return i; //char found at position i
   return -1; // char not found
}
