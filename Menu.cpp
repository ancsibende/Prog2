#include "Menu.h"
#include <string>
#include <fstream>
#include <iostream>
#include <ostream>
#include <cstdlib>
#include "Szemely.h"
#include "iterator.hpp"
#include"Filekezel.hpp"
#include "cross_platform.h"

using namespace std;

int valaszt(){
    int choice;
    cout<<"***** TELEFONKONYV *****"<<endl;
    cout << "1. Kereses"<<endl;
    cout << "2. Adatok felvetele"<<endl;
    cout << "3. Adatok torlese"<<endl;
    cout << "4. Adatok modositasa"<<endl;
    cout << "5. Listazas"<<endl;
    cout << "6. Kilepes"<<endl;
    cout<<"Adja meg, hogy melyik opciot valasztotta: ";
    cin>>choice;
    if(choice>0&&choice<10){
    return choice;}
    else{
        throw "Hiba";
    }
}

void KERES(){
    bool vege=false;
    int valasz;
    Szemely sz;
    Lista <Szemely> l=Fajlkezel();
    while(vege==false){
            cout<<"Mi szerint szeretne keresni?"<<endl;
            cout<<"1. Nev szerint"<<endl;
            cout<<"2. Cim szerint"<<endl;
            cout<<"3. Telefonszam szerint"<<endl;
            cout<<"4. Vissza a fomenube"<<endl;
            cout<<"Valasztott opcio szama: ";
            cin>>valasz;
        switch(valasz){
            case 1:{
                keres_nevszerint(l.begin(),l.end(),sz);
                break;
            case 2:
                keres_cimszerint(l.begin(),l.end(),sz);
                break;
            case 3:
                keres_telszamszerint(l.begin(),l.end(),sz);
                break;
            case 4 :
                vege=true;
                break;

            default:
                cout<<"Ilyen opcio nincs, probalja ujra!"<<endl;
            }
        }
    }
}

void TOROL(){
cout<<endl<<"----- ADATOK TORLESE -----"<<endl;
    Lista<Szemely> l=FajlbolTorol();
}

void ADATFELVET(){
    cout<<endl<<"----- ADATOK FELVETELE -----"<<endl;

    ofstream fajlom;
    fajlom.open("Adat.txt",ios::app);
    bool letezik_e_mar=false;

    Lista <Szemely> m=Fajlkezel();


    if(fajlom.is_open()){
                Lista<Szemely> l;
                Szemely sz;
                Telefonszam t;
                Cim c;

                string nev;
                string bc;

                string ir;
                string tl;
                string uh;
                string msz;
                string psz;

                cout<<"Adja meg a nevet: ";
                cin.ignore();
                cp::getline(cin,nev);
                letezik_e_mar=nev_letezik_e(m.begin(),m.end(),nev,sz);
                 if(letezik_e_mar==true){
                        cout<< "Probalja ujra!"<<endl;
                        fajlom.close();
                        }else{

                fajlom<<nev<<endl;
                sz.setNev(nev);
                cout<<"Adja meg a becenevet: ";
                cin>>bc;
                fajlom<<bc<<endl;
                sz.setBnev(bc);
                cout<<"Adja meg az iranyitoszamot: ";
                cin>>ir;
                fajlom<<ir<<endl;
                c.setIranyitoszam(ir);
                cout<<"Adja meg a telepulest: ";
                cin>>tl;
                fajlom<<tl<<endl;
                c.setTelepules(tl);
                cout<<"Adja meg az utcat es a hazszamot: ";
                cin.ignore();
                getline (cin, uh);
                fajlom<<uh<<endl;
                c.setUtca_Hsz(uh);
                cout<<"Adja meg a munkahelyi telefonszamat: ";
                cin>>msz;
                t.setMTelszam(msz);
                fajlom<<msz<<endl;
                cout<<"Adja meg a privat telefonszamat: ";
                cin>>psz;
                fajlom<<psz;
                t.setPTelszam(psz);


                l.beszur(sz);
                fajlom.close();}
        }
}

void adat_modosit(){

    ofstream fajlom;
    fajlom.open("Adat.txt",ios::app);

    if(fajlom.is_open()){
                Szemely sz;
                Telefonszam t;
                Cim c;

                string nev;
                string bc;

                string ir;
                string tl;
                string uh;
                string msz;
                string psz;

                cout<<"Adja meg az uj nevet: ";
                getline (cin, nev);
                fajlom<<endl<<nev<<endl;
                sz.setNev(nev);
                cout<<"Adja meg az uj becenevet: ";
                cin>>bc;
                fajlom<<bc<<endl;
                sz.setBnev(bc);
                cout<<"Adja meg az uj iranyitoszamot: ";
                cin>>ir;
                fajlom<<ir<<endl;
                c.setIranyitoszam(ir);
                cout<<"Adja meg a telepulest: ";
                cin>>tl;
                fajlom<<tl<<endl;
                c.setTelepules(tl);
                cout<<"Adja meg az uj utcat es hazszamot: ";
                cin.ignore();
                getline (cin, uh);
                fajlom<<uh<<endl;
                c.setUtca_Hsz(uh);
                cout<<"Adja meg a munkahelyi telefonszamot: ";
                cin>>msz;
                t.setMTelszam(msz);
                fajlom<<msz<<endl;
                cout<<"Adja meg a privat telefonszamot: ";
                cin>>psz;
                fajlom<<psz;
                t.setPTelszam(psz);


                Lista<Szemely> l;
                l.beszur(sz);

                fajlom.close();

        }

}

void MODOSIT(){
    cout<<endl<<"----- ADATOK MODOSITASA -----"<<endl;
    Lista<Szemely> l=FajltModosit();
    adat_modosit();
}

void LISTAZAS(){
cout<<endl<<"----- ADATOK LISTAZASA -----"<<endl;
    Lista<Szemely> l=Fajlkezel();
    l.kiir();
}

void FOMENU(){
    bool vege=false;
    while(vege==false){
    int choice=valaszt();
        switch(choice){
            case 1:
                KERES();
            break;
            case 2:
                ADATFELVET();
            break;
            case 3:
                TOROL();
                break;
            case 4:
                MODOSIT();
                break;
            case 5:
                LISTAZAS();
            break;
            case 6:
                cout<<"Viszlat!";
                vege=true;
                break;

            default:
                cout<<"Hibas muveletszam, probalja ujra"<<endl;
        }
    }
}
