#ifndef INSERISCITABLET_H
#define INSERISCITABLET_H

#include<QWidget>
#include<QLabel>
#include<QGridLayout>
#include<QPushButton>
#include<QLineEdit>
#include"Model/container.h"
#include"xmlutility.h"
#include"Model/tablet.h"
#include<QMessageBox>
#include<QSpinBox>
#include<QDoubleSpinBox>
#include<QCheckBox>
class InsertTablet:public QWidget{
Q_OBJECT
private:
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
           *SO;
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
    QCheckBox * sim;
    Container<Device*>* cont;
    Tablet* tab;
    QMessageBox * fatta;

public:
    InsertTablet(QWidget* =nullptr);
public slots:
    void insertTab();
};
#endif // INSERISCITABLET_H
