#include "Telefonszam.h"
using namespace std;

Telefonszam::Telefonszam(){
    this->munkahelyi="06303418871";
    this->privat="06201258432";
}

string Telefonszam::getMTelszam(){
    return munkahelyi;
 }

string Telefonszam::getPTelszam(){
    return privat;
}

void Telefonszam::setMTelszam(string mszam){
    munkahelyi=mszam;
}

void Telefonszam::setPTelszam(string pszam){
    privat=pszam;
}

void Telefonszam::getMind(){
    cout << this ->munkahelyi  << " " << endl<< this ->privat<<endl;
}

void Telefonszam::setMind(string munkahelyi,string privat){
    setMTelszam(munkahelyi);
    setPTelszam(privat);
}

