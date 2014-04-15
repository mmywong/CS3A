#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "mygui.h"

using namespace std;

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    mygui thegui;
    thegui.show();

    return app.exec();
}

