#include"portable.h"
#include"smartphone.h"
#include<iostream>

    Smartphone::Smartphone(double p,int m, std::string c, std::string con,std::string q,std::string w,double e,double r, double z,int t,std::string y,std::string u):Portable(p,m,c,con,q,w,e,r,z,t,y), connettivita(u){}

    //GETTER

    std::string Smartphone::getConnettivita() const{return connettivita;}

    //SETTER

    void Smartphone::setConnettivita(std::string c){if(c!="")connettivita=c;else connettivita="Non specificato";}

    //METODI EREDITATI

    bool Smartphone::operator==(Device& w)const{
        Smartphone x=dynamic_cast<Smartphone&>(w);
        return getCPU()==x.getCPU() && getRAM()==x.getRAM() && getMarca()==x.getMarca() && getModello()==x.getModello()
                && getHardisk()==x.getHardisk() && getSO()==x.getSO() && getPollici()==x.getPollici() && getFotocamera()==x.getFotocamera()
                && getBatteria()==x.getBatteria() && getMemoria()==x.getMemoria() && getColore()==x.getColore() && getConnettivita()==x.getConnettivita();
    }

    std::string Smartphone::CalcolaRating()const{
        if(getCPU()>=2.2 && getRAM()>=16 && connettivita=="4G" && getMemoria()>=64)
            return "Qualita' alta";
        if(getCPU()>1.6 && getCPU()<2.2 && getRAM()>=4 && getRAM()<16 &&(connettivita=="3G" ||connettivita=="4G") && getMemoria()>=16)
            return "Qualita' media";
        else
           return "Qualita' bassa";
    }

    double Smartphone::CalcolaAutonomia()const{
        return getBatteria()/15;
    }

    std::ostream& Smartphone::operator<< (std::ostream& o){
        return o<<"CPU:"<<getCPU()<<",RAM:"<<getRAM()<<",Marca:"<<getMarca()<<",Modello:"<<getModello()<<",Hardisk:"<<getHardisk()<<",SO:"<<getSO()<<",Pollici:"<<getPollici()<<",Batteria:"<<getBatteria()<<",Fotocamera:"<<getFotocamera()<<",Memoria:"<<getMemoria()<<",Colore:"<<getColore()<<",Connettivita"<<getConnettivita()<<".";
    }

    std::string Smartphone::details(){
        std::string c=std::to_string(this->getCPU());
        c.erase(c.size()-4);
        std::string b=std::to_string(this->getBatteria());
        b.erase(b.size()-4);
        std::string p=std::to_string(this->getPollici());
        p.erase(p.size()-4);
        std::string f= std::to_string(this->getFotocamera());
        f.erase(f.size()-4);
        return "CPU: "+ c+"\n"+"RAM: "+ std::to_string(this->getRAM())+"\n"+"Hardisk: "+this->getHardisk()+"\n"+"SO: "+this->getSO()+ "\n"+ "Batteria: "+b+ "\n"+ "Pollici: "+p+ "\n"+"Fotocamera:"+ f+ "\n"+"Colore:"+this->getColore()+ "\n"+"Connettivita:"+ this->getConnettivita();
    }

    std::string Smartphone::get(std::string x){
        if(x=="CPU"){
            std::string c=std::to_string(this->getCPU());
            c.erase(c.size()-4);
            return c;
        }
        if(x=="RAM")
            return std::to_string(getRAM());
        if(x=="Marca")
            return getMarca();
        if(x=="Modello")
            return getModello();
        if(x=="Hardisk")
            return getHardisk();
        if(x=="SO")
            return getSO();
        if(x=="Batteria"){
            std::string b=std::to_string(this->getBatteria());
            b.erase(b.size()-4);
            return b;
        }
        if(x=="Pollici"){
            std::string p=std::to_string(this->getPollici());
             return p.erase(p.size()-4);
        }
        if(x=="Fotocamera"){
            std::string f= std::to_string(this->getFotocamera());
             return f.erase(f.size()-4);
        }
        if(x=="Memoria")
            return std::to_string(getMemoria());
        if(x=="Colore")
            return getColore();
        if(x=="Connettivita'")
            return getConnettivita();
        return "";
    }

