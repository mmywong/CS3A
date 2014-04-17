#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include "polygon.h"

class glWidget : public QGLWidget
{
   Q_OBJECT //needed if we want to make something a slot?
public:
   glWidget();
   polygon* plist;
public slots:
   void initializeGL(); // already included in the library but we want to redefine it
   void paintGL();
   void resizeGL(int w, int h);
};

#endif // GLWIDGET_H
