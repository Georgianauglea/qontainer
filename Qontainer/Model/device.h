#ifndef DEVICES
#define DEVICES

#include"string"

class Device { //CLASSE BASE ASTRATTA
    private:
        double CPU;
        int RAM;
        std::string marca;
        std::string modello;
        std::string hardisk;
        std::string SO;

    protected:

        //COSTRUTTORE

         Device(double =0, int=0, std::string="", std::string="",std::string="", std::string="");

    public:

        //GETTER

        double getCPU() const;
        int getRAM() const;
        std::string getMarca() const;
        std::string getModello() const;
        std::string getHardisk() const;
        std::string getSO() const;

        //SETTER

        void setCPU(double =0);
        void setRAM(int =0);
        void setMarca(std::string ="Non specificato");
        void setModello(std::string ="Non specificato");
        void setHardisk(std::string ="Non specificato");
        void setSO(std::string ="Non specificato");

        //METODI VIRTUALI PURI

        virtual std::string CalcolaRating()const =0;
        virtual bool operator==(Device&)const =0;
        virtual std::ostream& operator<< (std::ostream& )=0;
        virtual std::string details()=0;
        virtual std::string get(std::string)=0;

        //DISTRUTTORE
        virtual ~Device()=default;
};

#endif // DEVICES

