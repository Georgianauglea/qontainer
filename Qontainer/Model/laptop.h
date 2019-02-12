#ifndef LAPTOP
#define LAPTOP

#include"computer.h"

class Laptop:public Computer{
private:
        double batteria;
        double pollici;
        double peso;
public:

        //COSTRUTTORE

        explicit Laptop(double=0 ,int=0 , std::string="",  std::string="" , std::string="", std::string="", std::string="", double =0,double =0,double=0);

        //GETTER

        double getBatteria() const;
        double getPollici() const;
        double getPeso() const;

        //SETTER

        void setBatteria(double =0);
        void setPollici(double =0);
        void setPeso(double =0);

        //METODI PROPRI

        double CalcolaAutonomia()const;

        //METODI EREDITATI

        bool operator==(Device&)const override;
        std::string CalcolaRating()const override;
        std::ostream& operator<< (std::ostream& ) override;
        std::string details()override;
        std::string get(std::string)override;

        //DISTRUTTORE

        ~Laptop()override =default;
};

#endif // LAPTOP

