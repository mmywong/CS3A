#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    list L;
    L.InsertHead(1); // first node

    L.Append(2);
    L.Append(3);
    L.Append(4);
    L.InsertAfter(L.Begin(),5);

    /*
    L.InsertAfter(marker, 2);
    marker = marker->next;
    L.InsertAfter(marker, 3);
    marker = marker->next;
    L.InsertAfter(marker, 4);
    marker = marker->next;
    L.InsertBefore(mainhead,marker,0);

    L.InsertAfter(marker, 5);
    L.Remove(mainhead,marker);
 */
    L.Print();

    cout<< endl<<endl<<endl;

    list B(L);

    B.Print();

    cout << endl << endl;

    return 0;
}
