#ifndef DESKTOP
#define DESKTOP

#include"computer.h"

class Desktop:public Computer{
    private:
        double wattMin;
        int nHard;
        std::string uso;

    public:

        //COSTRUTTORE

        explicit Desktop(double=0 ,int=0 , std::string="",  std::string="" , std::string="", std::string="", std::string="" , double =0,int =0,std::string ="");

        //GETTER

        double getWattMin() const;
        int getNHard() const;
        std::string getUso() const;



        //SETTER

        void setWattMin(double =0);
        void setNHard(int =0);
        void setUso(std::string ="Non specificato");


        //METODI EREDITATI

        bool operator==(Device&)const override;
        std::string CalcolaRating()const override;
        std::ostream& operator<< (std::ostream& ) override;
        std::string details()override;
        std::string get(std::string)override;

        //DISTRUTTORE

        ~Desktop()override =default;

};


#endif // DESKTOP

