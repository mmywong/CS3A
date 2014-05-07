#ifndef MYPANELOPENGL_H
#define MYPANELOPENGL_H
#include "constants.h"
#include "terrorist.h"
#include "counterterrorist.h"
#include "map.h"
#include <QGLWidget>
#include <Qtimer>
#include <QKeyEvent>
#include <QResizeEvent>
const int max_col = 59;
const int max_row = 59;

class MyPanelOpenGL : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyPanelOpenGL(QWidget *parent = 0);

signals:


protected:
    void initializeGL();
    void paintGL();
    void keyPressEvent(QKeyEvent *e);
    void run();
    void stop();
    void resizeGL(int width, int height);
    int conv_x_j(int x);
    int conv_y_i(int y);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);

 private slots:
    void process();
    void clicktostart();
    void pause();
//    void glider();
//    void pulsar();
//    void gosper();
    void clear();
//    void random();
    void save();
    void loadlastsave();
    void reset();

private:
    Map dust;
    int world[maxrow][maxcol];
    int world2[maxrow][maxcol];
    float r;
    float x, y;
    float mouse_x, mouse_y;
    float glWidth;
    float glHeight;
    int   gridWidth;//size of array
    int   gridHeight;//size of array
    float boxHeight;
    float boxWidth;
//    int cell[size][size];
    QTimer* timer;
};

#endif // MYPANELOPENGL_H
