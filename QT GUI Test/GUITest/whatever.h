
#ifndef WHATEVER_H
#define WHATEVER_H

#include <QGLWidget>

class whatever : public QGLWidget
{
    Q_OBJECT
public:
    explicit whatever(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    square A;
signals:

public slots:

};

#endif // WHATEVER_H
