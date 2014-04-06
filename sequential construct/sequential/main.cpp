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
    //walker is pointing at 9
    i = L.Delete(walker);
    cout << "iterator's value : " << i << endl;
    cout << "list : ";
    L.Print();
    cout << endl << endl;

    cout << "testing Search : 8" << endl;
    int search = L.Search(8);
    cout << "search is found at position : "<< search << endl;

    cout << "testing Search : 7" << endl;
    int search2 = L.Search(7);
    cout << "search is found at position : "<< search2 << endl;
    cout << endl;

    cout << "testing [] operator :"<< endl;
    cout << "L[2] : " << L[2] << endl;
    cout << "putting L[2] = 10 : " << endl;
    L[2] = 10;
    cout << "L[2] : " << L[2] << endl;
    L.Print();
    cout << endl << endl;

    cout << "testing Begin : "<<endl;
    cout << *(L.Begin()) << endl;
    cout << endl;

    cout << "testing End : " << endl;
    cout << *(L.End()) << endl << endl;

    cout << "testing Ithnode(4) : " << endl;
    cout << *(L.Ithnode(4)) << endl << endl;

    cout << "testing Sort : " << endl;
    list L3;
    L3.InsertHead(6);
    L3.Append(5);
    L3.Append(3);
    L3.Append(4);
    L3.Append(1);
    L3.Print();
    cout << endl;
    L3.Sort();
    L3.Print();
    cout << endl << endl;

    return 0;
}
