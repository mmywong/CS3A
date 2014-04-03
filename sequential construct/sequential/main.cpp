#include <iostream>
#include "list.h"
#include "iterator.h"

using namespace std;

int main()
{
    cout << "making a new list : " << endl;
    list L;
    L.InsertHead(1);
    Iterator walker(L.Begin()); // make iterator point at head
    L.Append(2);
    L.Append(3);
    L.Append(4);
    L.Print();
    cout << endl << endl;

    cout << "testing copy constructor : " << endl;
    list L2(L);
    L2.Print();
    cout << endl << endl;

    cout << "testing assignment operator : " << endl;
    L.Append(5);
    L2 = L;
    L2.Print();
    cout << endl << endl;

    cout << "testing InsertHead : " << endl;
    L2.InsertHead(0);
    L2.Print();
    cout << endl << endl;

    cout << "testing InsertAfter and walker operator: " << endl;
    //iterator walker is pointing at head of L
    L.InsertAfter(walker, 9);
    walker++;
    walker++;
    L.InsertAfter(walker, 8);
    L.Print();
    cout << endl << endl;

    cout << "testing Delete : " << endl;
    int i;
    //walker is pointig at 9
    i = L.Delete(walker);
    cout << "iterator's value : " << i << endl;
    cout << "list : ";
    L.Print();
    cout << endl << endl;


    cout << "End of program" << endl;

    return 0;
}
