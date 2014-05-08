#include <QDebug>
#include "GL/glu.h"
#include <cmath>
#include <iostream>
#include "terrorist.h"
#include "counterterrorist.h"
#include "map.h"
#include "constants.h"

using namespace std;

MyPanelOpenGL::MyPanelOpenGL(QWidget *parent) :
    QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    timer=NULL;
    r=0;
    dust.init();
    dust.read("configfile.txt");
}

void MyPanelOpenGL::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void MyPanelOpenGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //    static float i(0.01),j(0.007);

    for(int i=1; i<maxrow-1; i++)
    {
        for(int j=1; j<maxcol-1; j++)
        {
            x = -1.0 + (2.0/maxcol)*j;
            y = 1.0 - (2.0/maxrow)*i;

        if(dust.world[i][j]->identity == 'c')
            glColor3f(0.0f, 0.6f, 0.55f);
        else if (dust.world[i][j]->identity == 't')
            glColor3f(0.0f, 0.1f, 0.3f);
        else
            glColor3f(0.0f, 0.0f, 0.0f);

        glBegin(GL_QUADS);
          glVertex2f(x,y);                           //top left hand corner
          glVertex2f(x+(2.0/max_col), y);             //top right hand corner
          glVertex2f(x+(2.0/max_col), y+(2.0/max_row)); //bottom right hand corner
          glVertex2f(x, y+(2.0/max_row));             //bottom left hand corner
        glEnd();

        }
    }
}

void MyPanelOpenGL::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_Down:
        run();
        break;
    case Qt::Key_Up:
        stop();
        break;
    }
}

int MyPanelOpenGL::conv_x_j(int x)
{
    return (x/( (geometry().bottomRight().x()) /max_col)) +1.0;
    cout<<"x:"<<(x/( (geometry().bottomRight().x()) /max_col)) + 1.0<<endl;
}
int MyPanelOpenGL::conv_y_i(int y)
{
    return (y/( (geometry().bottomRight().y()) /max_row)) + 1.0;
    cout<<"y:"<<(y/( (geometry().bottomRight().y()) /max_row)) + 1.0<<endl;
}

void MyPanelOpenGL::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        int j = conv_x_j(mouse_x);
        int i = conv_y_i(mouse_y);

        if(world[i][j] == 0)
            world[i][j] = 1;
        else
            world[i][j] = 0;
    }
    repaint();
    updateGL();
}

void MyPanelOpenGL::mouseMoveEvent(QMouseEvent *e)
{
      mouse_x = e->x();
      mouse_y = e->y();
      cout<<"mouse x:"<<mouse_x<<endl;
      cout<<"mouse y:"<<mouse_y<<endl;
}


void MyPanelOpenGL::run()
{
    if(!timer)
    {
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(process()));
        timer->start(100);
    }
}

void MyPanelOpenGL::stop()
{
    if(timer)
    {
        delete timer;
        timer = NULL;
    }
}

void MyPanelOpenGL::process()
{
    paintGL();
    dust.step();
    repaint();
    updateGL();
}

void MyPanelOpenGL::clear()
{
    dust.init();
//    init(world);
    process();
}

//void MyPanelOpenGL::random()
//{
//    Random(world);
//    process();
//}

//void MyPanelOpenGL::glider()
//{
//    readfile(world, 1, 1, "glider.txt");
//    process();
//}

//void MyPanelOpenGL::pulsar()
//{
//    readfile(world, 1, 1, "pulsar.txt");
//    process();
//}

//void MyPanelOpenGL::gosper()
//{
//    readfile(world, 1, 1, "gosper.txt");
//    process();
//}

void MyPanelOpenGL::resizeGL(int width, int height)
{
    glViewport( 0, 0, (GLint)width,(GLint) height );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 45.0f,(GLfloat)width/(GLfloat)height,1.0f, 50.0f );

}

void MyPanelOpenGL::clicktostart()
{
    run();
}

void MyPanelOpenGL::pause()
{
    stop();
}

void MyPanelOpenGL::save()
{
    dust.save();
//    savefile(world);
}

void MyPanelOpenGL::loadlastsave()
{
    dust.read("savefile.txt");
//    readfile(world, 1, 1, "savefile.txt");
    paintGL();
    repaint();
    updateGL();
}

void MyPanelOpenGL::reset()
{
    dust.read("configfile.txt");
//    readfile(world, 1, 1, "configfile.txt");
    paintGL();
    repaint();
    updateGL();
}
