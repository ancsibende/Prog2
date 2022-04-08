#include <iostream>
#include "iterator.hpp"
#include "Szemely.h"
#include "Menu.h"
#include "Cim.h"
#include "Telefonszam.h"
//#include "memtrace.h"

using namespace std;

int main(){
    //std::ifstream in("standard_input.txt");
    //std::cin.rdbuf(in.rdbuf());

    try{
    FOMENU();
    }
    catch(exception& e){
        cout<<e.what()<<endl;
    }
    catch(...){
    cout<<"Nem jo tipusu opciot adtal meg!"<<endl;}

};
