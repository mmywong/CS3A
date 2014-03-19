#ifndef CH10HEADER_H
#define CH10HEADER_H
#include <iostream>

using namespace std;

//5
class CounterType
{
public:
    CounterType(); // default constructor sets value to 0
    CounterType(int value); // this constructor calls set
    void set(int value); // sets the value to the value specified by argument
    void increase(); // increase by 1
    void decrease(); // decrease by 1
    int get(); // returns the current value
    void print(ostream &out); // outputs count to a stream

private:
    int value;

};


//6
class Month
{
public:
    Month(); // default constructor
    Month(int monthnum); // constructor using int
    Month(char letter1, char letter2, char letter3); // constructor using first 3 letters of a month name

    void read(int monthnum); // reads month using int
    void read(char letter1, char letter2, char letter3); // reads month using first 3 letters of a month name

    void print(ostream &outint); // outputs month as an int or string of 3 characters

    Month next(); // returns month as a value of type month


private:
    int month;
    char letter1, letter2, letter3;
};


//7
class Month
{
public:
    Month(); // default constructor
    Month(char letter1, char letter2, char letter3); // constructor using first 3 letters of a month name

    void read(char letter1, char letter2, char letter3); // reads month using first 3 letters of a month name

    void print(ostream letter1, ostream letter2, ostream letter3); // outputs month as an int or string of 3 characters

    Month next(); // returns month as a value of type month


private:
    int month;
    char letter1, letter2, letter3;
};


//8
class Month
{
public:
    Month(); // default constructor
    Month(int monthnum); // constructor using int
    Month(char letter1, char letter2, char letter3); // constructor using first 3 letters of a month name

    void read(int monthnum); // reads month using int
    void read(char letter1, char letter2, char letter3); // reads month using first 3 letters of a month name

    void print();
    void sendtofile(ostream &out);

    Month next(); // returns month as a value of type month


private:
    int month;
    char letter1, letter2, letter3;
};

//9
class Counter
{
public:
    Counter();
    void reset(); // set everything to 0
    void incr1(); // increment 1
    void incr10(); // increment 10
    void incr100(); // increment 100
    void incr1000(); // increment 1000
    bool overflow(); // checks to see if the value is greater than 99.99. if return true, cout "overflow"
    //do i need an input output too?
private:
    int cents;
    int dimes;
    int dollars;
    int tendollars;
};

//10
class Rational
{
public:
    Rational();
    Rational(int numerator, int denominator);
    double add(); // +
    double sub(); // -
    double mul(); // *
    double div(); // /
    bool less(); // less than
    double neg(); // negative values
    void input(istream &in);
    void output(ostream &out);
private:
    int numerator;
    int denominator;

};

//11
class Odometer
{
public:
    Odometer();
    Odometer(double miles, double mpg);
    void reset();
    void addmileage(double milesthistrip); // adds the amount "milesthistrip" to total number of miles
    double gallonsconsumed();
    void inputmpg(istream &inmpg); // efficiency
    void output(ostream miles, ostream mpg);
private:
        //double fuel;
    double miles;
    double mpg;
};

//13
class Zipcode
{
public:
    Zipcode(int zipi);
    Zipcode(string zips);
    string encode(); //from int to string
    int decode(); // from string to int
    void concatenate(); // concatenates the 5 strings together
    void input(istream &in); //does this take in both string and int? like cin, doesn't care?
    void output(ostream &out); // include an error message if invalid code is passed
private:
    int zipi;
    string zips;
};

#endif // CH10HEADER_H
