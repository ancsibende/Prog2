#ifndef Szemely_h
#define Szemely_h
#include "iterator.hpp"
#include "Cim.h"
#include "Telefonszam.h"
#include <string>
#include <stdio.h>
#include <iostream>

class Szemely{ ///Szemely osztaly
    std::string nev;
    std::string becenev;
    Cim cim;
    Telefonszam telefonszam;
public:
    Szemely();

    std::string getNev();
    std::string getBnev();
    void getCim();
    std::string getIranyito();
    std::string getTelepules();
    std::string getUtca_Hsz();
    void getTelszam();
    std::string getMTelszam();
    std::string getPTelszam();
    void setNev(std::string n);
    void setBnev(std::string bn);
    void setCim(Cim c);
    void setTelszam(Telefonszam t);

    void getMIND();
    void setMIND(std::string n,std::string bn,Cim cim,Telefonszam telefonszam);

    friend std::ostream& operator<<(std::ostream& os,const Szemely& s){
        os<<s.nev<<std::endl<<s.becenev<<std::endl<<s.cim<<std::endl<<s.telefonszam;
        return os;
    }

    friend bool operator<(Szemely& p,Szemely& q){
        return(p.getNev()<q.getNev());
    }

    friend std::istream & operator >> (std::istream &in,  Szemely &sz) {
    std::cout<<"Adja meg a nevet: ";
    in>>sz.nev;
    std::cout<<"Adja meg a becenevet: ";
    in>>sz.becenev;

    return in;
}
};

#endif // Szemely_h

