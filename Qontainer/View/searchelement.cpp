#include"seachelement.h"

SearchElement::SearchElement(QWidget* parent){
    centralWidget = new QWidget(parent);
    lay = new QGridLayout(centralWidget);
    list=new QListWidget();
    tipo=new QComboBox();
    campo=new QComboBox();
    valore=new QLineEdit();
    send=new QPushButton("Cerca");
    mess=new QMessageBox();

    tipo->addItem("");
    tipo->addItem("Desktop");
    tipo->addItem("Laptop");
    tipo->addItem("Smartphone");
    tipo->addItem("Tablet");

    campo->addItem("");
    campo->addItem("CPU");
    campo->addItem("RAM");
    campo->addItem("Marca");
    campo->addItem("Modello");
    campo->addItem("Hardisk");
    campo->addItem("SO");
    campo->addItem("Tipologia");
    campo->addItem("Batteria");
    campo->addItem("Pollici");
    campo->addItem("Peso");
    campo->addItem("WattMin");
    campo->addItem("Numero Hardisk");
    campo->addItem("Uso");
    campo->addItem("Fotocamera");
    campo->addItem("Memoria");
    campo->addItem("Colore");
    campo->addItem("Connettivita'");
    campo->addItem("SIM");

    cont=XMLUtility::loadDevices();

    connect(send,SIGNAL(clicked()),this,SLOT(searchType()));

    title=new QLabel("Lista devices");
    lay->addWidget(title);
    lay->addWidget(list,1,0,1,3);
    lay->addWidget(tipo,2,0);
    lay->addWidget(campo,2,1);
    lay->addWidget(valore,2,2);
    lay->addWidget(send,3,2);
    setLayout(lay);
}

void SearchElement::searchType(){
    list->clear();
    cont=XMLUtility::loadDevices();

    if(tipo->currentText()=="Desktop"){
        Desktop* de=new Desktop();
        Container<Desktop*> d=cont->find(de);
        Container<Desktop*>::Iterator c=d.begin();
        if(valore->text()!="" && campo->currentText()!=""){
                int i=0;
                    for(;c!=d.end();++c){
                        if(!((*c)->get((campo->currentText()).toStdString())).empty())
                        if((QString::fromStdString((*c)->get((campo->currentText(). toStdString())))==valore->text()))
                            list->insertItem(i,QString::fromStdString((*c)->getMarca())+"  "+QString::fromStdString((*c)->getModello()));
                    }
        }else{
            Container<Desktop*>::Iterator s=d.begin();
            int j=0;
                for(;s!=d.end();++s){
                        list->insertItem(j,QString::fromStdString((*s)->getMarca())+"  "+QString::fromStdString((*s)->getModello()));
                }
        }


    }
    if(tipo->currentText()=="Laptop"){
        Laptop* de=new Laptop();
        Container<Laptop*> d=cont->find(de);
        Container<Laptop*>::Iterator c=d.begin();
        if(valore->text()!="" && campo->currentText()!=""){
                int i=0;
                    for(;c!=d.end();++c){
                        if(!((*c)->get((campo->currentText()).toStdString())).empty())
                        if((QString::fromStdString((*c)->get((campo->currentText().toStdString())))==valore->text()))
                            list->insertItem(i,QString::fromStdString((*c)->getMarca())+"  "+QString::fromStdString((*c)->getModello()));
                    }
        }else{
            Container<Laptop*>::Iterator s=d.begin();
            int j=0;
                for(;s!=d.end();++s){
                        list->insertItem(j,QString::fromStdString((*s)->getMarca())+"  "+QString::fromStdString((*s)->getModello()));
                }
        }
    }
    if(tipo->currentText()=="Smartphone"){
        Smartphone* de=new Smartphone();
        Container<Smartphone*> d=cont->find(de);
        Container<Smartphone*>::Iterator c=d.begin();
        if(valore->text()!="" && campo->currentText()!=""){
                int i=0;
                    for(;c!=d.end();++c){
                        if(!((*c)->get((campo->currentText()).toStdString())).empty())
                        if((QString::fromStdString((*c)->get((campo->currentText().toStdString())))==valore->text()))
                            list->insertItem(i,QString::fromStdString((*c)->getMarca())+"  "+QString::fromStdString((*c)->getModello()));
                    }
        }else{
            Container<Smartphone*>::Iterator s=d.begin();
            int j=0;
                for(;s!=d.end();++s){
                        list->insertItem(j,QString::fromStdString((*s)->getMarca())+"  "+QString::fromStdString((*s)->getModello()));
                }
        }
    }
    if(tipo->currentText()=="Tablet"){
        Tablet* de=new Tablet;
        Container<Tablet*> d=cont->find(de);
        Container<Tablet*>::Iterator c=d.begin();
        if(valore->text()!="" && campo->currentText()!=""){
                int i=0;
                    for(;c!=d.end();++c){
                        if(!((*c)->get((campo->currentText()).toStdString())).empty())
                        if((QString::fromStdString((*c)->get((campo->currentText().toStdString())))==valore->text()))
                            list->insertItem(i,QString::fromStdString((*c)->getMarca())+"  "+QString::fromStdString((*c)->getModello()));
                    }
        }else{
            Container<Tablet*>::Iterator s=d.begin();
            int j=0;
                for(;s!=d.end();++s){
                        list->insertItem(j,QString::fromStdString((*s)->getMarca())+"  "+QString::fromStdString((*s)->getModello()));
                }
        }
    }
    if(list->count()==0){ mess->setText("Nessun elemento trovato."); mess->show();}
}


