#include <iostream>
using namespace std;
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    QPushButton *helloButton = new QPushButton;
    helloButton->setText("hello");

    QPushButton *byeButton = new QPushButton("bye");

    QWidget *widget = new QWidget;

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(helloButton);
    layout->addWidget(byeButton);

    widget->setLayout(layout);

    QObject::connect(helloButton, SIGNAL(clicked()), widget, SLOT(close()));
    QObject::connect(byeButton, SIGNAL(clicked()), helloButton, SLOT(close()));

    QLabel label("I'm a label");

    label.show();

    widget->show();

    app.exec();

    delete widget;
    return 0;
}

