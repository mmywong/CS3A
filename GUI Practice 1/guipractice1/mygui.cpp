#include "mygui.h"
#include <iostream>

using namespace std;

mygui::mygui()
{
   exitButton = new QPushButton("Exit");
   saveButton = new QPushButton("Save");
   loadButton = new QPushButton("Load");
   glwidget = new QGLWidget;
//    textArea = new QTextEdit;

   QHBoxLayout *buttonLayout = new QHBoxLayout;
   buttonLayout->addWidget(exitButton);
   buttonLayout->addWidget(saveButton);
   buttonLayout->addWidget(loadButton);

   QVBoxLayout *overall = new QVBoxLayout; //to have text on top and buttons at the bottom


   overall->addWidget(glwidget);
   overall->addLayout(buttonLayout);

   setLayout(overall);

   connect(exitButton, SIGNAL(clicked()), this, SLOT(close())); // this refers to this window. so receiving object will be this window

   connect(saveButton, SIGNAL(clicked()), this, SLOT(Save()));
   connect(this, SIGNAL(actionSignal()), this, SLOT(Action()));

   glwidget->setMinimumSize(100,100);
}

void mygui::Save()
{
   cout<< "I'm saving" << endl;
   emit actionSignal(); // emit sends out signal
}

void mygui::Action()
{
   cout<<"Action is happening"<<endl;
}
   /*
   QPushButton *helloButton = new QPushButton;

   helloButton->setText("hello");
//    helloButton->resize(400, 300); // no longer needed because automatically set

   QPushButton *byeButton = new QPushButton("bye");

   QWidget *widget = new QWidget;

   QHBoxLayout *layout = new QHBoxLayout;
   layout->addWidget(helloButton);
   layout->addWidget(byeButton);

   //why no need & anymore?
   widget->setLayout(layout);

   QObject::connect(helloButton, SIGNAL(clicked()), widget, SLOT(close())); //1st :sending obj, 2nd:signal, 3rd: receiving obj, 4th : slot
   QObject::connect(byeButton, SIGNAL(clicked()), helloButton, SLOT(close()));

   QLabel label("label");

   label.show();

   widget->show();
//    byeButton.show(); // no longer needed because we have added these buttons to widget/layout
//    helloButton.show();



   delete widget; // cleans up buttons' memory
*/
