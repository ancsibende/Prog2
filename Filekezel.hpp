#ifndef FILEKEZEL_HPP_INCLUDED
#define FILEKEZEL_HPP_INCLUDED
#include <string>
#include <fstream>
#include "iterator.hpp"
#include "cross_platform.h"

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;

void uressor_torlese(const string &fajl){
    ifstream fajlom(fajl);
    string line, text;
    while (cp::getline(fajlom, line)){
        if (!(line.empty() || line.find_first_not_of(' ') == std::string::npos))
            text += line + "\n";}
    fajlom.close();
    std::ofstream out(fajl);
    out << text;
    }


Lista<Szemely> Fajlkezel(){
    string egysor;
    ifstream fajlom("Adat.txt");
    Lista<Szemely> l;

    if(fajlom.is_open()){
        while(cp::getline(fajlom,egysor)){
        Szemely sz;
        Telefonszam t;
        Cim c;

            sz.setNev(egysor);
            cp::getline(fajlom,egysor);
            sz.setBnev(egysor);

            cp::getline(fajlom,egysor);
            c.setIranyitoszam(egysor);

            cp::getline(fajlom,egysor);
            c.setTelepules(egysor);

            cp::getline(fajlom,egysor);
            c.setUtca_Hsz(egysor);
            cp::getline(fajlom,egysor);
            t.setMTelszam(egysor);
            cp::getline(fajlom,egysor);
            t.setPTelszam(egysor);

            sz.setTelszam(t);
            sz.setCim(c);

            l.beszur(sz);
        }
    }else{
        throw "Nem tudtuk beolvasni a fajlt";
    }

    fajlom.close();
    return l;
}

Lista<Szemely> FajlbolTorol(){
    bool sikeresvolt=false;
    string egysor;
    ifstream fajlom("Adat.txt");
    Lista<Szemely> l;

    ofstream temp;
    temp.open("Uj_adat.txt",ios::app);

    string adat;
    cout<<"Adja meg a torolni kivant nevet: ";
    cin.ignore();
    cp::getline(cin,adat);
    if(fajlom.is_open()){
        while(cp::getline(fajlom,egysor)){

            Szemely sz;
            Telefonszam t;
            Cim c;

            if(egysor!=adat){
                sz.setNev(egysor);
                temp<<endl<<egysor;
                cp::getline(fajlom,egysor);
                sz.setBnev(egysor);
                temp<<endl<<egysor;

                cp::getline(fajlom,egysor);
                c.setIranyitoszam(egysor);
                temp<<endl<<egysor;

                cp::getline(fajlom,egysor);
                c.setTelepules(egysor);
                temp<<endl<<egysor;

                cp::getline(fajlom,egysor);
                c.setUtca_Hsz(egysor);
                temp<<endl<<egysor;
                cp::getline(fajlom,egysor);
                t.setMTelszam(egysor);
                temp<<endl<<egysor;
                cp::getline(fajlom,egysor);
                t.setPTelszam(egysor);
                temp<<endl<<egysor;

                sz.setTelszam(t);
                sz.setCim(c);

                l.beszur(sz);
        }else if(egysor==adat){
                sikeresvolt=true;
                for(int i=0;i<6;i++) cp::getline(fajlom,egysor);
                }
            }
        }else{cout<< "Nem tudtuk beolvasni a fajlt";
    }

    uressor_torlese("Uj_adat.txt");
    temp.close();
    fajlom.close();
    remove("Adat.txt");
    rename("Uj_adat.txt","Adat.txt");

    if(sikeresvolt==true){
        cout<<"Sikeresen toroltuk az adatot!"<<endl;
    }else{
        cout<<"Ilyen nevu szemely nincs a telefonkonyvben, nem tudtuk torolni!"<<endl;}

    return l;
}

Lista<Szemely> FajltModosit(){
    string egysor;
    ifstream fajlom("Adat.txt");
    Lista<Szemely> l;

    ofstream temp;
    temp.open("Uj_adat.txt",ios::app);

    string adat;
    cout<<"Adja meg a modositani kivant nevet: ";
    cin.ignore();
    cp::getline(cin,adat);
    if(fajlom.is_open()){
        while(cp::getline(fajlom,egysor)){

            Szemely sz;
            Telefonszam t;
            Cim c;

            if(egysor!=adat){
                sz.setNev(egysor);
                temp<<endl<<egysor;
                cp::getline(fajlom,egysor);
                sz.setBnev(egysor);
                temp<<endl<<egysor;

                cp::getline(fajlom,egysor);
                c.setIranyitoszam(egysor);
                temp<<endl<<egysor;

                cp::getline(fajlom,egysor);
                c.setTelepules(egysor);
                temp<<endl<<egysor;

                cp::getline(fajlom,egysor);
                c.setUtca_Hsz(egysor);
                temp<<endl<<egysor;
                cp::getline(fajlom,egysor);
                t.setMTelszam(egysor);
                temp<<endl<<egysor;
                cp::getline(fajlom,egysor);
                t.setPTelszam(egysor);
                temp<<endl<<egysor;

                sz.setTelszam(t);
                sz.setCim(c);

                l.beszur(sz);
        }else if(egysor==adat){
                for(int i=0;i<6;i++) cp::getline(fajlom,egysor);
            }
        }
        }else{cout<< "Nem tudtuk beolvasni a fajlt";
    }

    uressor_torlese("Uj_adat.txt");
    temp.close();
    fajlom.close();
    remove("Adat.txt");
    rename("Uj_adat.txt","Adat.txt");

    return l;
}

#endif // FILEKEZEL_HPP_INCLUDED

