#include <iostream>
#include <QDir>
#include "mailserver.h"
#include "ui_mailserver.h"
#include "gtuvos.h"
#include "qmessagebox.h"


/**
* Default Constructors
*
* -Check MailServer Directory
* -Check the mailArchive file
*/
MailServer::MailServer()
{
    checkMailArchiveFile(MAILFILENAME);
    cout<<"Mail Server constucted"<<endl;
}

/**
* Virtual Constructors
*/
MailServer::~MailServer()
{
}


/**
 * Print all mail Archive
 *
 * -Read mailArchive file. Call the function
 * "writeGivenStringOnTheScreen" and print the all mail Archive.
 */
void MailServer::readMail(){

    /**
     * You must implement this function
     */

}

/**
 * Send Mail
 *
 * -Write mail into mailArchive file
 */
void MailServer::sendMail(Mail mail){
    sentMail.push_back(mail);
}

/**
 * Check the mailArchive file
 *
 * -Set mailArchiveFileName
 * -Check the mailArchive file..
 * @param path : mail server directory path
 * @return mail server archive file path
 * mailArchive file is in the "MailServer" directory.
 * if the mailArchive file doesn't exist then create it.
 */
string MailServer::checkMailArchiveFile(string path){

    QFile mailFile(QString::fromStdString(path));
    if(mailFile.exists()){
        cout<<"Mail file exist."<<endl;
    }else{
        mailFile.open(QIODevice::ReadWrite);
        cout<<"Mail file created!"<<endl;
    }

    return path;
}

vector<Mail> MailServer::getAllMails() const{
    return sentMail;
}
