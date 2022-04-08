#ifndef Szemely_h
#define Szemely_h
#include "iterator.hpp"
#include "Cim.h"
#include "Telefonszam.h"
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;


class Szemely{ ///Szemely osztaly
    string nev;
    string becenev;
    Cim cim;
    Telefonszam telefonszam;
public:
    Szemely();

    string getNev();
    string getBnev();
    void getCim();
    string getIranyito();
    string getTelepules();
    string getUtca_Hsz();
    void getTelszam();
    string getMTelszam();
    string getPTelszam();
    void setNev(string n);
    void setBnev(string bn);
    void setCim(Cim c);
    void setTelszam(Telefonszam t);

    void getMIND();
    void setMIND(string n,string bn,Cim cim,Telefonszam telefonszam);

    friend ostream& operator<<(ostream& os,const Szemely& s){
        os<<s.nev<<endl<<s.becenev<<endl<<s.cim<<endl<<s.telefonszam;
        return os;
    }

    friend bool operator<(Szemely& p,Szemely& q){
        return(p.getNev()<q.getNev());
    }

    friend istream & operator >> (istream &in,  Szemely &sz) {
    cout<<"Adja meg a nevet: ";
    in>>sz.nev;
    cout<<"Adja meg a becenevet: ";
    in>>sz.becenev;

    return in;
}
};

#endif // Szemely_h

