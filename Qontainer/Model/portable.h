#ifndef PORTABLE
#define PORTABLE

#include"string"
#include"device.h"

class Portable: public Device { //CLASSE VIRTUALE PURA
    private:

        double batteria;
        double pollici;
        double fotocamera;
        int memoria;
        std::string colore;

    protected:

        //COSTRUTTORE

        Portable(double , int , std::string , std::string , std::string,std::string ,double =0,double =0,double =0,int=0, std::string="");

    public:

        //GETTER

        double getBatteria()const;
        double getPollici() const;
        double getFotocamera() const;
        int getMemoria() const;
        std::string getColore() const;


        //SETTER

        void setBatteria(double =0);
        void setPollici(double =0);
        void setFotocamera(double =0);
        void setMemoria(int =0);
        void setColore(std::string ="Non specificato");

        //METODI VIRTUALI PURI

        virtual bool operator==(Device&)const =0;
        virtual std::string CalcolaRating()const =0;
        virtual double CalcolaAutonomia() const =0;
        virtual std::ostream& operator<< (std::ostream& )=0;
        virtual std::string details()=0;
        virtual std::string get(std::string)=0;

        //DISTRUTTORE
        virtual ~Portable()=default;
};

#endif // PORTABLE

