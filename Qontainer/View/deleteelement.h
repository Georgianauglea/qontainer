#ifndef DELETEELEMENT_H
#define DELETEELEMENT_H

#include<QWidget>
#include<QGridLayout>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QComboBox>
#include"Model/container.h"
#include"Model/desktop.h"
#include"Model/laptop.h"
#include"Model/smartphone.h"
#include"Model/tablet.h"
#include"xmlutility.h"
#include<QMessageBox>

class DeleteElement:public QWidget{
Q_OBJECT
private:
    QWidget *centralWidget;
    QGridLayout *lay;
    QLabel *title;
    QComboBox* scelta;
    QComboBox* tipo;
    QLineEdit * valore;
    Container<Device*>* cont;
    QMessageBox * mess;
    QPushButton * send;
public:
    DeleteElement(QWidget * =nullptr);

public slots:
  void eraseElement();
};

#endif // DELETEELEMENT_H
