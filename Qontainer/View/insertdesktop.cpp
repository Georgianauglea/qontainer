#include"insertdesktop.h"

InsertDesktop::InsertDesktop(QWidget* parent){
    layD=new QGridLayout(parent);
    send=new QPushButton("Invia");

    type=new QLabel("DESKTOP");
    cpu=new QLabel("CPU");
    ram=new QLabel("RAM");
    marca=new QLabel("Marca");
    modello=new QLabel("Modello");
    hardisk=new QLabel("Hardisk");
    SO=new QLabel("Sistema operativo");
    Tipologia=new QLabel("Tipologia Computer");
    wattMin=new QLabel("Numero watt");
    nHard= new QLabel("Numero Hardisk");
    uso=new QLabel("Tipo di uso");

    c=new QDoubleSpinBox(this);
    c->setRange(0.00,100.00);
    r=new QSpinBox(this);
    r->setRange(0,100);
    ma=new QLineEdit(this);
    mo=new QLineEdit(this);
    hd=new QLineEdit(this);
    SiO=new QLineEdit(this);
    ty=new QLineEdit(this);
    wM=new QDoubleSpinBox(this);
    wM->setRange(0.00,500.00);
    nH=new QSpinBox(this);
    nH->setRange(0,30);
    u=new QLineEdit(this);

    layD->addWidget(type,0,2);
    layD->addWidget(cpu,2,0);
    layD->addWidget(c,3,0);
    layD->addWidget(ram,4,0);
    layD->addWidget(r,5,0);
    layD->addWidget(marca,6,0);
    layD->addWidget(ma,7,0);
    layD->addWidget(modello,8,0);
    layD->addWidget(mo,9,0);
    layD->addWidget(hardisk,10,0);
    layD->addWidget(hd,11,0);
    layD->addWidget(SO,12,0);
    layD->addWidget(SiO,13,0);

    layD->addWidget(Tipologia,2,2);
    layD->addWidget(ty,3,2);
    layD->addWidget(wattMin,4,2);
    layD->addWidget(wM,5,2);
    layD->addWidget(nHard,6,2);
    layD->addWidget(nH,7,2);
    layD->addWidget(uso,8,2);
    layD->addWidget(u,9,2);
    layD->addWidget(send,13,2);
    setLayout(layD);

    connect(send,SIGNAL(clicked()),this,SLOT(insertDesk()));
}

void InsertDesktop::insertDesk(){
    fatta=new QMessageBox();
    if(ma->text()!="" && mo->text()!=""){
    desk=new Desktop();
    desk->setCPU((c->value()));
    desk->setRAM(r->value());
    desk->setMarca(ma->text().toStdString());
    desk->setModello(mo->text().toStdString());
    desk->setHardisk(hd->text().toStdString());
    desk->setSO(SiO->text().toStdString());
    desk->setTipologia((ty->text()).toStdString());
    desk->setWattMin((wM->value()));
    desk->setUso(u->text().toStdString());
    desk->setNHard(nH->value());

    cont=new Container<Device*>(desk);

    XMLUtility::saveDevices(cont);
    fatta->setText("Inserimento riuscito.");
    fatta->show();
    window()->close();

    }else{
            fatta->setText("Inseririre almeno Marca e Modello");
            fatta->show();
        }
}
