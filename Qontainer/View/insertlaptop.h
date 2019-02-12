#ifndef INSERTLAPTOP_H
#define INSERTLAPTOP_H

#include<QWidget>
#include<QLabel>
#include<QMessageBox>
#include"xmlutility.h"
#include"Model/container.h"
#include"Model/laptop.h"
#include<QPushButton>
#include<QSpinBox>
#include<QDoubleSpinBox>
#include<QLineEdit>
#include<QGridLayout>
class InsertLaptop:public QWidget{
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
           *batteria,
           *pollici,
           *peso;
    QLineEdit *ma,
              *mo,
              *hd,
              *SiO,
              *ty;
    QSpinBox *r;
    QDoubleSpinBox *c,
                   *batt,
                   *poll,
                   *pes;
    QPushButton * send;
    QMessageBox * fatta;
    Laptop * lap;
    Container<Device*>* cont;
public:
    InsertLaptop(QWidget* =nullptr);
public slots:
    void insertLap();
};

#endif // INSERTLAPTOP_H
