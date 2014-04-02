#include <iostream>
#include "list.h"
#include "iterator.h"

using namespace std;

int main()
{
    list L;

    L.InsertHead(1); // first node

    L.Append(2);
    L.Append(3);
    L.Append(4);
//    L.InsertAfter(walker, 99);

    L.Print();
    Iterator walker(L.Begin());
    cout << "walker at begin : " << *walker << endl;
    cout<<endl<<endl;



    cout << "End of program.\n";


    exit(0);
    return 0;
}
