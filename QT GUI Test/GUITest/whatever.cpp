#include "whatever.h"
#include "GL/glu.h"

whatever::whatever(QWidget *parent) :
    QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    A = Square(0.1,2.0,coord(3,4));
}

void whatever::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // colors the screen
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void whatever::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glColor3d(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2d(A.UPCorner.x, A.UPCorner.y);
    glVertex2d(A.UPCorner.x + A.a, A.UPCorner.y);
    glVertex2d(A.UPCorner.x + A.a, A.UPCorner.y + A.b);
    glVertex2d(A.UPCorner.x, A.UPCorner.y+A.b);
    glEnd();
}

void whatever::resizeGL(int width, int height)
{
    glViewport(0, 0, (GLint)width, (GLint) height);
    gluOrtho2D(0,10,10,0); // changes or resizes the window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 1.0f, 100.0f);
}
