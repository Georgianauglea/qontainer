#include<iostream>
#include"desktop.h"
#include"computer.h"

    Desktop::Desktop(double q, int w, std::string e,  std::string r, std::string t, std::string y, std::string a, double u, int i, std::string o):Computer(q,w,e,r,t,y,a), wattMin(u), nHard(i), uso(o){
        if(u<0 || i<0){
            std::cerr<<"Attenzione!Valori inseriti non permessi";
        }
    }

    //GETTER

    double Desktop::getWattMin() const{return wattMin;}
    int Desktop::getNHard()const{return nHard;}
    std::string Desktop::getUso() const{return uso;}

    //SETTER

    void Desktop::setWattMin(double b){
        if(b<0){
            std::cerr<<"Attenzione!Valore inserito minore di 0.Settato a 0";
            b=0;
        }
        wattMin=b;
    }
    void Desktop::setNHard(int f){
        if(f<0){
            std::cerr<<"Attenzione!Valore inserito minore di 0.Settato a 0";
            f=0;
        }
        nHard=f;
    }
    void Desktop::setUso(std::string p){if(p!="")uso=p;else uso="Non specificato";}

    //METODI EREDITATI
    bool Desktop::operator==(Device& w)const{
        Desktop x=dynamic_cast<Desktop&>(w);
        return getCPU()==x.getCPU() && getRAM()==x.getRAM() && getMarca()==x.getMarca() && getModello()==x.getModello()
                && getHardisk()==x.getHardisk() && getSO()==x.getSO() && getTipologia()==x.getTipologia() && wattMin==x.wattMin && uso==x.uso && nHard==x.nHard;
    }

    std::string Desktop::CalcolaRating()const{
            if(getCPU()>=2.2 && getRAM()>=16 && wattMin>= 850)
                return "Qualita' alta";
            if(getCPU()>1.6 && getCPU()<2.2 && getRAM()>=4 && getRAM()<16 && wattMin>=750)
                return "Qualita' media";
            else
                return "Qualita' bassa";
    }

    std::ostream& Desktop::operator<< (std::ostream& o){
        return o<<"CPU:"<<getCPU()<<",RAM:"<<getRAM()<<",Marca:"<<getMarca()<<",Modello:"<<getModello()<<",Hardisk:"<<getHardisk()<<",SO:"<<getSO()<<",Tipologia:"<<getTipologia()<<",WattMin:"<<getWattMin()<<",Numero Hard:"<<getNHard()<<",Uso:"<<getUso()<<".";
    }

    std::string Desktop::details(){
        std::string c=std::to_string(this->getCPU());
        c.erase(c.size()-4);
        std::string b=std::to_string(this->getWattMin());
        b.erase(b.size()-4);
        return "CPU: "+ c+"\n"+"RAM: "+ std::to_string(this->getRAM())+"\n"+"Hardisk: "+this->getHardisk()+"\n"+"SO: "+this->getSO()+ "\n"+"Tipologia: "+this->getTipologia()+ "\n"+ "WattMin: "+b+ "\n"+ "Numero Hardisk: "+(this->getHardisk())+ "\n"+"Uso: "+ (this->getUso());
    }

    std::string Desktop::get(std::string x){
        if(x=="CPU"){
            std::string c=std::to_string(this->getCPU());
            return c.erase(c.size()-4);
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
        if(x=="Tipologia")
            return getTipologia();
        if(x=="WattMin"){
            std::string b=std::to_string(this->getWattMin());
            return b.erase(b.size()-4);
        }
        if(x=="Numero Hardisk")
            return std::to_string(getNHard());
        if(x=="Uso")
            return getUso();
        return "";
    }
