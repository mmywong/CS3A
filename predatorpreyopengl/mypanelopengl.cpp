#include <QDebug>
#include "GL/glu.h"
#include <cmath>
#include <iostream>
#include "terrorist.h"
#include "counterterrorist.h"
#include "csmap.h"
#include "mypanelopengl.h"
using namespace std;

MyPanelOpenGL::MyPanelOpenGL(QWidget *parent) :
    QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    timer=NULL;
    r=0;
//    csmap dust;
//    dust.initialize();
//    dust.random();
//    dust.show();
//    dust.read("configfile.txt");
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
    dust.initialize();
//    cout << "init" << endl;
    dust.random();
//    cout << "random" << endl;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //    static float i(0.01),j(0.007);

    for(int i=0; i<maxrow; i++)
    {
        for(int j=0; j<maxcol; j++)
        {
            x = -0.9 + (1.9/maxcol)*j;
            y = 0.9 - (1.9/maxrow)*i;

        if(dust.world[i][j]->identity == 'c')
            glColor3f(0.0f, 0.6f, 0.55f);
        else if (dust.world[i][j]->identity == 't')
            glColor3f(0.0f, 1.0f, 1.0f);
        else
            glColor3f(0.0f, 0.0f, 0.0f);

        glBegin(GL_QUADS);
          glVertex2f(x,y);                           //top left hand corner
          glVertex2f(x+(1.9/maxcol), y);             //top right hand corner
          glVertex2f(x+(1.9/maxcol), y+(1.9/maxrow)); //bottom right hand corner
          glVertex2f(x, y+(1.9/maxrow));             //bottom left hand corner
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
    return (x/( (geometry().bottomRight().x()) /maxcol)) +1.0;
    cout<<"x:"<<(x/( (geometry().bottomRight().x()) /maxcol)) + 1.0<<endl;
}
int MyPanelOpenGL::conv_y_i(int y)
{
    return (y/( (geometry().bottomRight().y()) /maxrow)) + 1.0;
    cout<<"y:"<<(y/( (geometry().bottomRight().y()) /maxrow)) + 1.0<<endl;
}

//void MyPanelOpenGL::mousePressEvent(QMouseEvent *e)
//{
//    csmap dust;
//    if (e->button() == Qt::LeftButton)
//    {
//        int j = conv_x_j(mouse_x);
//        int i = conv_y_i(mouse_y);

//        //just for the sake of keeping old code although doesn't make sense
//        if(dust.world[i][j]->identity == NULL)
//            dust.world[i][j]->identity = 'c';
//        else
//            dust.world[i][j]->identity = 't';
//    }
//    repaint();
//    updateGL();
//}

//void MyPanelOpenGL::mouseMoveEvent(QMouseEvent *e)
//{
//      mouse_x = e->x();
//      mouse_y = e->y();
//      cout<<"mouse x:"<<mouse_x<<endl;
//      cout<<"mouse y:"<<mouse_y<<endl;
//}


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

//void MyPanelOpenGL::clear()
//{
//    csmap dust;
//    dust.initialize();
////    dust.random();
////    dust.show();
////    init(world);
//    process();
//}

//void MyPanelOpenGL::random()
//{
//    csmap dust;
//    dust.random();
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

//void MyPanelOpenGL::clicktostart()
//{
//    run();
//}

//void MyPanelOpenGL::pause()
//{
//    stop();
//}

//void MyPanelOpenGL::save()
//{
//    dust.save();
//    savefile(world);
//}

//void MyPanelOpenGL::loadlastsave()
//{
//    dust.read("savefile.txt");
//    readfile(world, 1, 1, "savefile.txt");
//    paintGL();
//    repaint();
//    updateGL();
//}

//void MyPanelOpenGL::reset()
//{
//    dust.read("configfile.txt");
//    readfile(world, 1, 1, "configfile.txt");
//    paintGL();
//    repaint();
//    updateGL();
//}
