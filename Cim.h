#ifndef Cim_h
#define Cim_h

#include <iostream>
#include <string>
using namespace std;

class Cim{ ///Cim osztaly
    string iranyitoszam;
    string telepules;
    string utca_hsz;
public:
    Cim();
    string getIranyitoszam();
    string getTelepules();
    string getUtca_Hsz();
    void setIranyitoszam(string iszam);
    void setTelepules(string t);
    void setUtca_Hsz(string u_h);

    void getMind();
    void setMind(string iranyitoszam,string telepules,string utca_hsz);

    friend ostream& operator<<(ostream& os,const Cim& c){
        os<<c.iranyitoszam<<endl<<c.telepules<<endl<<c.utca_hsz<<endl;
        return os;
    }

    friend istream & operator >> (istream &in,  Cim &c) {
    cout<<endl<<"Adja meg az iranyitoszamot: ";
    in>>c.iranyitoszam;
    cout<<endl<<"Adja meg a telepulest: ";
    in>>c.telepules;
    cout<<endl<<"Adja meg az utcat es a hazszamot: ";
    in>>c.utca_hsz;

    return in;
    }
};

#endif // Cim_h

