#ifndef MONTH_H
#define MONTH_H
#include <string>

using namespace std;

class Month
{
public:
    Month(); // default constructor
    Month(int monthnum); // constructor using int. int represents which month (1 jan, 2 feb)
    Month(char new_letter1, char new_letter2, char new_letter3); // constructor using first 3 letters of a month name

    void read(int monthnum); // reads month using int
    void read(char new_letter1, char new_letter2, char new_letter3); // reads month using first 3 letters of a month name

    //string combineletters(char new_letter1, char new_letter2, char new_letter3); // concatenates letters to a string
    string inttostring(int monthnum); // converts int to string
    int stringtoint(char new_letter1, char new_letter2, char new_letter3); // converts string to int

    void printi(ostream &outint); // outputs month as an int
    void prints(ostream &outstring); // outputs first three letters of month

    Month next(); // returns month as a value of type month

    int getmonth();



private:
    int month;
    char letter1, letter2, letter3;
};

#endif // MONTH_H
