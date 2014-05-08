#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include "csmap.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_released();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
