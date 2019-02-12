#include<iostream>
#include"portable.h"
#include"tablet.h"

    Tablet::Tablet(double p,int m, std::string c, std::string con,std::string q,std::string w,double e,double r, double z,int t,std::string y,bool a):Portable(p,m,c,con,q,w,e,r,z,t,y), SIM(a){}

    //GETTER

    bool Tablet::getSIM() const{return SIM;}

    //SETTER

    void Tablet::setSIM(bool s){SIM=s;}



    //METODI EREDITATI

    bool Tablet::operator==(Device& w)const {
        Tablet x=dynamic_cast<Tablet&>(w);
        return getCPU()==x.getCPU() && getRAM()==x.getRAM() && getMarca()==x.getMarca() && getModello()==x.getModello()
                && getHardisk()==x.getHardisk() && getSO()==x.getSO() && getPollici()==x.getPollici() && getFotocamera()==x.getFotocamera()
                && getMemoria()==x.getMemoria() && getColore()==x.getColore() && getSIM()==x.getSIM() && getBatteria()==x.getBatteria();
    }

    std::string Tablet::CalcolaRating()const{
        if(getCPU()>=2.2 && getRAM()>=16 && getSIM() && getMemoria()>=64)
            return "Qualita' alta";
        if(getCPU()>1.6 && getCPU()<2.2 && getRAM()>=4 && getRAM()<16 && getMemoria()>=16)
            return "Qualita' media";
        else
            return "Qualita' bassa";
    }

    double Tablet::CalcolaAutonomia()const{
        return getBatteria()/15;
    }

    std::ostream& Tablet::operator<< (std::ostream& o){
        return o<<"CPU:"<<getCPU()<<",RAM:"<<getRAM()<<",Marca:"<<getMarca()<<",Modello:"<<getModello()<<",Hardisk:"<<getHardisk()<<",SO:"<<getSO()<<",Pollici:"<<getPollici()<<"Batteria: "<<getBatteria()<<",Fotocamera:"<<getFotocamera()<<",Memoria:"<<getMemoria()<<",Colore:"<<getColore()<<",SIM:"<<getSIM()<<".";
    }

    std::string Tablet::details(){
        std::string c=std::to_string(this->getCPU());
        c.erase(c.size()-4);
        std::string b=std::to_string(this->getBatteria());
        b.erase(b.size()-4);
        std::string p=std::to_string(this->getPollici());
        p.erase(p.size()-4);
        std::string f= std::to_string(this->getFotocamera());
        f.erase(f.size()-4);
        std::string si;
        if(this->getSIM()==1)
            si="Si";
        else
            si="No";
        return "CPU: "+c +"\n"+"RAM: "+ std::to_string(this->getRAM())+"\n"+"Hardisk: "+this->getHardisk()+"\n"+"SO: "+this->getSO()+ "\n"+ "Batteria: "+b+ "\n"+ "Pollici: "+p+ "\n"+"Fotocamera:"+ f+ "\n"+"Colore:"+ this->getColore()+ "\n"+"SIM: "+si;
    }

    std::string Tablet::get(std::string x){
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
            p.erase(p.size()-4);
            return p;
        }
        if(x=="Fotocamera"){
            std::string f= std::to_string(this->getFotocamera());
            f.erase(f.size()-4);
            return f;
        }
        if(x=="Memoria")
            return std::to_string(getMemoria());
        if(x=="Colore")
            return getColore();
        if(x=="SIM")
            return std::to_string(getSIM());
        return "";
    }



