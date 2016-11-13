#include "helpcmd.h"
#include "command.h"
#include "QApplication"
#include "gtuvos.h"

#include <iostream>
using namespace  std;


HelpCMD::~HelpCMD(){
}

HelpCMD::HelpCMD(QStringList params):ICommand(params)
{
    cout<<"HelpCmd constructed!!"<<endl;
}

void HelpCMD::execute(Ui::MainWindow *mainWindow){
    // Information for running the command
    printTerm(mainWindow,"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--- Help Manual ---","purple");
    printTerm(mainWindow,"&nbsp;&nbsp;&nbsp;The available commands are:<br>","purple");
    printTerm(mainWindow,"&nbsp;-&nbsp;&nbsp;help<br>"
                         "&nbsp;-&nbsp;&nbsp;cp &nbsp;&nbsp;&nbsp;file_source &nbsp;&nbsp;&nbsp;file_destination<br>"
                         "&nbsp;-&nbsp;&nbsp;mail&nbsp;&nbsp;list<br>"
                         "&nbsp;-&nbsp;&nbsp;mail&nbsp; \"send\" &nbsp;&nbsp; \"to\"&nbsp;&nbsp;&nbsp; \"title\"&nbsp;&nbsp;&nbsp;\"subject\"<br>"
                         "&nbsp;-&nbsp;&nbsp;ls&nbsp;&nbsp;&nbsp;path (path is optional)","blue");
}
