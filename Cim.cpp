#include "Cim.h"
using namespace std;

Cim::Cim(){
    this->iranyitoszam="1098";
    this->telepules="Budapest";
    this->utca_hsz="Lobogo utca 9.";
}

string Cim::getIranyitoszam(){
    return iranyitoszam;
}

string Cim::getTelepules(){
    return telepules;
}

string Cim::getUtca_Hsz(){
    return utca_hsz;
}

void Cim::setIranyitoszam(string iszam){
   iranyitoszam=iszam;
}

void Cim::setTelepules(string t){
    telepules=t;
}

void Cim::setUtca_Hsz(string u_h){
    utca_hsz=u_h;
}

void Cim::getMind(){
    cout<<this->iranyitoszam<<endl<<this->telepules<<endl<<this->utca_hsz<<endl;
}

void Cim::setMind(string iranyitoszam,string telepules,string utca_hsz){
    setIranyitoszam(iranyitoszam);
    setTelepules(telepules);
    setUtca_Hsz(utca_hsz);
}

