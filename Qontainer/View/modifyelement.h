#ifndef MODIFYELEMENT
#define MODIFYELEMENT

#include<QWidget>
#include<QGridLayout>
#include<QLabel>
#include<QListWidget>
#include<QCheckBox>
#include<QPushButton>
#include<QLabel>
#include<QSpinBox>
#include<QDoubleSpinBox>
#include<QLineEdit>
#include<QComboBox>
#include"Model/container.h"
#include"Model/desktop.h"
#include"Model/laptop.h"
#include"Model/smartphone.h"
#include"Model/tablet.h"
#include"xmlutility.h"
#include"QMessageBox"

class ModifyElement:public QWidget{
Q_OBJECT
private:
    QWidget *centralWidget;
    QGridLayout *lay;
    QLabel *title;
    QListWidget * list;
    QComboBox* scelta;
    Container<Device*>* cont;
    QListWidgetItem* oggetto;
    QMessageBox * mess;
    QPushButton * send;
    QDoubleSpinBox* c;
    QSpinBox* r;
    QLineEdit* ma;
    QLineEdit* mo;
    QLineEdit* hd;
    QLineEdit* SiO;

    QLineEdit* ty;
    QDoubleSpinBox* wM;
    QSpinBox* nH;
    QLineEdit* u;

    QLineEdit* ti;
    QDoubleSpinBox* batte;
    QDoubleSpinBox* polli;
    QDoubleSpinBox* peso;

    QDoubleSpinBox* batteria;
    QDoubleSpinBox* pollici;
    QDoubleSpinBox* fotocamera;
    QSpinBox* memoria;
    QLineEdit* colore;
    QLineEdit* co;

    QDoubleSpinBox* batter;
    QDoubleSpinBox* pollic;
    QDoubleSpinBox* fotocamera1;
    QSpinBox* memoria1;
    QLineEdit* colore1;

    QLineEdit *sim;
public:
    ModifyElement(QWidget * =nullptr);
  signals:
   void deleteFirstView();

public slots:
    void showmodify(QListWidgetItem*);
    void modify();
    void deleteItems();
};

#endif // MODIFYELEMENT

