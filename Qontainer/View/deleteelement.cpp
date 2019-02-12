#include"deleteelement.h"

DeleteElement::DeleteElement(QWidget* parent): QWidget (parent){
    centralWidget=new QWidget(this);
    lay=new QGridLayout(centralWidget);
    title=new QLabel("Cancellazione devices.");
    scelta=new QComboBox(this);
    scelta->addItem(" ");
    tipo=new QComboBox(this);
    tipo->addItem(" ");
    tipo->addItem("Desktop");
    tipo->addItem("Laptop");
    tipo->addItem("Smartphone");
    tipo->addItem("Tablet");

    scelta->addItem("CPU");
    scelta->addItem("RAM");
    scelta->addItem("marca");
    scelta->addItem("modello");
    scelta->addItem("hardisk");
    scelta->addItem("SO");
    scelta->addItem("tipologia");
    scelta->addItem("batteria");
    scelta->addItem("pollici");
    scelta->addItem("peso");
    scelta->addItem("wattMin");
    scelta->addItem("nHard");
    scelta->addItem("uso");
    scelta->addItem("fotocamera");
    scelta->addItem("memoria");
    scelta->addItem("colore");
    scelta->addItem("connettivita'");
    scelta->addItem("sim");

    valore=new QLineEdit();
    cont=XMLUtility::loadDevices();

    send=new QPushButton("Cancella");
    connect(send,SIGNAL(clicked()),this,SLOT(eraseElement()));

    lay->addWidget(title,0,0);
    lay->addWidget(tipo,1,0);
    lay->addWidget(scelta,1,1);
    lay->addWidget(valore,1,2);
    lay->addWidget(send,2,2);

    setLayout(lay);
}

void DeleteElement::eraseElement(){
    mess=new QMessageBox();
    if(tipo->currentText()=="Desktop"){
        if(scelta->currentText()!=" " && valore->text()!=""){
            XMLUtility::DeleteElementField("desktop",(scelta->currentText()).toStdString(),(valore->text()).toStdString());
            mess->setText("Tutti i desktop con campo: "+valore->text()+" sono stati cancellati.");
       }else{
        XMLUtility::DeleteElement("desktop");
        mess->setText("Tutti i device di tipo Desktop sono stati cancellati.Aggiornare lista.");
        }
    }
    if(tipo->currentText()=="Laptop"){
        if(scelta->currentText()!=" " && valore->text()!=""){
            XMLUtility::DeleteElementField("laptop",(scelta->currentText()).toStdString(),(valore->text()).toStdString());
            mess->setText("Tutti i laptop con campo: "+valore->text()+" sono stati cancellati.");
       }else{
        XMLUtility::DeleteElement("laptop");
        mess->setText("Tutti i device di tipo Laptop sono stati cancellati.Aggiornare lista.");
        }
    }
    if(tipo->currentText()=="Smartphone"){
        if(scelta->currentText()!=" " && valore->text()!=""){
            XMLUtility::DeleteElementField("smartphone",(scelta->currentText()).toStdString(),(valore->text()).toStdString());
            mess->setText("Tutti i Smartphone con campo: "+valore->text()+" sono stati cancellati.");
       }else{
        XMLUtility::DeleteElement("smartphone");
        mess->setText("Tutti i device di tipo Smartphone sono stati cancellati.Aggiornare lista.");
        }
    }
    if(tipo->currentText()=="Tablet"){
        if(scelta->currentText()!=" " && valore->text()!=""){
            XMLUtility::DeleteElementField("tablet",(scelta->currentText()).toStdString(),(valore->text()).toStdString());
            mess->setText("Tutti i Tablet con campo: "+valore->text()+" sono stati cancellati.");
       }else{
        XMLUtility::DeleteElement("tablet");
        mess->setText("Tutti i device di tipo Tablet sono stati cancellati.Aggiornare lista.");
        }
    }
    mess->show();
}
