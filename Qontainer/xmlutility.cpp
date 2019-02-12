#include"xmlutility.h"
#include <QString>
#include<iostream>
#include"Model/container.h"
#include <QFile>
#include<QDomDocument>

Device* XMLUtility::gatherDevice(QXmlStreamReader& x){
        std::string nomenodo,type;
        double CPU,wattMin,batteria,pollici,peso,fotocamera;
        int RAM,memoria;
        std::string marca,modello,hardisk,SO,colore,connettivita,uso,tipologia;
        int nHard;
        bool SIM;
        QXmlStreamAttributes atts = x.attributes();
        if (atts.hasAttribute("type")){
                type = atts.value("type").toString().toStdString();
        }else{
                return nullptr;
        }
        x.readNext();
        nomenodo = x.name().toString().toStdString();
        while(nomenodo!="device"){
            if (x.isStartElement()){
                if(nomenodo=="CPU")
                    CPU= x.readElementText().toDouble();
                if(nomenodo=="RAM")
                    RAM= x.readElementText().toInt();
                if(nomenodo=="marca")
                    marca= x.readElementText().toStdString();
                if(nomenodo=="modello")
                    modello= x.readElementText().toStdString();
                if(nomenodo=="hardisk")
                    hardisk= x.readElementText().toStdString();
                if(nomenodo=="SO")
                    SO= x.readElementText().toStdString();
                if(type=="desktop"){
                    if(nomenodo=="tipologia")
                        tipologia= x.readElementText().toStdString();
                    if(nomenodo=="wattMin")
                        wattMin= x.readElementText().toDouble();
                    if(nomenodo=="nHard")
                        nHard= x.readElementText().toInt();
                    if(nomenodo=="uso")
                        uso= x.readElementText().toStdString();
                }
                if(type=="laptop"){
                    if(nomenodo=="tipologia")
                        tipologia= x.readElementText().toStdString();
                    if(nomenodo=="batteria")
                        batteria= x.readElementText().toDouble();
                    if(nomenodo=="pollici")
                        pollici= x.readElementText().toDouble();
                    if(nomenodo=="peso")
                        peso= x.readElementText().toDouble();
                }
                if(type=="smartphone"){
                    if(nomenodo=="colore")
                        colore= x.readElementText().toStdString();
                    if(nomenodo=="batteria")
                        batteria= x.readElementText().toDouble();
                    if(nomenodo=="pollici")
                        pollici= x.readElementText().toDouble();
                    if(nomenodo=="fotocamera")
                        fotocamera= x.readElementText().toDouble();
                    if(nomenodo=="memoria")
                        memoria=x.readElementText().toInt();
                    if(nomenodo=="connettivita")
                        connettivita= x.readElementText().toStdString();
                }
                if(type=="tablet"){
                    if(nomenodo=="colore")
                        colore= x.readElementText().toStdString();
                    if(nomenodo=="batteria")
                        batteria= x.readElementText().toDouble();
                    if(nomenodo=="pollici")
                        pollici= x.readElementText().toDouble();
                    if(nomenodo=="fotocamera")
                        fotocamera= x.readElementText().toDouble();
                    if(nomenodo=="memoria")
                        memoria=x.readElementText().toInt();
                    if(nomenodo=="SIM")
                        SIM= x.readElementText().toInt();
                }
            }
            x.readNext();
            nomenodo = x.name().toString().toStdString();
        }
        if(type=="tablet")
            return new Tablet(CPU,RAM,marca,modello,hardisk,SO,batteria,pollici,fotocamera,memoria,colore,SIM);
        if(type=="smartphone")
            return new Smartphone(CPU,RAM,marca,modello,hardisk,SO,batteria,pollici,fotocamera,memoria,colore,connettivita);
        if(type=="laptop")
            return new Laptop(CPU,RAM,marca,modello,hardisk,SO,tipologia,batteria,pollici,peso);
        if(type=="desktop")
            return new Desktop(CPU,RAM,marca,modello,hardisk,SO,tipologia,wattMin,nHard,uso);
   return nullptr;
}

Container<Device*>* XMLUtility::loadDevices(){
        Container<Device*>* ret=new Container<Device*>();
        QFile* fil = new QFile("Container.xml");
      fil->open(QIODevice::ReadOnly);
        QXmlStreamReader xml(fil);
        while(!xml.atEnd()){
            xml.readNext();
            if (xml.isStartElement()){
                if (xml.name() == "device"){
                    ret->insert(gatherDevice(xml));
                }
            }
        }
        if (xml.hasError()){
            std::cout << "Errore nella lettura del file XML Dati:" << xml.errorString().toStdString();
        }
        fil->close();
        return ret;
}

void XMLUtility::saveDevices(Container<Device*>* co){
    QDomDocument  doc("Container");
    QFile file("Container.xml");

    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    QDomElement docElem = doc.documentElement();
    QDomNode n = docElem;

    Container<Device*>::Iterator it=co->begin();
        while(it!=co->end()){
            QDomElement root = doc.createElement("device");
            Desktop* d = dynamic_cast<Desktop*>(*it);
            Laptop* l = dynamic_cast<Laptop*>(*it);
            Smartphone* s=dynamic_cast<Smartphone*>(*it);
            Tablet* t=dynamic_cast<Tablet*>(*it);
            root.attributeNode("type");
            if(d){root.setAttribute("type","desktop");}
            if(l){root.setAttribute("type","laptop");}
            if(s){root.setAttribute("type","smartphone");}
            if(t){root.setAttribute("type","tablet");}

            QDomElement c = doc.createElement("CPU");
            QDomElement r = doc.createElement("RAM");
            QDomElement m = doc.createElement("marca");
            QDomElement mo = doc.createElement("modello");
            QDomElement hd = doc.createElement("hardisk");
            QDomElement so = doc.createElement("SO");
            std::string c1=std::to_string((*it)->getCPU());
            c1.erase(c1.size()-4);
            QDomText cpu = doc.createTextNode(QString::fromStdString(c1));
            QDomText ram = doc.createTextNode(QString::number((*it)->getRAM()));
            QDomText marca = doc.createTextNode(QString::fromStdString((*it)->getMarca()));
            QDomText modello = doc.createTextNode(QString::fromStdString((*it)->getModello()));
            QDomText hardisk = doc.createTextNode(QString::fromStdString((*it)->getHardisk()));
            QDomText SO = doc.createTextNode(QString::fromStdString((*it)->getSO()));

            c.appendChild(cpu);
            root.appendChild(c);

            r.appendChild(ram);
            root.appendChild(r);

            m.appendChild(marca);
            root.appendChild(m);

            mo.appendChild(modello);
            root.appendChild(mo);

            hd.appendChild(hardisk);
            root.appendChild(hd);

            so.appendChild(SO);
            root.appendChild(so);

            if (d){
                QDomElement tip = doc.createElement("tipologia");
                QDomText tipologia = doc.createTextNode(QString::fromStdString(d->getTipologia()));

                QDomElement watt = doc.createElement("wattMin");
                std::string w1=std::to_string(d->getWattMin());
                w1.erase(w1.size()-4);
                QDomText wattMin = doc.createTextNode(QString::fromStdString(w1));

                QDomElement nh = doc.createElement("nHard");
                QDomText nhard = doc.createTextNode(QString::number(d->getNHard()));

                QDomElement u = doc.createElement("uso");
                QDomText uso = doc.createTextNode(QString::fromStdString(d->getUso()));

                tip.appendChild(tipologia);
                root.appendChild(tip);
                watt.appendChild(wattMin);
                root.appendChild(watt);
                nh.appendChild(nhard);
                root.appendChild(nh);
                u.appendChild(uso);
                root.appendChild(u);

            }
            if (l){

                QDomElement tip = doc.createElement("tipologia");
                QDomText tipologia = doc.createTextNode(QString::fromStdString(l->getTipologia()));

                QDomElement batt = doc.createElement("batteria");
                std::string b1=std::to_string(l->getBatteria());
                b1.erase(b1.size()-4);
                QDomText batteria = doc.createTextNode(QString::fromStdString(b1));

                QDomElement poll = doc.createElement("pollici");
                std::string p1=std::to_string(l->getPollici());
                p1.erase(p1.size()-4);
                QDomText pollici = doc.createTextNode(QString::fromStdString(p1));

                QDomElement pe = doc.createElement("peso");
                std::string p2=std::to_string(l->getPeso());
                p2.erase(p2.size()-4);
                QDomText peso = doc.createTextNode(QString::fromStdString(p2));

                tip.appendChild(tipologia);
                root.appendChild(tip);
                batt.appendChild(batteria);
                root.appendChild(batt);
                poll.appendChild(pollici);
                root.appendChild(poll);
                pe.appendChild(peso);
                root.appendChild(pe);

            }
            if (s){

                QDomElement batt = doc.createElement("batteria");
                std::string b2=std::to_string(s->getBatteria());
                b2.erase(b2.size()-4);
                QDomText batteria = doc.createTextNode(QString::fromStdString(b2));

                QDomElement poll = doc.createElement("pollici");
                std::string pp1=std::to_string(s->getPollici());
                pp1.erase(pp1.size()-4);
                QDomText pollici = doc.createTextNode(QString::fromStdString(pp1));

                QDomElement fo = doc.createElement("fotocamera");
                std::string f1=std::to_string(s->getFotocamera());
                f1.erase(f1.size()-4);
                QDomText foto = doc.createTextNode(QString::fromStdString(f1));

                QDomElement me = doc.createElement("memoria");
                QDomText memo = doc.createTextNode(QString::number(s->getMemoria()));

                QDomElement co = doc.createElement("colore");
                QDomText colo = doc.createTextNode(QString::fromStdString(s->getColore()));

                QDomElement con = doc.createElement("connettivita");
                QDomText conn = doc.createTextNode(QString::fromStdString(s->getConnettivita()));

                batt.appendChild(batteria);
                root.appendChild(batt);
                poll.appendChild(pollici);
                root.appendChild(poll);
                fo.appendChild(foto);
                root.appendChild(fo);
                me.appendChild(memo);
                root.appendChild(me);
                co.appendChild(colo);
                root.appendChild(co);
                con.appendChild(conn);
                root.appendChild(con);

            }
            if (t){

                QDomElement batt = doc.createElement("batteria");
                std::string bb1=std::to_string(t->getBatteria());
                bb1.erase(bb1.size()-4);
                QDomText batteria = doc.createTextNode(QString::fromStdString(bb1));

                QDomElement poll = doc.createElement("pollici");
                std::string pq1=std::to_string(t->getPollici());
                pq1.erase(pq1.size()-4);
                QDomText pollici = doc.createTextNode(QString::fromStdString(pq1));

                QDomElement fo = doc.createElement("fotocamera");
                std::string ff1=std::to_string(t->getFotocamera());
                ff1.erase(ff1.size()-4);
                QDomText foto = doc.createTextNode(QString::fromStdString(ff1));

                QDomElement me = doc.createElement("memoria");
                QDomText memo = doc.createTextNode(QString::number(t->getMemoria()));

                QDomElement co = doc.createElement("colore");
                QDomText colo = doc.createTextNode(QString::fromStdString(t->getColore()));

                QDomElement con = doc.createElement("sim");
                QDomText conn = doc.createTextNode(QString::number(t->getSIM()));

                batt.appendChild(batteria);
                root.appendChild(batt);
                poll.appendChild(pollici);
                root.appendChild(poll);
                fo.appendChild(foto);
                root.appendChild(fo);
                me.appendChild(memo);
                root.appendChild(me);
                co.appendChild(colo);
                root.appendChild(co);
                con.appendChild(conn);
                root.appendChild(con);

            }
            ++it;
            n.appendChild(root);
        }

       QString xml = doc.toString();
        file.open(QIODevice::WriteOnly);
        file.write(xml.toUtf8());
        file.close();
}

void XMLUtility::ModifyElement(int pos, std::string tag, std::string valore){
    QDomDocument  doc("Container");
    QFile file("Container.xml");

    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    QDomNodeList nodes = doc.elementsByTagName("device");

    QDomNode x= nodes.at(pos).firstChildElement(QString::fromStdString(tag)).firstChild();
    x.setNodeValue(QString::fromStdString(valore));

    QString newXml = doc.toString();
    file.open(QIODevice::WriteOnly);
    file.write(newXml.toUtf8());
    file.close();
}

void XMLUtility::DeleteElement(std::string tipo){
    QDomDocument  doc("Container");
    QFile file("Container.xml");

    if (!file.open(QIODevice::ReadWrite))
        return;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    QDomNodeList root = doc.elementsByTagName("devices");
    QDomNodeList nodes = root.at(0).childNodes();

    int i=0;

    while(i<nodes.size()){
        if(nodes.at(i).toElement().attribute("type")==QString::fromStdString(tipo)){
            QDomNodeList childs=nodes.at(i).childNodes();

            int n_childs=childs.size();
            for(int j=0; j<n_childs; j++)
                nodes.at(i).removeChild(childs.at(0));

            root.at(0).removeChild(nodes.at(i));
        }
        else
            i++;

    }
    QString newXml = doc.toString();
    file.open(QIODevice::WriteOnly);
    file.write(newXml.toUtf8());
    file.close();
}

void XMLUtility::DeleteElementField(std::string tipo,std::string campo, std::string valore){
    QDomDocument  doc("Container");
    QFile file("Container.xml");

    if (!file.open(QIODevice::ReadWrite))
        return;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    QDomNodeList root = doc.elementsByTagName("devices");
    QDomNodeList nodes = root.at(0).childNodes();

    for(int i=0;i<nodes.size();i++){
        if(nodes.at(i).toElement().attribute("type")==QString::fromStdString(tipo)){
            QDomNodeList childs=nodes.at(i).childNodes();
            QDomNode x= nodes.at(i).firstChildElement(QString::fromStdString(campo)).firstChild();
            if(x.nodeValue()==QString::fromStdString(valore)){
                int n_childs=childs.size();
                for(int j=0; j<n_childs; j++)
                    nodes.at(i).removeChild(childs.at(0));

                root.at(0).removeChild(nodes.at(i));
            }
        }
    }
    QString newXml = doc.toString();
    file.open(QIODevice::WriteOnly);
    file.write(newXml.toUtf8());
    file.close();
}



