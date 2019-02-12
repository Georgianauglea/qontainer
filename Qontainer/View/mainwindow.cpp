#include "mainwindow.h"
#include<iostream>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
    setWindowTitle("Magazzino Devices");

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    winLayout = new QGridLayout(centralWidget);
    list=new QListWidget();

    QLabel* instr=new QLabel("Doppio click per visualizzare i dettagli.");
    titles=new QLabel("Lista devices");
    title=new QLabel("Magazzino Devices");
    inseriscid=new QPushButton("Inserisci Desktop");
    inseriscil=new QPushButton("Inserisci Laptop");
    inseriscis=new QPushButton("Inserisci Smartphone");
    inseriscit=new QPushButton("Inserisci Tablet");
    ricerca=new QPushButton("Ricerca");
    elimina=new QPushButton("Elimina");
    modifica=new QPushButton("Modifica");
    aggiorna=new QPushButton("Aggiorna");

    connect(inseriscid,SIGNAL(clicked()),this,SLOT(showInsertD()));
    connect(inseriscil,SIGNAL(clicked()),this,SLOT(showInsertL()));
    connect(inseriscis,SIGNAL(clicked()),this,SLOT(showInsertS()));
    connect(inseriscit,SIGNAL(clicked()),this,SLOT(showInsertT()));
    connect(ricerca,SIGNAL(clicked()),this,SLOT(showSearch()));
    connect(modifica,SIGNAL(clicked()),this,SLOT(showModify()));
    connect(elimina,SIGNAL(clicked()),this,SLOT(showDelete()));
    connect(aggiorna,SIGNAL(clicked()),this,SLOT(refresh()));

    winLayout->addWidget(title);
    winLayout->addWidget(titles);
    winLayout->addWidget(instr);
    winLayout->addWidget(list,3,0,1,2);
    winLayout->addWidget(aggiorna,1,1);
    winLayout->addWidget(inseriscid);
    winLayout->addWidget(inseriscil);
    winLayout->addWidget(inseriscis);
    winLayout->addWidget(inseriscit);

    winLayout->addWidget(ricerca);
    winLayout->addWidget(modifica);
    winLayout->addWidget(elimina);

    setFixedSize(500,300);
    cont=XMLUtility::loadDevices();


    Container<Device*>::Iterator c=cont->begin();
    int i=0;
    while (c!=cont->end()) {
        list->insertItem(i,QString::fromStdString((*c)->getMarca())+"  "+QString::fromStdString((*c)->getModello()));
        ++c;
        i++;
    }
    connect(list,SIGNAL(itemDoubleClicked(QListWidgetItem *)),this,SLOT(showDetail(QListWidgetItem*)));
}

void MainWindow::showInsertT(){
    t=new InsertTablet();
    t->show();
}

void MainWindow::showInsertD(){
    d=new InsertDesktop();
    d->show();
}

void MainWindow::showInsertL(){
    l=new InsertLaptop();
    l->show();
}

void MainWindow::showInsertS(){
    s=new InsertSmartphone();
    s->show();
}

void MainWindow::showSearch(){
    search=new SearchElement();
    search->show();
}

void MainWindow::showModify(){
    modify=new ModifyElement();
    modify->show();
}

void MainWindow::showDelete(){
    del=new DeleteElement();
    del->show();
}

void MainWindow::refresh(){
    list->clear();
    cont=XMLUtility::loadDevices();

    Container<Device*>::Iterator c=cont->begin();
    int i=0;
    while (c!=cont->end()) {
        list->insertItem(i,QString::fromStdString((*c)->getMarca())+"  "+QString::fromStdString((*c)->getModello()));
        ++c;
        i++;
    }
}

void MainWindow::showDetail(QListWidgetItem * x){
    cont=XMLUtility::loadDevices();
    Container<Device*>::Iterator it=cont->begin();
  for(int i=0; i<list->row(x)&& it!=cont->end(); i++){
        ++it;
    }
     QMessageBox * mess=new QMessageBox();
     mess->setText(QString::fromStdString((*it)->details()));
     mess->setWindowTitle(QString::fromStdString((*it)->getMarca())+"  "+QString::fromStdString((*it)->getModello()));
     mess->show();
}




