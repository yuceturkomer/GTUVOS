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
    string path = checkMailServerDirectory();
    checkMailArchiveFile(path);
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
 * Check the MailServer directory
 *
 * -Check the MailServer directory which is called "MailServer".
 * "MailServer" directory is in the our source directory which is called "GTUVOSROOT"
 * if the "MailServer" directory doesn't exist then create it.
 * @return mail server directory path
 */
string MailServer::checkMailServerDirectory(){

    string path = ".GTUVOSROOT";
    path.append("/").append(getMailServerPath());

    QDir root(QString::fromStdString(path));
    if(root.exists()){
        cout<<"Mail Directory exist."<<endl;
    }else{
        root.mkpath(".");
        cout<<"Mail Directory created!"<<endl;
    }

    return path;
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

    string temp = path;
    path.append("/").append(getMailFileName());
    QFile mailFile(QString::fromStdString(temp));
    if(mailFile.exists()){
        cout<<"Mail file exist."<<endl;
    }else{
        mailFile.open(QIODevice::ReadWrite);
        cout<<"Mail file created!"<<endl;
    }

    return temp;
}

vector<Mail> MailServer::getAllMails() const{
    return sentMail;
}
