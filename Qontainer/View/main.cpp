#include "mainwindow.h"
#include<QMainWindow>
#include<QApplication>
#include<QWidget>

int main(int argc, char *argv[])
{
 QApplication Qontainer(argc,argv);
    MainWindow * main=new MainWindow();
    main->show();
    Qontainer.exec();
    return 0;
}
