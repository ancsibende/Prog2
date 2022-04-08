
#ifndef iter_h
#define iter_h
#include <fstream>
#include <iostream>
#include <ostream>
#include <string.h>
#include "Szemely.h"
//#include "cross_platform.h"

using  std::cout;
using std::cin;
using std::out_of_range;
using std::endl;
using std::string;
using std::ifstream;


template<class T>
class Lista  {
   struct ListaElem {
     T  adat;
     ListaElem *kov;
     ListaElem(ListaElem *p = NULL) :kov(p) {}
     ListaElem& operator=(const ListaElem);
};
    ListaElem *elso;
    ListaElem *akt;
  public:
    Lista(const Lista&);
    Lista& operator=(const Lista&);
    bool hasonlit( T a1, T a2) { return(a1<a2);}

    Lista() { akt = elso = new ListaElem;}
    void beszur(const T& dat);
    void torol(const T& dat);
    void kiir();
        class iterator;
   iterator begin() {
     return(iterator(*this));
   }
   iterator end() {
     return(iterator());
   }
   class iterator {
     ListaElem *akt;
   public:
	 iterator() : akt(NULL) {};
 	 iterator(const Lista& l) : akt(l.elso) {
	   if (akt->kov == NULL)
         akt = NULL;
     }
	 iterator& operator++() {
       if (akt != NULL) {
         akt = akt->kov;
         if (akt->kov == NULL)
           akt = NULL;
       }
       return(*this);
     }
     iterator operator++(int) {
       iterator tmp = *this;
       operator++();
       return(tmp);
     }
     bool operator!=(const iterator &i) const {
       return(akt != i.akt);
	 }
     T& operator*() {
       if (akt != NULL ) return(akt->adat);
       else throw out_of_range("Hibas");
     }
	 T* operator->() {
       if (akt != NULL) return(&akt->adat);
       else throw out_of_range("Hibas");
     }
   };

        ~Lista();
};

template <class T>
Lista<T>::~Lista() {
	ListaElem *mozgo;
    while ((mozgo = elso) != NULL) {
        elso = mozgo->kov;
        delete mozgo;
    }
}

template <class T>
void Lista<T>::beszur(const T& dat) {
	ListaElem *mozgo=NULL;
	ListaElem *uj=NULL;

    for (mozgo=elso; mozgo->kov != NULL && hasonlit(mozgo->adat, dat);mozgo = mozgo->kov);
    uj = new ListaElem(*mozgo);
    mozgo->adat = dat;
    mozgo->kov = uj;
}

template <class T>
void Lista<T>::kiir(){
    ListaElem *mozgo;
    for(mozgo=elso;mozgo->kov!=NULL;mozgo=mozgo->kov){
        cout<<mozgo->adat;
        cout<<"--------------------"<<endl;
    }
}

template <class Iterator,class S>
void keres_nevszerint(Iterator elso,Iterator utolso,S s){
    bool sikeres=false;
    string nev;
    cout<<"Adja meg a keresni kivant nevet: ";
    cin.ignore();
    getline(cin,nev);

            for(;elso!=utolso;elso++){
                    s=*elso;
                    if(s.getNev()==nev){
                            sikeres=true;
                        cout<<"A keresett szemely adatai:"<<endl<<endl;
                        s.getMIND();
                    }

            }
                if(sikeres!=true){cout<<"Nincs ilyen nevu ember!"<<endl;}

}

template<class Iterator,class S>
void iranyitoval_keres(Iterator elso,Iterator utolso,S s){
    bool siker=false;
        string i;
        cout<<"Adja meg a keresett iranyitoszamot: ";
        cin>>i;

        for(;elso!=utolso;elso++){
                    s=*elso;

                    if(s.getIranyito()==i){
                        siker=true;

                        cout<<"A keresett szemely adatai:"<<endl<<endl;
                        s.getMIND();
                    }
            }
        if(siker!=true){cout<<"Nincs ilyen iranyitoszammal rendelkezo ember!"<<endl;}

}

template<class Iterator,class S>
void telepulessel_keres(Iterator elso,Iterator utolso,S s){
        bool siker=false;
            string tlp;
            cout<<"Adja meg a keresett telepulest: ";
            cin>>tlp;

        for(;elso!=utolso;elso++){
                    s=*elso;
                    if(s.getTelepules()==tlp){
                        siker=true;

                        cout<<"A keresett szemely adatai:"<<endl<<endl;
                        s.getMIND();
                    }

            }
        if(siker!=true){cout<<"Nincs ilyen telepulesen lako ember!"<<endl;}
}

template<class Iterator, class S>
void utcahsz_keres(Iterator elso,Iterator utolso,S s){
        bool siker=false;
            string uh;
            cout<<"Adja meg a keresett utcat es hazszamot: ";
            cin.ignore();
            getline(cin,uh);

        for(;elso!=utolso;elso++){
                    s=*elso;
                    if(s.getUtca_Hsz()==uh){
                        siker=true;

                        cout<<"A keresett szemely adatai:"<<endl<<endl;
                        s.getMIND();
                    }
            }
        if(siker!=true){cout<<"Nincs ilyen utcaban lako szemely!"<<endl;}
}

template<class Iterator,class S>
void keres_cimszerint(Iterator elso,Iterator utolso,S s){

    int alapjan;
    cout<<"Milyen adatot ismer biztosan a cimbol?: "<<endl;
    cout<<"1. Iranyitoszamot"<<endl;
    cout<<"2. Telepulest"<<endl;
    cout<<"3. Utcat es hazszamot"<<endl;
    cout<<"Valasztasom: ";
    cin>>alapjan;


    switch(alapjan){
    case 1:
        iranyitoval_keres(elso,utolso,s);
        break;
    case 2:
        telepulessel_keres(elso,utolso,s);
        break;
    case 3:
        utcahsz_keres(elso,utolso,s);
        break;
    default:
        cout<<"Ilyen opcio nincs, probalja ujra!"<<endl;
    }

}

template<class Iterator,class S>
void keres_telszamszerint(Iterator elso,Iterator utolso,S s){
    bool siker=false;
    string egysor;
    ifstream fajlom("Adat.txt");

    string telszam;
    cout<<"Adja meg a keresni kivant telefonszamot: ";
    cin>>telszam;

            for(;elso!=utolso;elso++){
                    s=*elso;

                    if(s.getMTelszam()==telszam||s.getPTelszam()==telszam){
                        siker=true;

                        cout<<"A keresett szemely adatai:"<<endl<<endl;
                        s.getMIND();
                    }

            }
                if(siker!=true){cout<<"Nincs ilyen telefonszamu ember!"<<endl;}
}

template <class T>          // tagfüggvénysablon
void Lista<T>::torol(const T& dat) {
	ListaElem *lemarad=NULL;
	ListaElem *p=elso;
	while(p!=NULL && hasonlit(p->adat,dat)){
        lemarad=p;
        p=p->kov;
	}
	if(p==NULL){

	}
	else if(lemarad==NULL){
        ListaElem *uj=p->kov;
        delete p;
        elso=uj;
	}
	else{
        lemarad->kov=p->kov;
        delete p;
	}
}

template <class Iterator,typename S,typename T>
bool nev_letezik_e(Iterator elso,Iterator utolso,S s,T t){
            for(;elso!=utolso;elso++){
                    t=*elso;
                    if(t.getNev()==s){
                        cout<<"Ilyen nevezetu ember mar van a telefonkonyvben!"<<endl;
                        return true;
                    }
            }
            return false;
}
#endif // iter_h
