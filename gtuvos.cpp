#include <iostream>
#include "gtuvos.h"
#include <vector>

using namespace std;

GTUVOS *GTUVOS::instance= NULL;

GTUVOS::GTUVOS(){
    name = "GTU Virtual OS";
    version = 0.1;

    prepareSystem();
}

void GTUVOS::prepareSystem(){
    cout<< "GTUVOS prepared!!"<<endl;
}


vector<string> GTUVOS::parseStr(string str){
    cout<<"parseStr: "<<str<<endl;
    vector<string> parses;

    parses.push_back("fuckSercan");
    return parses;
}

bool GTUVOS::executeCmd(string str){
    vector<string> parses = parseStr(str);

    cout<<parses[0]<<endl;
    return true;
}

double GTUVOS::getVersion() const{
    return version;
}

string GTUVOS::getName() const{
    return name;
}
