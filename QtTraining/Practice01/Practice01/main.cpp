#include <iostream>
using namespace std;
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    QPushButton helloButton;
    helloButton.setText("hello");
    helloButton.resize(400, 300);

    QPushButton byeButton("bye");

    QWidget widget;

    QHBoxLayout layout;
    layout.addWidget(&helloButton);
    layout.addWidget(&byeButton);

    widget.setLayout(&layout);


    widget.show();

    return app.exec();
}

