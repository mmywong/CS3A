#include <iostream>

using namespace std;

int main()
{
    int num = 10;
    char letter = 'a';
    int A[]={1,2,3};
    char array[]="hello world!";

    //declaring a pointer of type int
    int *iPtr;

    //declaring a pointer of type char
    char *iPtr2;

    //to point to variable "num"
    iPtr = &num;

    //to point to char "letter"
    iPtr2 = &letter;

    /* ---FOR INTEGERS--- */
    cout<<"FOR INTEGERS"<<endl;
    //this will cout an address:
    cout<<"address : "<<iPtr<<endl;
    //this will cout the value stored in the variable "num":
    cout<<"value : "<<*iPtr<<endl;
    cout<<endl;

    /*---FOR CHARACTERS--- */
    cout<<"FOR CHARACTERS"<<endl;
    //for chars, the (*) is not needed. so this will cout the character "letter" just fine:
    cout<<"without (*) : "<<iPtr2;
    cout<<"with (*) : "<<*iPtr2<<endl;
    cout<<endl;

    /*---FOR INT ARRAYS---*/
    cout<<"FOR INT ARRAYS"<<endl;
    //to print int arrays, we need a for loop. pointer is pointed to the address of the first element
    iPtr = &A[0];
    for(int i = 0; i<3; i++)
        cout<<*(iPtr+i)<<" ";
    cout<<endl<<endl;

    /*---FOR CHAR ARRAYS---*/
    cout<<"FOR CHAR ARRAYS"<<endl;
    //to print char arrays, no need for loop, no need (*). pointer set to address of first element
    iPtr2 = &array[0];
    cout<<iPtr2<<endl<<endl;

    /*---FOR STRINGS---*/
    cout<<"FOR STRINGS"<<endl;
    string str = "hello";
    string *mystring;
    mystring = &str;
    cout<<*mystring<<endl;

    return 0;
}


