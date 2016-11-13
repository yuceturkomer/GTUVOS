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
       ICommand::printTerm(window,"Please type a mail operation send/list","red");
       return;
   }

   if(mParams[1].compare("send")==0){
       if(mParams.size() <5){
           ICommand::printTerm(window,"Mail send invalid parameters","red");
           return;
       }

//       QString log="";
//       log.append("\tTO: ").append(mParams[2]).append("\n");
//       log.append("\tTITTLE: ").append(mParams[3]).append("\n");
//       log.append("\tMAIL: ").append(mParams[4]).append("\n");
//       cout<<"MailSent log:"<<log<<endl;

       Mail newMail;

       newMail.setTo(mParams[2].toStdString());
       newMail.setSubject(mParams[3].toStdString());
       newMail.setBody(mParams[4].toStdString());

       GTUVOS::getInstance()->getMailServer().sendMail(newMail);

       QString msg="Mail has been sent to: ";
       msg.append(QString::fromStdString(newMail.getTo()));
       ICommand::printTerm(window,msg,"green");

   }else if(mParams[1].compare("list")==0){
       vector<Mail> mails = GTUVOS::getInstance()->getMailServer().getAllMails();

       if(mails.size()==0){
           ICommand::printTerm(window,"There is no mail!\nTo send a mail, use mail send command.","blue");
       }

       for(unsigned int i=0;i!=mails.size();++i){
           QString mail="";
           mail.append(QString::number(i)).append(". Mail:<br>");
           mail.append("TO: ").append(QString::fromStdString(mails[i].getTo())).append("<br>");
           mail.append("TITLE: ").append(QString::fromStdString(mails[i].getSubject())).append("<br>");
           mail.append("MESSAGE: ").append(QString::fromStdString(mails[i].getBody())).append("<br>");
           ICommand::printTerm(window,mail);
       }
   }else{
       ICommand::printTerm(window,"Invalid mail action. Please use help manual","red");
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
