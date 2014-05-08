#include "mygui.h"

mygui::mygui()
{
    exitButton = new QPushButton("Exit");
    saveButton = new QPushButton("Save");
    loadButton = new QPushButton("Load");
    glwidget = new glWidget;

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(exitButton);
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(loadButton);

    QVBoxLayout *overall = new QVBoxLayout;
    overall->addWidget(glwidget);
    overall->addLayout(buttonLayout);

    setLayout(overall);

    connect(exitButton, SIGNAL(clicked()),
            this, SLOT(close()));

    connect(saveButton, SIGNAL(clicked()),
            this, SLOT(Save()));

    connect(this, SIGNAL(actionSignal()),
            this, SLOT(Action()));

    glwidget->setMinimumSize(100, 100);
}

void mygui::Save()
{
    cout<<"I'm saving"<<endl;
    emit actionSignal();
}

void mygui::Action()
{
    cout<<"Action is happening"<<endl;
}
