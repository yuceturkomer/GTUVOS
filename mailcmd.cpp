#include "mailcmd.h"
#include "mailserver.h"

#include <mail.h>

#include <fstream>
#include <string>

#include <iostream>
#include "gtuvos.h"

using namespace std;

MailCMD::MailCMD(QStringList params):ICommand(params)
{
    cout<<"MailCMD constructed!"<<endl;
}


<<<<<<< HEAD
void MailCMD::execute(){
   cout<<"MailCMD execute cmd!!"<<endl;

   mail newMail;

    if(mParams.size() == 3){

        newMail.setFrom(mParams[1].toStdString());
        newMail.setTo(mParams[2].toStdString());

    }



=======
void MailCMD::execute(Ui::MainWindow *window){
   window->terminalScreen->insertPlainText("MailCMD execute cmd!!\n");
>>>>>>> master
}

MailCMD::~MailCMD(){
}
