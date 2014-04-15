#ifndef MYGUI_H
#define MYGUI_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>

class mygui : public QWidget
{
public:
    mygui();

private:
    QPushButton *exitButton;
    QPushButton *saveButton;
    QPushButton *loadButton;

    QTextEdit *textArea;
};

#endif // MYGUI_H
