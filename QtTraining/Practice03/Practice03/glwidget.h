#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

class glWidget : public QGLWidget
{
    Q_OBJECT
public:
    glWidget();

public slots:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

};

#endif // GLWIDGET_H
