#include <iostream>
#include "gtuvos.h"
#include <vector>
#include <QApplication>
#include <QVector>
#include <QDir>
#include "command.h"
#include "commandfactory.h"
#include "mailcmd.h"
#include "gtuexceptions.h"


using namespace std;

GTUVOS *GTUVOS::instance= NULL;

GTUVOS::~GTUVOS(){
    delete mailServer;
    mailServer=NULL;
    cout<<"GTUVOS destructed!"<<endl;
}

GTUVOS::GTUVOS(){
    name = "GTU Virtual OS";
    version = 2.1;

    prepareSystem();

    mailServer = new MailServer();
    cout<<"GTUVOS constructed!"<<endl;
}

void GTUVOS::prepareSystem(){
    cout<< "GTUVOS prepareSystem started!!"<<endl;

    checkRootFile();
    // check other dependencies

}


/*
 * Isletim sisteminin on tanımlı versiyon numarasını dondurur
 */
double GTUVOS::getVersion() const{
    return version;
}

/*
 * Istelim sisteminin adini dondurur
 */
string GTUVOS::getName() const{
    return name;
}

bool GTUVOS::executeCMD(QString cmdStr){

    ICommand *command=NULL;
    try{
        ICommand *command = CommandFactory::getInstance()->getCommand(cmdStr);
        command->execute(window);
    }catch(exception& e){
        ICommand::printTerm(window,e.what(),"red");
    }

    if(command!=NULL)
      delete command;

    return true;
}

MailServer* GTUVOS::getMailServer(){
    return mailServer;
}

string GTUVOS::getRootPath() const{
    return ROOTFileName;
}


void GTUVOS::checkRootFile(){

    string path=getRootPath();
    // gizli olarak root directory olmalı
    QDir root(QString::fromStdString(path));
    if(root.exists()){
        cout<<"Root Directory exist."<<endl;
    }else{
        root.mkpath(".");
        cout<<"Root path created!"<<endl;
    }
}
