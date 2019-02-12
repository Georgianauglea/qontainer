#include<iostream>
#include"laptop.h"

    Laptop::Laptop(double q,int w,std::string e,std::string r,std::string t,std::string y, std::string c,double b,double p,double pe):Computer(q,w,e,r,t,y,c), batteria(b), pollici(p), peso(pe){
        if(b<0 || p<0 || pe<0){
            std::cerr<<"Attenzione!Valori inseriti non permessi";
        }
    }

    //GETTER

    double Laptop::getBatteria() const{return batteria;}
    double Laptop::getPollici()const{return pollici;}
    double Laptop::getPeso() const{return peso;}

    //SETTER

    void Laptop::setBatteria(double b){
        if(b<0){
            std::cerr<<"Attenzione!Valore inserito minore di 0.Settato a 0";
            b=0;
        }
        batteria=b;
    }
    void Laptop::setPollici(double f){
        if(f<0){
            std::cerr<<"Attenzione!Valore inserito minore di 0.Settato a 0";
            f=0;
        }
        pollici=f;
    }
    void Laptop::setPeso(double p){
        if(p<0){
            std::cerr<<"Attenzione!Valore inserito minore di 0.Settato a 0";
            p=0;
        }
        peso=p;
    }


    //METODI PROPRI

    double Laptop::CalcolaAutonomia()const{
        return batteria/15;
    }

    //METODI EREDITATI
    bool Laptop::operator==(Device& w)const{
        Laptop x=dynamic_cast<Laptop&>(w);
        return getCPU()==x.getCPU() && getRAM()==x.getRAM() && getMarca()==x.getMarca() && getModello()==x.getModello()
                && getHardisk()==x.getHardisk() && getSO()==x.getSO() && getTipologia()==x.getTipologia() && batteria==x.batteria && pollici==x.pollici && peso==x.peso;
    }

    std::string Laptop::CalcolaRating()const{
        if(getCPU()>=2.2 && getRAM()>=16)
            return "Qualita' alta";
        if(getCPU()>1.6 && getCPU()<2.2 && getRAM()>=4 && getRAM()<16)
            return "Qualita' media";
        else
            return "Qualita' bassa";
    }

    std::ostream& Laptop::operator<< (std::ostream& o){
        return o<<"CPU:"<<getCPU()<<",RAM:"<<getRAM()<<",Marca:"<<getMarca()<<",Modello:"<<getModello()<<",Hardisk:"<<getHardisk()<<",SO:"<<getSO()<<",Tipologia:"<<getTipologia()<<",Batteria:"<<getBatteria()<<",Pollici"<<getPollici()<<",Peso:"<<getPeso()<<".";
    }

    std::string Laptop::details(){
        std::string c=std::to_string(this->getCPU());
        c.erase(c.size()-4);
        std::string b=std::to_string(this->getBatteria());
        b.erase(b.size()-4);
        std::string p=std::to_string(this->getPollici());
        p.erase(p.size()-4);
        std::string f= std::to_string(this->getPeso());
        f.erase(f.size()-4);
        return "CPU: "+ c+"\n"+"RAM: "+ std::to_string(this->getRAM())+"\n"+"Hardisk: "+this->getHardisk()+"\n"+"SO: "+this->getSO()+ "\n"+"Tipologia: "+this->getTipologia()+ "\n"+ "Batteria: "+b+ "\n"+ "Pollici: "+p+ "\n"+"Peso:"+ f;
    }

    std::string Laptop::get(std::string x){
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
        if(x=="Batteria"){
            std::string b=std::to_string(this->getBatteria());
            return b.erase(b.size()-4);
        }
        if(x=="Pollici"){
            std::string p=std::to_string(this->getPollici());
            return p.erase(p.size()-4);
        }
        if(x=="Peso"){
            std::string f= std::to_string(this->getPeso());
            return f.erase(f.size()-4);
        }
        return "";
    }


