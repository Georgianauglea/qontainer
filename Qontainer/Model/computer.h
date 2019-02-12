#ifndef COMPUTER
#define COMPUTER

#include"string"
#include"device.h"

class Computer: public Device { //CLASSE VIRTUALE PURA
    private:
        std::string tipologia;

    protected:

        //COSTRUTTORE

        explicit Computer(double ,int , std::string,  std::string , std::string, std::string, std::string ="");

    public:

        //GETTER

        std::string getTipologia() const;

        //SETTER

        void setTipologia(std::string ="Non specificato");

        //METODI VIRTUALI PURI

        virtual bool operator==(Device& x)const =0;
        virtual std::string CalcolaRating() const =0;
        virtual std::ostream& operator<< (std::ostream& )=0;
        virtual std::string details()=0;
        virtual std::string get(std::string)=0;

        //DISTRUTTORE
        virtual ~Computer()=default;
};


#endif // COMPUTER

