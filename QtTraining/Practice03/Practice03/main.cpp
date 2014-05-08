#include <iostream>
using namespace std;
#include "mygui.h"
#include <QApplication>
#include "glwidget.h"

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    mygui thegui;
    thegui.show();


    return app.exec();
}

