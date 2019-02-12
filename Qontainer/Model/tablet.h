#ifndef TABLET
#define TABLET

#include"portable.h"

class Tablet:public Portable {
    private:
        bool SIM;
    public:

        //COSTRUTTORE

        explicit Tablet(double=0 ,int=0 ,std::string="",std::string="", std::string="", std::string="",double=0,double=0, double=0,int=0,std::string="", bool =false);

        //GETTER

        bool getSIM() const;

        //SETTER

        void setSIM(bool =false);

        //METODI EREDITATI

        bool operator==(Device&)const override;
        std::string CalcolaRating()const override;
        double CalcolaAutonomia()const override;
        std::ostream& operator<< (std::ostream& ) override;
        std::string details()override;
        std::string get(std::string)override;

        //DISTRUTTORE

        ~Tablet()override =default;
};
#endif // TABLET

