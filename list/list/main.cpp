#include <iostream>
#include "cursoredlist.h"
#include "list.h"
#include "iterator.h"
#include "sortedlist.h"
#include "stack.h"
#include "queue.h"

using namespace std;

int main()
{
    cout << "==========================Normal List===============================" << endl << endl;

    cout << "making a new list : " << endl;

    list<int> L;
    L.InsertHead(1);
    Iterator<int> walker(L.Begin()); // make iterator point at head
    L.Append(2);
    L.Append(3);
    L.Append(4);
    L.Print();
    cout << endl << endl;

    cout << "testing copy constructor : " << endl;
    list<int> L2(L);
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

    cout << "testing InsertBefore(Ithnode(4), 2)" << endl;
    L.InsertBefore(L.Ithnode(4), 2);
    L.Print();
    cout << endl << endl;

    cout << "testing InsertAfter(Ithnode(4), 1)" << endl;
    L.InsertAfter(L.Ithnode(4), 1);
    L.Print();
    cout << endl << endl;



    cout << "============================Templated List=============================" << endl << endl;

    cout << "#==char list==#" << endl;
    list<char> L5;
    L5.InsertHead('a');
    L5.Append('c');
    L5.Append('d');
    L5.Append('t');
    L5.Append('w');
    L5.Append('x');
    L5.Append('b');
    L5.Print();

    cout << endl << endl;

    cout << "#==string list==#" << endl;
    list<string> L6;
    L6.InsertHead("test 1");
    L6.Append("davina");
    L6.Append("davina2");
    L6.Append("davina3");
    L6.Append("davina4");
    L6.Append("davina5");
    L6.Print();
    cout << endl << endl;

    cout << "#==int list==#" << endl;
    L.Print();
    cout << endl << endl;

    cout << "=============================Sorted List============================" << endl << endl;

    list<int> L3;
    L3.InsertHead(9);
    L3.Append(5);
    L3.Append(3);
    L3.Append(4);
    L3.Append(8);
    L3.Append(1);
    L3.Append(10);


    SortedList<int> L4;
    cout << "original list" << endl;
    L3.Print();
    cout << endl << endl;
    L4.Sort(L3);
    cout << "sorted list " << endl;
    L4.Print();

    cout << endl << endl;
    SortedList<int> L4_2;
    L4_2.InsertHead(11);
    L4_2.Insert(14);
    L4_2.Insert(31);
    L4_2.Insert(19);
    L4_2.Insert(80);
    L4_2.Insert(6);

    cout << "/--testing merge--/" << endl;
    cout << "old list : " << endl;
    L4.Print();
    cout << endl << "new list :" << endl;
    L4_2.Print();
    cout << endl;
    cout << "merge old and new list : " << endl;
    SortedList<int> L4_merge;
    L4_merge.Merge(L4,L4_2);
    L4_merge.Print();
    cout << endl << endl;

    cout << "=============================Cursored List============================" << endl << endl;

    CursoredList<int> L7;
    L7.InsertHead(9);
    L7.Append(5);
    L7.Append(3);
    L7.Append(4);
    L7.Append(8);
    L7.Append(1);
    L7.Append(10);
    L7.PrintC();
    cout << endl << endl;

    char command;
    cout << "//---controls---//" << endl;
    cout << "a : left" << endl;
    cout << "d : right" << endl;
    cout << "x : exit" << endl;
    cout << " : ";
    cin >> command;

    while(command != 'x')
    {
        switch(command)
        {
            case 'a':
            case 'A':
                L7.GoPrev();
                L7.PrintC();
                cout << endl;
                cout << ":";
                break;
            case 'd':
            case 'D':
                L7.GoNext();
                L7.PrintC();
                cout << endl;
                cout << ":";
                break;
            default:
                break;
        }

        cin >> command;
    }

    cout << endl << endl;

    cout << "=============================Stack============================" << endl << endl;

    stack<int> S;
    cout << "push : 4" << endl;
    S.Push(4);
    S.Print();
    cout << endl << endl;
    cout << "push : 1" << endl;
    S.Push(1);
    S.Print();
    cout << endl << endl;
    cout << "push : 3" << endl;
    S.Push(3);
    S.Print();
    cout << endl << endl;
    cout << "pop : " << endl;
    int popint = S.Pop();
    S.Print();
    cout << endl;
    cout << "pop value : " << popint << endl << endl;
    cout << "top : " << S.Top() << endl << endl;
    cout << "popping more... " << endl;
    S.Pop();
    S.Print();
    cout << endl;
    S.Pop();
    S.Print();
    cout << endl;
    cout << "is stack empty?" << endl;
    if(S.Empty())
        cout << "yes" << endl;
    else
        cout << "no" << endl;


    cout << endl << endl;
    cout << "=============================Queue============================" << endl << endl;

    queue<int> Q;
    cout << "enQueue : 1" << endl;
    Q.EnQueue(1);
    Q.Print();
    cout << endl << endl;

    cout << "enQueue : 3" << endl;
    Q.EnQueue(3);
    Q.Print();
    cout << endl << endl;

    cout << "enQueue : 3" << endl;
    Q.EnQueue(3);
    Q.Print();
    cout << endl << endl;

    cout << "enQueue : 7" << endl;
    Q.EnQueue(7);
    Q.Print();
    cout << endl << endl;

    cout << "deQueue : " << endl;
    int dequeue = Q.DeQueue();
    Q.Print();
    cout << endl;
    cout << "dequeue value : " << dequeue << endl;
    cout << endl;

    cout << "deQueue : " << endl;
    int dequeue2 = Q.DeQueue();
    Q.Print();
    cout << endl;
    cout << "dequeue value : " << dequeue2 << endl;
    cout << endl;

    cout << "deQueue : " << endl;
    int dequeue3 = Q.DeQueue();
    Q.Print();
    cout << endl;
    cout << "dequeue value : " << dequeue3 << endl;
    cout << endl;

    cout << "deQueue : " << endl;
    int dequeue4 = Q.DeQueue();
    Q.Print();
    cout << endl;
    cout << "dequeue value : " << dequeue4 << endl;
    cout << endl;

    cout << "is queue empty? :" << endl;
    if(Q.Empty())
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    cout << endl << endl;
    return 0;
}
