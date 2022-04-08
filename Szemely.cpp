#include "Szemely.h"
using namespace std;

Szemely::Szemely(){
    this->nev= "Simon Karoly";
    this->becenev="Karcsi";
}

string Szemely::getNev(){
    return nev;
}

string Szemely::getBnev(){
    return becenev;
}

string Szemely::getIranyito(){
    return cim.getIranyitoszam();
}

string Szemely::getTelepules(){
    return cim.getTelepules();
}

string Szemely::getUtca_Hsz(){
    return cim.getUtca_Hsz();
}

void Szemely::getCim(){
    this->cim.getMind();
}

string Szemely::getMTelszam(){
    return telefonszam.getMTelszam();
}

string Szemely::getPTelszam(){
    return telefonszam.getPTelszam();
}

void Szemely::getTelszam(){
    this->telefonszam.getMind();
}

void Szemely::setNev(string n){
    nev=n;
}

void Szemely::setBnev(string bn){
    becenev=bn;
}

void Szemely::setCim(Cim c){
    cim=c;
}

void Szemely::setTelszam(Telefonszam t){
    telefonszam=t;
}

void Szemely::getMIND(){
    cout<<this->nev<<endl<<this->becenev<<endl;
    getCim();
    getTelszam();
}

void Szemely::setMIND(string n,string bn,Cim cim,Telefonszam telszam){
    setNev(n);
    setBnev(bn);
    setCim(cim);
    setTelszam(telszam);
}

