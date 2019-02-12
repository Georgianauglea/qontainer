#ifndef INSERISCISMARTPHONE_H
#define INSERISCISMARTPHONE_H

#include<xmlutility.h>
#include<QMessageBox>
#include"./Model/smartphone.h"
#include"./Model/container.h"
#include<QWidget>
#include<QLabel>
#include<QGridLayout>
#include<QPushButton>
#include<QLineEdit>
#include<QSpinBox>
#include<QDoubleSpinBox>

class InsertSmartphone:public QWidget{
Q_OBJECT
public:
    QWidget* central;
    QGridLayout*layD;

    QLabel *type,
           *cpu,
           *ram,
           *marca,
           *modello,
           *hardisk,
           *batteria,
           *pollici,
           *fotocamera,
           *memoria,
           *colore,
           *SO,
           *si;
    QLineEdit *ma,
              *mo,
              *hd,
              *col,
              *SiO;
    QDoubleSpinBox *c,
                   *batt,
                   *poll,
                   *foto;
    QSpinBox *r,
             *mem;
    QPushButton* send;
    QLineEdit * sim;
    Smartphone* smart;
    Container<Device*>* smartphone;
    QMessageBox * fatta;
public:
    InsertSmartphone(QWidget* =nullptr);
public slots:
    void insertSmart();
};
#endif // INSERISCISMARTPHONE_H
