#include "mailcmd.h"
#include "mailserver.h"
#include <iostream>
#include "gtuvos.h"

using namespace std;

MailCMD::MailCMD(QStringList params):ICommand(params)
{
    cout<<"MailCMD constructed!"<<endl;
}


void MailCMD::execute(){
   cout<<"MailCMD execute cmd!!"<<endl;
}

MailCMD::~MailCMD(){
}
