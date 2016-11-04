#include "mailcmd.h"
#include "mailserver.h"
#include <iostream>
#include "gtuvos.h"

using namespace std;

MailCMD::MailCMD(QStringList params):ICommand(params)
{
    cout<<"MailCMD constructed!"<<endl;
}


void MailCMD::execute(Ui::MainWindow *window){
   window->terminalScreen->insertPlainText("MailCMD execute cmd!!\n");
}

MailCMD::~MailCMD(){
}
