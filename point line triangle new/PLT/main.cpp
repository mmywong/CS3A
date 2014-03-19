#include <iostream>
#include "point.h"
#include "line.h"
#include "triangle.h"

using namespace std;

int main()
{
    int ax, ay, bx, by , cx, cy;


    cout << "~~~~~Line Generator~~~~~" << endl << endl;
    cout << "Point A : " << endl;
    cin >> ax >> ay;
    cout << "(" << ax << "," << ay << ")" << endl<< endl;
    cout << "Point B : " << endl;
    cin >> bx >> by;
    cout << "(" << bx << "," << by << ")" << endl<< endl;

    point a(ax,ay);
    point b(bx,by);

    line myline(a,b);

    cout << "equation : y = " << myline.slope() << "x + " << myline.y_intercept() << endl << endl;
    cout <<"length : "<< myline.length() << endl;
    cout <<"slope : " << myline.slope() << endl;
    cout <<"y-intercept : ("<< myline.y_intercept() << ",0)" << endl;
    cout <<"x-intercept : (0," << myline.x_intercept() << ")" << endl;

    cout << endl << endl << endl;

    cout << "~~~~~Triangle Generator~~~~" << endl << endl;
    cout << "Point A : " << endl;
    cin >> ax >> ay;
    cout << "(" << ax << "," << ay << ")" << endl << endl;
    cout << "Point B : " << endl;
    cin >> bx >> by;
    cout << "(" << bx << "," << by << ")" << endl << endl;
    cout << "Point C : " << endl;
    cin >> cx >> cy;
    cout << "(" << cx << "," << cy << ")" << endl << endl;

    point A(ax,ay);
    point B(bx,by);
    point C(cx,cy);

    line AB(A,B);
    line BC(B,C);
    line CA(C,A);

    triangle ABC(ax,ay,bx,by,cx,cy);

    cout << "perimeter : " << ABC.perimeter() << endl;
    cout << "area : " << ABC.area() << endl;
    cout << "angle at point A : " << ABC.angle(BC,AB,CA) << endl;
    cout << "angle at point B : " << ABC.angle(CA,BC,AB) << endl;
    cout << "angle at point C : " << ABC.angle(AB,BC,CA) << endl;

    cout << "equiangular : ";
    if(ABC.equiangular() == true)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    cout << "isoceles : ";
    if(ABC.isoceles() == true)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    cout << "right triangle : ";
    if(ABC.righttriangle() == true)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    cout << endl << endl;

    return 0;
}

