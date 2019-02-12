#include"modifyelement.h"

ModifyElement::ModifyElement(QWidget* parent){
    centralWidget = new QWidget(parent);
    lay = new QGridLayout(centralWidget);
    list=new QListWidget();


    cont= new Container<Device*>();
    cont=XMLUtility::loadDevices();

    Container<Device*>::Iterator c=cont->begin();
    int i=0;
    while (c!=cont->end()) {
        list->insertItem(i,QString::fromStdString((*c)->getMarca())+"  "+QString::fromStdString((*c)->getModello()));
        ++c;
        i++;
    }

    title=new QLabel("Lista devices");
    QLabel* instr=new QLabel("Seleziona il device da modificare.");
    lay->addWidget(title,0,0);
    lay->addWidget(instr,1,0);
    lay->addWidget(list,2,0,1,2);
    setFixedSize(300,500);
    setLayout(lay);

    connect(list,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(showmodify(QListWidgetItem*)));
    connect(this,SIGNAL(deleteFirstView()),this,SLOT(deleteItems()));
}

void ModifyElement::showmodify(QListWidgetItem * x){
    emit deleteItems();
    oggetto=x;
    cont=XMLUtility::loadDevices();
    Container<Device*>::Iterator it=cont->begin();
  for(int i=0; i<list->row(x)&& it!=cont->end(); i++){
        ++it;
    }

  QLabel *cpu=new QLabel("CPU");
  QLabel *ram=new QLabel("RAM");
  QLabel *marca=new QLabel("Marca");
  QLabel *modello=new QLabel("Modello");
  QLabel *hardisk=new QLabel("Hardisk");
  QLabel *SO=new QLabel("Sistema operativo");

  c=new QDoubleSpinBox(this);
  c->setValue((*it)->getCPU());
  c->setRange(0.00,100.00);
  r=new QSpinBox(this);
  r->setRange(0,1000);
  r->setValue((*it)->getRAM());
  ma=new QLineEdit(this);
  mo=new QLineEdit(this);
  hd=new QLineEdit(this);
  SiO=new QLineEdit(this);
  send=new QPushButton("Modifica");
  connect(send,SIGNAL(clicked()),this,SLOT(modify()));

  ma->setPlaceholderText(QString::fromStdString((*it)->getMarca()));
  mo->setPlaceholderText(QString::fromStdString((*it)->getModello()));
  hd->setPlaceholderText(QString::fromStdString((*it)->getHardisk()));
  SiO->setPlaceholderText(QString::fromStdString((*it)->getSO()));

  lay->addWidget(cpu,3,0);
  lay->addWidget(ram,4,0);
  lay->addWidget(marca,5,0);
  lay->addWidget(modello,6,0);
  lay->addWidget(hardisk,7,0);
  lay->addWidget(SO,8,0);
  lay->addWidget(c,3,1);
  lay->addWidget(r,4,1);
  lay->addWidget(ma,5,1);
  lay->addWidget(mo,6,1);
  lay->addWidget(hd,7,1);
  lay->addWidget(SiO,8,1);
  lay->addWidget(send,15,1);

   Desktop* de=dynamic_cast<Desktop*>((*it));
  if(de){
      QLabel *Tipologia=new QLabel("Tipologia");
      QLabel *wattMin=new QLabel("Watt minimi");
      QLabel *nHard=new QLabel("Numero Hardisk");
      QLabel *uso=new QLabel("Uso");

      ty=new QLineEdit(this);
      wM=new QDoubleSpinBox(this);
      wM->setRange(0.00,1000.00);
      wM->setValue(de->getWattMin());
      nH=new QSpinBox(this);
      nH->setValue(de->getNHard());
      nH->setRange(0.00,30.00);
      u=new QLineEdit(this);

      ty->setPlaceholderText(QString::fromStdString(de->getTipologia()));
      u->setPlaceholderText(QString::fromStdString(de->getUso()));
      lay->addWidget(Tipologia,9,0);
      lay->addWidget(wattMin,10,0);
      lay->addWidget(nHard,11,0);
      lay->addWidget(uso,12,0);
      lay->addWidget(ty,9,1);
      lay->addWidget(wM,10,1);
      lay->addWidget(nH,11,1);
      lay->addWidget(u,12,1);
  }
  Laptop * la=dynamic_cast<Laptop*>((*it));
  if(la){
      QLabel* Tip=new QLabel("Tipologia");
      QLabel* ba=new QLabel("Batteria");
      QLabel* po=new QLabel("Pollici");
      QLabel* pe=new QLabel("Peso");

      ti=new QLineEdit(this);
      batte=new QDoubleSpinBox(this);
      batte->setRange(0.00,100000.00);
      batte->setValue(la->getBatteria());
      polli=new QDoubleSpinBox(this);
      polli->setValue(la->getPollici());
      polli->setRange(0.00,100);
      peso=new QDoubleSpinBox(this);
      peso->setRange(0.00,1000.00);
      peso->setValue(la->getPeso());

      ti->setPlaceholderText(QString::fromStdString(la->getTipologia()));

      lay->addWidget(Tip,9,0);
      lay->addWidget(ba,10,0);
      lay->addWidget(po,11,0);
      lay->addWidget(pe,12,0);
      lay->addWidget(ti,9,1);
      lay->addWidget(batte,10,1);
      lay->addWidget(polli,11,1);
      lay->addWidget(peso,12,1);
  }

  Smartphone * sma=dynamic_cast<Smartphone*>((*it));
  if(sma){
       QLabel* batt=new QLabel("Batteria");
       QLabel* poll=new QLabel("Pollici");
       QLabel* foto=new QLabel("Fotocamera");
       QLabel* mem=new QLabel("Memoria");
       QLabel* col=new QLabel("Colore");
       QLabel* conn=new QLabel("Connettivita'");

      batteria=new QDoubleSpinBox(this);
      batteria->setRange(0.00,100000.00);
      batteria->setValue(sma->getBatteria());
      pollici=new QDoubleSpinBox(this);
      pollici->setValue(sma->getPollici());
      pollici->setRange(0.00,100.00);
      fotocamera=new QDoubleSpinBox(this);
      fotocamera->setValue(sma->getFotocamera());
      fotocamera->setRange(0.00,100.00);
      memoria=new QSpinBox(this);
      memoria->setRange(0,1000);
      memoria->setValue(sma->getMemoria());
      colore=new QLineEdit(this);
      co=new QLineEdit(this);

      colore->setPlaceholderText(QString::fromStdString(sma->getColore()));
      co->setPlaceholderText(QString::fromStdString(sma->getConnettivita()));

      lay->addWidget(batt,9,0);
      lay->addWidget(poll,10,0);
      lay->addWidget(foto,11,0);
      lay->addWidget(mem,12,0);
      lay->addWidget(col,13,0);
      lay->addWidget(conn,14,0);
      lay->addWidget(batteria,9,1);
      lay->addWidget(pollici,10,1);
      lay->addWidget(fotocamera,11,1);
      lay->addWidget(memoria,12,1);
      lay->addWidget(colore,13,1);
      lay->addWidget(co,14,1);
  }
  Tablet * ta=dynamic_cast<Tablet*>((*it));
  if(ta){
      QLabel* batt1=new QLabel("Batteria");
      QLabel* poll1=new QLabel("Pollici");
      QLabel* foto=new QLabel("Fotocamera");
      QLabel* mem=new QLabel("Memoria");
      QLabel* col=new QLabel("Colore");
      QLabel* s=new QLabel("SIM");

      batter=new QDoubleSpinBox(this);
      batter->setRange(0.00,100000.00);
      batter->setValue(ta->getBatteria());
      pollic=new QDoubleSpinBox(this);
      pollic->setValue(ta->getPollici());
      pollic->setRange(0.00,100.00);
      fotocamera1=new QDoubleSpinBox(this);
      fotocamera1->setValue(ta->getFotocamera());
      fotocamera1->setRange(0.00,100.00);
      memoria1=new QSpinBox(this);
      memoria1->setRange(0,1000);
      memoria1->setValue(ta->getMemoria());
      colore1=new QLineEdit(this);

      colore1->setPlaceholderText(QString::fromStdString(ta->getColore()));

      sim=new QLineEdit(this);
      if(ta->getSIM()){sim->setPlaceholderText("Si");
      }else
          sim->setPlaceholderText("No");

      lay->addWidget(batt1,9,0);
      lay->addWidget(poll1,10,0);
      lay->addWidget(foto,11,0);
      lay->addWidget(mem,12,0);
      lay->addWidget(col,13,0);
      lay->addWidget(batter,9,1);
      lay->addWidget(pollic,10,1);
      lay->addWidget(fotocamera1,11,1);
      lay->addWidget(memoria1,12,1);
      lay->addWidget(colore1,13,1);
      lay->addWidget(s,14,0);
      lay->addWidget(sim,14,1);
  }
}

void ModifyElement::deleteItems(){
    QLayoutItem * x=lay->takeAt(3);
    while (x!=nullptr) {
        lay->removeItem(x);
        x->widget()->hide();
        delete x;
        x=lay->takeAt(3);

    }
}

void ModifyElement::modify(){
    cont=XMLUtility::loadDevices();
    Container<Device*>::Iterator it=cont->begin();
    for(int i=0; i<list->row(oggetto) && it!=cont->end(); i++){
        ++it;
    }
    std::string cc=std::to_string(c->value());
    cc.erase(cc.size()-4);
    XMLUtility::ModifyElement(list->row(oggetto),"CPU",cc);
    std::string rr=std::to_string(r->value());
    XMLUtility::ModifyElement(list->row(oggetto),"RAM",rr);
    if(ma->text()!="")
        XMLUtility::ModifyElement(list->row(oggetto),"marca",ma->text().toStdString());
    if(mo->text()!="")
        XMLUtility::ModifyElement(list->row(oggetto),"modello",mo->text().toStdString());
    if(hd->text()!="")
        XMLUtility::ModifyElement(list->row(oggetto),"hardisk",hd->text().toStdString());
    if(SiO->text()!="")
        XMLUtility::ModifyElement(list->row(oggetto),"SO",SiO->text().toStdString());
    if(c){
    if(dynamic_cast<Desktop*>(*it)){
        if(ty->text()!="")
            XMLUtility::ModifyElement(list->row(oggetto),"tipologia",ty->text().toStdString());
        std::string ww=std::to_string(wM->value());
        ww.erase(ww.size()-4);
        XMLUtility::ModifyElement(list->row(oggetto),"wattMin",ww);
        std::string nn=std::to_string(nH->value());
        XMLUtility::ModifyElement(list->row(oggetto),"nHard",nn);
        if(u->text()!="")
            XMLUtility::ModifyElement(list->row(oggetto),"uso",u->text().toStdString());
    }
    if(dynamic_cast<Laptop*>(*it)){
        if(ti->text()!="")
            XMLUtility::ModifyElement(list->row(oggetto),"tipologia",ti->text().toStdString());
        std::string bb=std::to_string(batte->value());
        bb.erase(bb.size()-4);
        XMLUtility::ModifyElement(list->row(oggetto),"batteria",bb);
        std::string pp=std::to_string(polli->value());
        pp.erase(pp.size()-4);
        XMLUtility::ModifyElement(list->row(oggetto),"pollici",pp);
        std::string pee=std::to_string(peso->value());
        pee.erase(pee.size()-4);
        XMLUtility::ModifyElement(list->row(oggetto),"peso",pee);
    }
    if(dynamic_cast<Smartphone*>(*it)){
        std::string bbt=std::to_string(batteria->value());
        bbt.erase(bbt.size()-4);
        XMLUtility::ModifyElement(list->row(oggetto),"batteria",bbt);
        std::string ppp=std::to_string(pollici->value());
        ppp.erase(ppp.size()-4);
        XMLUtility::ModifyElement(list->row(oggetto),"pollici",ppp);
        std::string ff=std::to_string(fotocamera->value());
        ff.erase(ff.size()-4);
        XMLUtility::ModifyElement(list->row(oggetto),"fotocamera",ff);
        std::string memm=std::to_string(memoria->value());
        XMLUtility::ModifyElement(list->row(oggetto),"memoria",memm);
        if(colore->text()!="")
            XMLUtility::ModifyElement(list->row(oggetto),"colore",colore->text().toStdString());
        if(co->text()!="")
            XMLUtility::ModifyElement(list->row(oggetto),"connettivita",co->text().toStdString());
    }
    if(dynamic_cast<Tablet*>(*it)){
        std::string b11=std::to_string(batter->value());
        b11.erase(b11.size()-4);
        XMLUtility::ModifyElement(list->row(oggetto),"batteria",b11);
        std::string p11=std::to_string(pollic->value());
        p11.erase(p11.size()-4);
        XMLUtility::ModifyElement(list->row(oggetto),"pollici",p11);
        std::string f11=std::to_string(fotocamera1->value());
        f11.erase(f11.size()-4);
        XMLUtility::ModifyElement(list->row(oggetto),"fotocamera",f11);
        std::string m11=std::to_string(memoria1->value());
        XMLUtility::ModifyElement(list->row(oggetto),"memoria",m11);
        if(colore1->text()!="")
            XMLUtility::ModifyElement(list->row(oggetto),"colore",colore1->text().toStdString());
        if(sim->text()=="Si" || sim->text()=="si")
            XMLUtility::ModifyElement(list->row(oggetto),"SIM","1");
        if(sim->text()=="No" || sim->text()=="no")
            XMLUtility::ModifyElement(list->row(oggetto),"SIM","0");
    }

    QMessageBox * mess=new QMessageBox();
    mess->setText("Modifica riuscita.");
    mess->show();

}


}
