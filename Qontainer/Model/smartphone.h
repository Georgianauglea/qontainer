#ifndef SMARTPHONE
#define SMARTPHONE

#include"string"

#include"portable.h"

class Smartphone:public Portable {
    private:
        std::string connettivita;
    public:

        //COSTRUTTORE

        explicit Smartphone(double=0 , int=0 , std::string="", std::string="", std::string="", std::string="", double=0, double=0, double=0 , int=0, std::string="", std::string="");

        //GETTER

        std::string getConnettivita() const;

        //SETTER

        void setConnettivita(std::string ="Non specificato");

        //METODI EREDITATI

        bool operator==(Device&)const override;
        std::string CalcolaRating()const override;
        double CalcolaAutonomia()const override;
        std::ostream& operator<< (std::ostream& ) override;
        std::string details()override;
        std::string get(std::string)override;

        //DISTRUTTORE

        ~Smartphone()override =default;
};
#endif // SMARTPHONE

