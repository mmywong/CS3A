#ifndef POINT_H
#define POINT_H

class Point
{
public:
    // CONSTRUCTORS
    Point();
    Point(int new_x, int new_y);
    int GetX();
    int GetY();
    void SetX(int new_x);
    void SetY(int new_y);
    void Set(int new_x, int new_y);
    void Show();
    double distance(Point A); // any point

private:
    int x;
    int y;
};

#endif // POINT_H
