#include<iostream>
#include"portable.h"

    //COSTRUTTORE

    Portable::Portable(double t, int x, std::string y, std::string z, std::string w,std::string c,double batt,double p,double f,int m, std::string v):Device(t,x,y,z,w,c),batteria(batt),pollici(p), fotocamera(f), memoria(m), colore(v){
        if(p<0 || f<0){
            std::cerr<<"Attenzione!Valori inseriti non permessi";
        }
    }

    //GETTER

    double Portable::getBatteria()const{return batteria;}
    double Portable::getPollici() const{return pollici;}
    double Portable::getFotocamera()const{return fotocamera;}
    int Portable::getMemoria() const{return memoria;}
    std::string Portable::getColore() const{return colore;}

    //SETTER

    void Portable::setBatteria(double x){
        if(x<0){
            std::cerr<<"Attenzione!Valore inserito minore di 0.Settato a 0";
            x=0;
        }
        batteria=x;
    }

    void Portable::setPollici(double p){
        if(p<0){
            std::cerr<<"Attenzione!Valore inserito minore di 0.Settato a 0";
            p=0;
        }
        pollici=p;
    }
    void Portable::setFotocamera(double f){
        if(f<0){
            std::cerr<<"Attenzione!Valore inserito minore di 0.Settato a 0";
            f=0;
        }
        fotocamera=f;
    }
    void Portable::setMemoria(int m){memoria=m;}
    void Portable::setColore(std::string c){if(c!="")colore=c;else colore="Non specificato";}

