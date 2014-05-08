#ifndef MYGUI_H
#define MYGUI_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QGLWidget>
#include <iostream>
using namespace std;
#include "glwidget.h"

class mygui : public QWidget
{
    Q_OBJECT
public:
    mygui();

signals:
    void actionSignal();

public slots:
    void Save();
    void Action();

private:
    QPushButton *exitButton;
    QPushButton *saveButton;
    QPushButton *loadButton;

    glWidget *glwidget;
};

#endif // MYGUI_H
