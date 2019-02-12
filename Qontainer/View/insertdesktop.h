#ifndef INSERTDESKTOP_H
#define INSERTDESKTOP_H

#include<QWidget>
#include<QLabel>
#include<QMessageBox>
#include"Model/container.h"
#include"Model/desktop.h"
#include"xmlutility.h"
#include<QPushButton>
#include<QSpinBox>
#include<QDoubleSpinBox>
#include<QLineEdit>
#include<QGridLayout>
class InsertDesktop:public QWidget{
Q_OBJECT
private:
    QWidget* central;
    QGridLayout* layD;
    QLabel *type,
           *cpu,
           *ram,
           *marca,
           *modello,
           *hardisk,
           *SO,
           *Tipologia,
           *wattMin,
           *nHard,
           *uso;
    QLineEdit *ma,
              *mo,
              *hd,
              *SiO,
              *ty,
              *u;
    QSpinBox *r,
             *nH;
    QDoubleSpinBox *c,
                   *wM;
    QPushButton * send;
    Container<Device*>* cont;
    Desktop* desk;
    QMessageBox* fatta;
public:
    InsertDesktop(QWidget* =nullptr);
public slots:
    void insertDesk();
};

#endif // INSERTDESKTOP_H
