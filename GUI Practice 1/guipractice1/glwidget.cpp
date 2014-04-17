#include "glwidget.h"
#include "coord.h"

glWidget::glWidget()
{
}

void glWidget::initializeGL()
{
   glClearColor(0,0,0,0);
}

void glWidget::paintGL()
{
   glClear(GL_COLOR_BUFFER_BIT);


   //--------polygon--------//
   coord* v = new coord[4];
   v[0] = coord(-.1,-.1);
   v[1] = coord(.1,-.1);
   v[2] = coord(.1,.1);
   v[3] = coord(-.1,.1);

   polygon Poly(4,v);

   glColor3f(1,0,0); // 3f stands for 3 floats which represents RGB
   glBegin(GL_POLYGON);
       glVertex3f(Poly.vertices[0].x, Poly.vertices[0].y, 0);
       glVertex3f(Poly.vertices[0].x, Poly.vertices[0].y, 0);
       glVertex3f(Poly.vertices[0].x, Poly.vertices[0].y, 0);
       glVertex3f(Poly.vertices[0].x, Poly.vertices[0].y, 0);
//       glVertex3f(0.5, -0.5, 0);
//       glVertex3f(0.5, 0.5, 0);
//       glVertex3f(-0.5, 0.5, 0); // Q : does it matter which order the vertexes are? e.g. clockwise; A : yes
   glEnd();
//    glBegin(GL_POLYGON);
//        glVertex3f()
}

void glWidget::resizeGL(int w, int h)
{
   glViewport(0,0,w,h);
}
