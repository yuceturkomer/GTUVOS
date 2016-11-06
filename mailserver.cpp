#include "mailserver.h"
#include "ui_mailserver.h"
#include "qmessagebox.h"


/**
* Default Constructors
*
* -Check MailServer Directory
* -Check the mailArchive file
*/
MailServer::MailServer()
{}

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
 * "MailServer" directory is in the our source directory which is called "SourceFileGtuOS"
 * if the "MailServer" directory doesn't exist then create it.
 */
void MailServer::checkMailServerDirectory(){
    /**
     * You must implement this function
     */
}

/**
 * Check the mailArchive file
 *
 * -Set mailArchiveFileName
 * -Check the mailArchive file..
 * mailArchive file is in the "MailServer" directory.
 * if the mailArchive file doesn't exist then create it.
 */
void MailServer::checkMailArchiveFile(){

    //setMailArchiveFileName("mailArchive.txt");

    /**
     * You must implement this function
     */

}

vector<Mail> MailServer::getAllMails() const{
    return sentMail;
}
