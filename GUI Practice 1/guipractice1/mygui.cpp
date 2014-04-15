#include "mygui.h"

mygui::mygui()
{
    exitButton = new QPushButton("Exit");
    saveButton = new QPushButton("Save");
    loadButton = new QPushButton("Load");
    textArea = new QTextEdit;

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(exitButton);
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(loadButton);

    QVBoxLayout *overall = new QVBoxLayout; //to have text on top and buttons at the bottom


    overall->addWidget(textArea);
    overall->addLayout(buttonLayout);

    setLayout(overall);





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
}
