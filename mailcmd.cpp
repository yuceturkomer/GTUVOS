#include "mailcmd.h"
#include "mailserver.h"
#include <iostream>
#include <QApplication>
#include "gtuvos.h"
#include "mail.h"

using namespace std;

MailCMD::MailCMD(QStringList params):ICommand(params)
{
    cout<<"MailCMD constructed!"<<endl;
}


void MailCMD::execute(Ui::MainWindow *window){

   if(mParams.size()<2){
       window->terminalScreen->insertPlainText("Please and an mail operation send/list");
       return;
   }

   if(mParams[1].compare("send")==0){
       if(mParams.size() <5){
           window->terminalScreen->insertPlainText("Mail send invalid parameters");
           return;
       }
       QString log="MAIL->\n";
       log.append("\tTO: ").append(mParams[2]).append("\n");
       log.append("\tTITTLE: ").append(mParams[3]).append("\n");
       log.append("\tMAIL: ").append(mParams[4]).append("\n");

       window->terminalScreen->insertPlainText(log);

       Mail newMail;

       newMail.setTo(mParams[1].toStdString());
       newMail.setSubject(mParams[2].toStdString());
       newMail.setBody(mParams[3].toStdString());

       GTUVOS::getInstance()->getMailServer().sendMail(newMail);
   }else if(mParams[1].compare("list")==0){
       vector<Mail> mails = GTUVOS::getInstance()->getMailServer().getAllMails();

       if(mails.size()==0){
           window->terminalScreen->insertPlainText("There is no mail!\nTo sent mail use mail send command");
       }

       for(unsigned int i=0;i!=mails.size();++i){
           QString mail="";
           mail.append(QString::number(i)).append(". Mail->\n");
           mail.append("TO: ").append(QString::fromStdString(mails[i].getTo())).append("\n");
           mail.append("TITLE: ").append(QString::fromStdString(mails[i].getSubject())).append("\n");
           mail.append("MESSAGE: ").append(QString::fromStdString(mails[i].getBody())).append("\n");
           window->terminalScreen->insertPlainText(mail);
       }
   }else{
       window->terminalScreen->insertPlainText("Invalid mail action. Please use help manual");
   }
/*
   ofstream sendMailFileArchive;
   sendMailFileArchive.open("sendMail.xml",std::ios_base::app);

   sendMailFileArchive<<"<email>"<<endl<<"\t"
              <<"<from>"<<newMail.getFrom()<<"</from>"<<endl<<"\t"
              <<"<to>"<<newMail.getTo()<<"</to>"<<endl<<"\t"
              <<"<cc>"<<newMail.getCC()<<"</cc>"<<endl<<"\t"
             <<"<bcc>"<<newMail.getBCC()<<"</bcc>"<<endl<<"\t"
             <<"<subject>"<<newMail.getSubject()<<"</subject>"<<endl<<"\t"
             <<"<body>"<<newMail.getBody()<<"</body>"<<endl
            <<"</email>"<<endl<<endl<<endl;
*/

}

MailCMD::~MailCMD(){
}
