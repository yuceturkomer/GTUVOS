#include <iostream>
#include "gtuvos.h"
#include <vector>
#include <QApplication>
#include <QVector>
#include "command.h"
#include "commandfactory.h"
#include "mailcmd.h"
#include "gtuexceptions.h"


using namespace std;

GTUVOS *GTUVOS::instance= NULL;

GTUVOS::GTUVOS(){
    name = "GTU Virtual OS";
    version = 1.3;

    prepareSystem();

    cout<<"GTUVOS constructed!"<<endl;
}

void GTUVOS::prepareSystem(){
    cout<< "GTUVOS prepareSystem started!!"<<endl;
    // TODO: check os files
}


double GTUVOS::getVersion() const{
    return version;
}

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

MailServer& GTUVOS::getMailServer(){
    return mailServer;
}
