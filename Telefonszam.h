#ifndef Telefonszam_h
#define Telefonszam_h

#include <iostream>
#include <string>

class Telefonszam{ ///Telefonszam osztaly
    std::string munkahelyi;
    std::string privat;
public:
    Telefonszam();
    std::string getMTelszam();
    std::string getPTelszam();
    void setMTelszam(std::string mszam);
    void setPTelszam(std::string pszam);

    void getMind();
    void setMind(std::string munkahelyi,std::string privat);

     friend std::ostream& operator<<(std::ostream& os,const Telefonszam& t){
        os<<t.munkahelyi<<std::endl<<t.privat<<std::endl;
        return os;
    }


    friend std::istream & operator >> (std::istream &in,  Telefonszam& t) {
    std::cout<<std::endl<<"Adja meg a munkahelyi telefonszamat: ";
    in>>t.munkahelyi;
    std::cout<<std::endl<<"Adja meg a privat telefonszamat: ";
    in>>t.privat;

    return in;
    }
};

#endif //Telszam_h
