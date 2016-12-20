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
using namespace rapidxml;

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

    vector<Mail> mails;

    status=readMailFile("./sendMail.xml", mails);

    if(mails.size()==0){
        ICommand::printTerm(window,"There is no mail!\nTo send a mail, use mail send command.","DeepSkyBlue");
    }

    if(status == false && mails.size() == 0){
        ICommand::printTerm(window,"No mail in archive!\n Send a mail first");
    }else{
        for(int i=0;i!=mails.size();++i){
            QString mail="";
            mail.append(QString::number(i)).append(". Mail:<br>");
            mail.append("FROM: ").append(QString::fromStdString(mails[i].getFrom())).append("<br>");
            mail.append("TO: ").append(QString::fromStdString(mails[i].getTo())).append("<br>");
            mail.append("TITLE: ").append(QString::fromStdString(mails[i].getSubject())).append("<br>");
            mail.append("MESSAGE: ").append(QString::fromStdString(mails[i].getBody())).append("<br>");

            ICommand::printTerm(window,mail);
        }
    }
   }else{
       ICommand::printTerm(window,"Invalid mail action. Please use help manual","red");
   }
}

bool MailCMD::readMailFile(string fileName,vector<Mail>& mailList){
    qDebug("readMailFile debug");

    xml_document<> doc;
    xml_node<> * root_node;

    // Read the xml file into a vector
    ifstream theFile(fileName);
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');

    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);
    // Find our root node
    root_node = doc.first_node("GTUVOSMAIL");
    if(theFile.is_open()){
        for(xml_node<> * mail_node = root_node->first_node("email"); mail_node; mail_node = mail_node->next_sibling()){
            Mail mail;

            mail.setFrom(mail_node->first_node("from")->value());

            mail.setTo(mail_node->first_node("to")->value());

            mail.setSubject(mail_node->first_node("subject")->value());
            mail.setBody(mail_node->first_node("body")->value());

            mailList.push_back(mail);
            std::cerr<<mail;
        }
        return true;
   }else return false;
/*
        // Find our root node
        root_node = doc.first_node("MyBeerJournal");
        // Iterate over the brewerys
        for (xml_node<> * brewery_node = root_node->first_node("Brewery"); brewery_node; brewery_node = brewery_node->next_sibling())
        {
            printf("I have visited %s in %s. ",
                brewery_node->first_attribute("name")->value(),
                brewery_node->first_attribute("location")->value());
                // Interate over the beers
            for(xml_node<> * beer_node = brewery_node->first_node("Beer"); beer_node; beer_node = beer_node->next_sibling())
            {
                printf("On %s, I tried their %s which is a %s. ",
                    beer_node->first_attribute("dateSampled")->value(),
                    beer_node->first_attribute("name")->value(),
                    beer_node->first_attribute("description")->value());
                printf("I gave it the following review: %s", beer_node->value());
            }
            cout << endl;
        }*/
}

void MailCMD::writeToFile(vector<Mail> mailList){

    const char* fname="sendMail.xml";
    QString filename (fname);

    QFile mailArchive(filename);

    mailArchive.open(QIODevice::WriteOnly);

    QXmlStreamWriter mailFile(&mailArchive);
    mailFile.setAutoFormatting(true);
    mailFile.writeStartDocument();
    mailFile.writeStartElement("GTUVOSMAIL");
    for(int i=0;i<mailList.size();i++){
        mailFile.writeStartElement("email");
        mailFile.writeTextElement("from",QString::fromStdString(mailList[i].getFrom()));
        mailFile.writeTextElement("to",QString::fromStdString(mailList[i].getTo()));
        mailFile.writeTextElement("subject",QString::fromStdString(mailList[i].getSubject()));
        mailFile.writeTextElement("body",QString::fromStdString(mailList[i].getBody()));
        mailFile.writeEndElement();
    }

    mailArchive.close();

}


MailCMD::~MailCMD(){
}
