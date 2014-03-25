#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    node* mainhead = NULL;

    list L;
    L.InsertHead(mainhead, 1); // first node

    node* marker = mainhead;

    L.InsertAfter(marker, 2);
    marker = marker->next;
    L.InsertAfter(marker, 3);
    marker = marker->next;
    L.InsertAfter(marker, 4);
    marker = marker->next;
    L.InsertBefore(mainhead,marker,0);

    L.InsertAfter(marker, 5);
    L.Remove(mainhead,marker);
    L.Print(mainhead);

    cout << endl << endl;

    return 0;
}
