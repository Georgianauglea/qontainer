#include"inseriscismartphone.h"
#include<QString>

InsertSmartphone::InsertSmartphone(QWidget* parent){
    layD=new QGridLayout(parent);
    send=new QPushButton("Invia");

    type=new QLabel("SMARTPHONE");
    cpu=new QLabel("CPU");
    ram=new QLabel("RAM");
    marca=new QLabel("Marca");
    modello=new QLabel("Modello");
    hardisk=new QLabel("Hardisk");
    SO=new QLabel("Sistema operativo");
    batteria=new QLabel("Batteria");
    pollici=new QLabel("Pollici");
    colore=new QLabel("Colore");
    fotocamera=new QLabel("Fotocamera");
    memoria=new QLabel("Memoria");

    si=new QLabel("Connettivita'");

    c=new QDoubleSpinBox(this);
    c->setRange(0.00,100.00);
    r=new QSpinBox(this);
    r->setRange(0,100);
    ma=new QLineEdit(this);
    mo=new QLineEdit(this);
    hd=new QLineEdit(this);
    SiO=new QLineEdit(this);
    batt=new QDoubleSpinBox(this);
    batt->setRange(0.00,10000.00);
    poll=new QDoubleSpinBox(this);
    poll->setRange(0.00,100.00);
    col=new QLineEdit(this);
    mem=new QSpinBox(this);
    mem->setRange(0,1000);
    foto=new QDoubleSpinBox(this);
    foto->setRange(0.00,50.00);

    sim=new QLineEdit(this);

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

    layD->addWidget(batteria,2,2);
    layD->addWidget(batt,3,2);
    layD->addWidget(pollici,4,2);
    layD->addWidget(poll,5,2);
    layD->addWidget(fotocamera,6,2);
    layD->addWidget(foto,7,2);
    layD->addWidget(memoria,8,2);
    layD->addWidget(mem,9,2);
    layD->addWidget(colore,10,2);
    layD->addWidget(col,11,2);
    layD->addWidget(si,12,2);
    layD->addWidget(sim,13,2);
    layD->addWidget(send,14,2);

    setLayout(layD);

    connect(send, SIGNAL(clicked()),this,SLOT(insertSmart()));
}

void InsertSmartphone::insertSmart(){
    fatta=new QMessageBox();
    if(ma->text()!="" && mo->text()!=""){
    smart=new Smartphone();
    smart->setCPU((c->value())+0.00);
    smart->setRAM(r->text().toInt());
    smart->setMarca(ma->text().toStdString());
    smart->setModello(mo->text().toStdString());
    smart->setHardisk(hd->text().toStdString());
    smart->setSO(SiO->text().toStdString());
    smart->setBatteria((batt->value()));
    smart->setPollici((poll->value()));
    smart->setColore(col->text().toStdString());
    smart->setMemoria(mem->value());
    smart->setFotocamera(foto->value());
    smart->setConnettivita(sim->text().toStdString());
    smartphone=new Container<Device*>(smart);

    XMLUtility::saveDevices(smartphone);
    fatta->setText("Inserimento riuscito.");
    fatta->show();
    window()->close();
    }else{
        fatta->setText("Inseririre almeno Marca e Modello");
        fatta->show();
    }
}

