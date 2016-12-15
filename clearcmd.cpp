/**
 * Virtual Operating System Clear Command
 *
 * File:   clearcmd.cpp
 *
 * @author CSE_343_Software Engineering_Group_2
 * @since Thursday 15 December 2016
 */

#include "clearcmd.h"


ClearCMD::~ClearCMD(){

}

ClearCMD::ClearCMD(QStringList params):ICommand(params)
{
    cout<<"Clear cmd constructed"<<endl;
}

void ClearCMD::execute(Ui::MainWindow *mainWindow){
    cout<<"Clear execute started."<<endl;

    if(mParams.size()!=1){
        printTerm(mainWindow,"Invalid clear parameter","red");
        printTerm(mainWindow,"Please check help manual","DeepSkyBlue");
        return;
    }
    mainWindow->terminalScreen->setText("");

    // get system informations and print on startup
    double version = GTUVOS::getInstance()->getVersion();
    QString name = QString::fromStdString(GTUVOS::getInstance()->getName());

    ICommand::printTerm(mainWindow,"Welcome to " +name+"\n");
    ICommand::printTerm(mainWindow,"Version "+QString::number(version)+"\n");
    ICommand::printTerm(mainWindow,"Write 'help' to see all commands""\n");
    ICommand::printTerm(mainWindow,"~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-");

}
