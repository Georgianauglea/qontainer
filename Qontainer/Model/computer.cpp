#include"computer.h"
#include"device.h"

    Computer::Computer(double t, int x, std::string y, std::string z, std::string w, std::string c, std::string v):Device(t,x,y,z,w,c),tipologia(v){}

    //GETTER

    std::string Computer::getTipologia() const{return tipologia;}

    //SETTER

    void Computer::setTipologia(std::string t){
        if(t!="")
            tipologia=t;
        else tipologia="Non specificato";
    }
