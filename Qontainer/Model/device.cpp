#include <iostream>
#include"device.h"

    Device::Device(double c, int r, std::string m, std::string mo, std::string hd, std::string s):CPU(c), RAM(r), marca(m), modello(mo), hardisk(hd), SO(s){
        if(c<0){
            std::cerr<<"Attenzione!Valore della CPU non permesso";
        }
    }

    //GETTER

    double Device::getCPU() const{return CPU;}
    int Device::getRAM() const{return RAM;}
    std::string Device::getMarca() const{return marca;}
    std::string Device::getModello() const{return modello;}
    std::string Device::getHardisk() const{return hardisk;}
    std::string Device::getSO() const{return SO;}

    //SETTER

    void Device::setCPU(double c){
        if(c<0){
            std::cerr<<"Attenzione!Valore inserito minore di 0.Settato a 0";
            c=0;
        }
        CPU=c;
    }
    void Device::setRAM(int r){RAM=r;}
    void Device::setMarca(std::string m){if(m!="")marca=m;else marca="Non specificato";}
    void Device::setModello(std::string m){if(m!="")modello=m;else modello="Non specificato";}
    void Device::setHardisk(std::string hd){if(hd!="")hardisk=hd;else hardisk="Non specificato";}
    void Device::setSO(std::string s){if(s!="")SO=s;else SO="Non specificato";}


