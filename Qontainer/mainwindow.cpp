#include "mainwindow.h"
#include<iostream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    setWindowTitle("Magazzino Devices");
    setFixedSize(600,200);
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    winLayout = new QGridLayout(centralWidget);


    title=new QLabel("Magazzino Devices");
    inserisci=new QPushButton("Inserisci elemento");
    ricerca=new QPushButton("Ricerca");
    elimina=new QPushButton("Elimina");
    show =new QPushButton("Mostra elenco");
    modifica=new QPushButton("Modifica");

    winLayout->addWidget(title);
    winLayout->addWidget(inserisci);
    winLayout->addWidget(ricerca);
    winLayout->addWidget(show);
    winLayout->addWidget(modifica);
    winLayout->addWidget(elimina);



}
