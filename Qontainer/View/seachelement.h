#ifndef SEACHELEMENT_H
#define SEACHELEMENT_H

#include<QWidget>
#include<QGridLayout>
#include<QLabel>
#include<QListWidget>
#include<QComboBox>
#include<QLineEdit>
#include<QPushButton>
#include"Model/container.h"
#include"Model/desktop.h"
#include"Model/laptop.h"
#include"Model/smartphone.h"
#include"Model/tablet.h"
#include"xmlutility.h"
#include"QMessageBox"

class SearchElement:public QWidget{
Q_OBJECT
private:
    QWidget *centralWidget;
    QGridLayout *lay;
    QLabel *title;
    QListWidget * list;
    QComboBox* tipo;
    QComboBox* campo;
    QLineEdit* valore;
    Container<Device*>* cont;
    QMessageBox * mess;
    QPushButton * send;
public:
    SearchElement(QWidget * =nullptr);
    ~SearchElement()=default;
public slots:
    void searchType();
};

#endif // SEACHELEMENT_H
