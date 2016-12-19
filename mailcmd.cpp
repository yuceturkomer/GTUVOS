#include "mailcmd.h"
#include "mailserver.h"
#include <iostream>
#include <string>
#include <fstream>
#include <QApplication>
#include "gtuvos.h"
#include "mail.h"
#include <precompiledxml.h>

using namespace std;

MailCMD::MailCMD(QStringList params):ICommand(params)
{
    cout<<"MailCMD constructed!"<<endl;

}


void MailCMD::execute(Ui::MainWindow *window){

    Mail newMail;

   if(mParams.size()<2){
       ICommand::printTerm(window,"Please type a mail operation send/list","red");
       return;
   }

   if(mParams[1].compare("send")==0){
       if(mParams.size() <5){
           ICommand::printTerm(window,"Mail Send Error: Invalid Parameters","red");
           return;
       }

       newMail.setFrom("admin@gtuvos.edu.tr");
       newMail.setTo(mParams[2].toStdString());
       newMail.setSubject(mParams[3].toStdString());
       newMail.setBody(mParams[4].toStdString());
       newMail.setCC("No CC");

       GTUVOS::getInstance()->getMailServer()->sendMail(newMail);

      writeToFile(GTUVOS::getInstance()->getMailServer()->getAllMails());


       QString msg="Mail has been sent to: ";
       msg.append(QString::fromStdString(newMail.getTo()));
       ICommand::printTerm(window,msg,"LawnGreen");



   }else if(mParams[1].compare("list")==0){
    bool status;

    vector<Mail> mailto = GTUVOS::getInstance()->getMailServer()->getAllMails();
    vector<Mail> deneme;

    status=readMailFile("~/build-GTUVOS-Desktop_Qt_5_5_1_GCC_64bit3-Debug/sendMail.xml", deneme);



       if(mailto.size()==0){
           ICommand::printTerm(window,"There is no mail!\nTo send a mail, use mail send command.","DeepSkyBlue");
       }


        if(status == false && mailto.size() == 0){
            ICommand::printTerm(window,"No mail in archive!\n Send a mail first");

        }else{

                for(unsigned int i=0;i!=deneme.size();++i){
                    QString mail="";
                    mail.append(QString::number(i)).append(". Mail:<br>");
                    mail.append("TO: ").append(QString::fromStdString(mailto[i].getTo())).append("<br>");
                    mail.append("TITLE: ").append(QString::fromStdString(mailto[i].getSubject())).append("<br>");
                    mail.append("MESSAGE: ").append(QString::fromStdString(mailto[i].getBody())).append("<br>");
                    ICommand::printTerm(window,mail);
            }
        }

   }else{
       ICommand::printTerm(window,"Invalid mail action. Please use help manual","red");
   }

}

bool MailCMD::readMailFile(string fileName,vector<Mail>& mailList){

    xml_document<> doc;
    xml_node<> * root_node;
    // Read the xml file into a vector
    ifstream theFile(fileName);
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);
    // Find our root node
    root_node = doc.first_node("sentMail");

    if(theFile.is_open()){

for (xml_node<> * mail_node = root_node->first_node("email"); mail_node; mail_node = mail_node->next_sibling())
    {
        Mail tempMail;
        xml_node<> * from_node = mail_node->first_node("from");
        xml_node<> * to_node = mail_node->first_node("to");
       // xml_node<> * cc_node = mail_node->first_node("cc");
       //xml_node<> * bcc_node = mail_node->first_node("bcc");
        xml_node<> * subject_node = mail_node->first_node("subject");
        xml_node<> * body_node = mail_node->first_node("body");
        //for(xml_node<> * from_node = mail_node->first_node("from"); from_node; from_node = from_node->next_sibling())
        //{
            tempMail.setFrom(from_node->value());
        //}
        //for(xml_node<> * to_node = mail_node->first_node("to"); to_node; to_node = to_node->next_sibling())
        //{
            tempMail.setTo(to_node->value());
        //}
        //for(xml_node<> * cc_node = mail_node->first_node("cc"); cc_node; cc_node = cc_node->next_sibling())
        //{
        //	if(cc_node->value() !=" ")
        //	tempMail.setCC(cc_node->value());
        //}
        //for(xml_node<> * bcc_node = mail_node->first_node("bcc"); bcc_node; bcc_node = bcc_node->next_sibling())
        //{
       //  if(bcc_node->value() != " ")
        //	tempMail.setBCC(bcc_node->value());
        //for(xml_node<> * subject_node = mail_node->first_node("subject"); subject_node; subject_node = subject_node->next_sibling())
        //{
            tempMail.setSubject(subject_node->value());
       // }
        //for(xml_node<> * body_node = mail_node->first_node("body"); body_node; body_node = body_node->next_sibling())
        //{
            tempMail.setBody(body_node->value());
        //}

        mailList.push_back(tempMail);

    }

    return true;
   }else{

       return false;
    }

}

void MailCMD::writeToFile(vector<Mail> mailList){

 const char* fname="sendMail.xml";
 QString filename (fname);

 QFile mailArchive(filename);

  mailArchive.open(QIODevice::WriteOnly);

  QXmlStreamWriter mailFile(&mailArchive);

    mailFile.setAutoFormatting(true);
    mailFile.writeStartDocument();
    mailFile.writeStartElement("sentMail");
        for(int i=0;i<mailList.size();i++){
            mailFile.writeStartElement("email");
            mailFile.writeTextElement("from",QString::fromStdString(mailList[i].getFrom()));
            mailFile.writeTextElement("to",QString::fromStdString(mailList[i].getTo()));
            mailFile.writeTextElement("body",QString::fromStdString(mailList[i].getBody()));
            mailFile.writeEndElement();
        }

        mailArchive.close();

//  mailArchive<<"<?xml version=\"1.0\"? encoding=\"utf-8\"?>\n<sentMail>\n";

//           for(int i=0;i< mailList.size();i++){
//               mailArchive<<"<email>"<<endl<<"\t"
//                         <<"<from>"<<mailList[i].getFrom()<<"</from>"<<endl<<"\t"
//                         <<"<to>"<<mailList.at(i).getTo()<<"</to>"<<endl<<"\t"

//                        <<"<subject>"<<mailList.at(i).getSubject()<<"</subject>"<<endl<<"\t"
//                        <<"<body>"<<mailList.at(i).getBody()<<"</body>"<<endl
//                       <<"</email>"<<endl;
//           }

//    mailArchive<<"</sentMail>\n";
//    mailArchive.close();
}


MailCMD::~MailCMD(){
}
