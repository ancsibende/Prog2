
#ifndef Telefonszam_h
#define Telefonszam_h

#include <iostream>
#include <string>
using namespace std;

class Telefonszam{ ///Telefonszam osztaly
    string munkahelyi;
    string privat;
public:
    Telefonszam();
    string getMTelszam();
    string getPTelszam();
    void setMTelszam(string mszam);
    void setPTelszam(string pszam);

    void getMind();
    void setMind(string munkahelyi,string privat);

     friend ostream& operator<<(ostream& os,const Telefonszam& t){
        os<<t.munkahelyi<<endl<<t.privat<<endl;
        return os;
    }


    friend istream & operator >> (istream &in,  Telefonszam& t) {
    cout<<endl<<"Adja meg a munkahelyi telefonszamat: ";
    in>>t.munkahelyi;
    cout<<endl<<"Adja meg a privat telefonszamat: ";
    in>>t.privat;

    return in;
    }
};

#endif //Telszam_h
