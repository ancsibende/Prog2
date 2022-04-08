#ifndef Cim_h
#define Cim_h

#include <iostream>
#include <string>

class Cim{ ///Cim osztaly
    std::string iranyitoszam;
    std::string telepules;
    std::string utca_hsz;
public:
    Cim();
    std::string getIranyitoszam();
    std::string getTelepules();
    std::string getUtca_Hsz();
    void setIranyitoszam(std::string iszam);
    void setTelepules(std::string t);
    void setUtca_Hsz(std::string u_h);

    void getMind();
    void setMind(std::string iranyitoszam,std::string telepules,std::string utca_hsz);

    friend std::ostream& operator<<(std::ostream& os,const Cim& c){
        os<<c.iranyitoszam<<std::endl<<c.telepules<<std::endl<<c.utca_hsz<<std::endl;
        return os;
    }

    friend std::istream & operator >> (std::istream &in,  Cim &c) {
    std::cout<<std::endl<<"Adja meg az iranyitoszamot: ";
    in>>c.iranyitoszam;
    std::cout<<std::endl<<"Adja meg a telepulest: ";
    in>>c.telepules;
    std::cout<<std::endl<<"Adja meg az utcat es a hazszamot: ";
    in>>c.utca_hsz;

    return in;
    }
};

#endif // Cim_h

