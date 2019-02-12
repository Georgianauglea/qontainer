#include"insertlaptop.h"
InsertLaptop::InsertLaptop(QWidget* parent){
    layD=new QGridLayout(parent);
    send=new QPushButton("Invia");

    type=new QLabel("LAPTOP");
    cpu=new QLabel("CPU");
    ram=new QLabel("RAM");
    marca=new QLabel("Marca");
    modello=new QLabel("Modello");
    hardisk=new QLabel("Hardisk");
    SO=new QLabel("Sistema operativo");
    Tipologia=new QLabel("Tipologia Computer");
    batteria=new QLabel("Batteria");
    pollici=new QLabel("Pollici");
    peso=new QLabel("Peso");

    c=new QDoubleSpinBox(this);
    c->setRange(0.00,100.00);
    r=new QSpinBox(this);
    r->setRange(0,100);
    ma=new QLineEdit(this);
    mo=new QLineEdit(this);
    hd=new QLineEdit(this);
    SiO=new QLineEdit(this);
    ty=new QLineEdit(this);
    batt=new QDoubleSpinBox(this);
    batt->setRange(0.00,10000.00);
    poll=new QDoubleSpinBox(this);
    poll->setRange(0.00,100.00);
    pes=new QDoubleSpinBox(this);
    pes->setRange(0.00,1000.00);

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
    layD->addWidget(batteria,4,2);
    layD->addWidget(batt,5,2);
    layD->addWidget(pollici,6,2);
    layD->addWidget(poll,7,2);
    layD->addWidget(peso,8,2);
    layD->addWidget(pes,9,2);
    layD->addWidget(send,13,2);
    setLayout(layD);

    connect(send,SIGNAL(clicked()),this,SLOT(insertLap()));
}

void InsertLaptop::insertLap(){
    fatta=new QMessageBox();
    if(ma->text()!="" && mo->text()!=""){
    lap=new Laptop();
    lap->setCPU((c->value()));
    lap->setRAM(r->value());
    lap->setMarca(ma->text().toStdString());
    lap->setModello(mo->text().toStdString());
    lap->setHardisk(hd->text().toStdString());
    lap->setSO(SiO->text().toStdString());
    lap->setTipologia((ty->text()).toStdString());
    lap->setBatteria((batt->value()));
    lap->setPeso(pes->value());
    lap->setPollici(poll->value());

    cont=new Container<Device*>(lap);

    XMLUtility::saveDevices(cont);
    fatta->setText("Inserimento riuscito.");
    fatta->show();
    window()->close();
    }else{
        fatta->setText("Inserire almeno Marca e Modello.");
        fatta->show();
    }
}
