#ifndef MYGUI_H
#define MYGUI_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QGLWidget>
//#include <iostream>

class mygui : public QWidget
{
   Q_OBJECT // q_object is a macro
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

   QGLWidget *glwidget;
//    QTextEdit *textArea;
};

#endif // MYGUI_H
