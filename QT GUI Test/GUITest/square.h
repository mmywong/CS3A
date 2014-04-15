#ifndef SQUARE_H
#define SQUARE_H

#include <QWidget>

class square : public QWidget
{
    Q_OBJECT
public:
    explicit square(QWidget *parent = 0);

signals:

public slots:
    coord upperleft;
    int length;
    int width;
};

struct coord
{
    coord(int X=0, int Y=0)
    {
        x = X;
        y = Y;
    }

    int x;
    int y;
};

#endif // SQUARE_H
