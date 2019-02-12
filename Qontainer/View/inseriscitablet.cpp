#include"inseriscitablet.h"
InsertTablet::InsertTablet(QWidget* parent){
    layD=new QGridLayout(parent);
    send=new QPushButton("Invia");

    type=new QLabel("TABLET");
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

    sim=new QCheckBox("SIM");

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
    layD->addWidget(sim,12,2);
    layD->addWidget(send,13,2);

    setLayout(layD);

    connect(send, SIGNAL(clicked()),this,SLOT(insertTab()));
}

void InsertTablet::insertTab(){
    fatta=new QMessageBox();
    if(ma->text()!="" && mo->text()!=""){
    tab=new Tablet();

    tab->setCPU((c->value()));
    tab->setRAM((r->value()));
    tab->setMarca(ma->text().toStdString());
    tab->setModello(mo->text().toStdString());
    tab->setHardisk(hd->text().toStdString());
    tab->setSO(SiO->text().toStdString());
    tab->setBatteria((batt->value()));
    tab->setPollici((poll->value()));
    tab->setColore(col->text().toStdString());
    tab->setMemoria(mem->value());
    tab->setFotocamera(foto->value());
    if(sim->isChecked()){
         tab->setSIM(true);}
    else{
         tab->setSIM(false);}
    cont=new Container<Device*>(tab);

    XMLUtility::saveDevices(cont);
    fatta->setText("Inserimento riuscito.");
    fatta->show();
    window()->close();
    }else{
        fatta->setText("Inseririre almeno Marca e Modello");
        fatta->show();
    }
}
