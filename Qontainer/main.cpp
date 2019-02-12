#include "mainwindow.h"
#include<QMainWindow>
#include<QApplication>
#include<QWidget>

int main(int argc, char *argv[])
{
    QApplication Qontainer(argc,argv);
    MainWindow* mainWindow=new MainWindow();
    mainWindow->show();

    Qontainer.exec();
}
