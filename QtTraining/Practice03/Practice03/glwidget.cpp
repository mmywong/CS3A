
#include "glwidget.h"

glWidget::glWidget()
{
}

void glWidget::initializeGL()
{
    glClearColor(0, 0, 0, 0);
}

void glWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0, 0);

    glBegin(GL_QUADS);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(-0.5, 0.5, 0);
        glVertex3f(0.5, 0.5, 0);
        glVertex3f(0.5, -0.5, 0);
    glEnd();
}

void glWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}
