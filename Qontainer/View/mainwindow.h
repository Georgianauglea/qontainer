#ifndef MAINWINDOW
#define MAINWINDOW

#include"inseriscitablet.h"
#include"inseriscismartphone.h"
#include"insertdesktop.h"
#include"insertlaptop.h"
#include"seachelement.h"
#include"modifyelement.h"
#include"deleteelement.h"
#include"./Model/container.h"
#include"xmlutility.h"
#include<QMainWindow>
#include<QWidget>
#include<QListWidget>
#include<QGridLayout>
#include<QPushButton>
#include<QLabel>

class MainWindow : public QMainWindow{
Q_OBJECT
private:
    QGridLayout *winLayout;
    QLabel *title;
    QPushButton *inseriscis,*inseriscid,*inseriscit,*inseriscil;
    QPushButton *ricerca;
    QWidget *centralWidget;
    QPushButton *elimina;
    QPushButton *modifica;
    QPushButton *aggiorna;
    QLabel *titles;
    InsertTablet * t;
    InsertDesktop *d;
    InsertLaptop *l;
    InsertSmartphone *s;
    DeleteElement * del;
    ModifyElement * modify;
    SearchElement * search;
    QListWidget * list;
    Container<Device*>* cont;

public:
    MainWindow(QWidget *parent = nullptr);

signals:
    void tipologiaDevice(Device*);
  public slots:
    void showInsertD();
    void showInsertL();
    void showInsertS();
    void showInsertT();
    void showModify();
    void showDelete();
    void refresh();

    void showDetail(QListWidgetItem*);
    void showSearch();   
};

#endif // MAINWINDOW

