#include "mailserver.h"
#include "ui_mailserver.h"
#include "qmessagebox.h"

/**
* Default Constructors
*
* -Check MailServer Directory
* -Check the mailArchive file
*/
MailServer::MailServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MailServer)
{
    ui->setupUi(this);
    checkMailServerDirectory(); // Check MailServer Directory
    checkMailArchiveFile(); // Check MailArchiveFile
}

/**
* Virtual Constructors
*/
MailServer::~MailServer()
{
    delete ui;
}

/**
* Run MailServer
*
* -Call the readInput function for read input from the terminal
*/
void MailServer::runMailServer(){
    readInput();
}

/**
 * This function is read input from the terminal
 *
 * -Read input from the terminal
 * -Call the parseString function
 * -If "isItClosed" variable true then wait the next input.
 * -if "isItClosed" variable false then interrupt loop
 */
void MailServer::readInput(){

    /**
     * You must implement this function
     * You need some Qt skills.
     */
}

/**
 * This function parses the newString, then calls the appropriate function
 *
 * -parse the newString
 * -if newString is meaningful then call the appropriate command
 * -if newString is not meaningful then call the function
 * "writeGivenStringOnTheScreen" and give the error message.
 *
 * Available commands:
 *      -readMail
 *      -sendMail
 *      -shutdownMailServer
 *      -helpMailServerForCommands
 *
 * @param newString will parsed
 */
void MailServer::parseString(string newString){

    /**
     * You must implement this function
     */

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
void MailServer::sendMail(){

    /**
     * You must implement this function
     */

}

/**
 * Check the MailServer directory
 *
 * -Check the MailServer directory which is called "MailServer".
 * "MailServer" directory is in the our source directory which is called "SourceFileGtuOS"
 * if the "MailServer" directory doesn't exist then create it.
 *
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

    setMailArchiveFileName("mailArchive.txt");

    /**
     * You must implement this function
     */

}

/**
 * Print Given String On The Screen
 *
 * @param newString will written
 */
void MailServer::writeGivenStringOnTheScreen(string newString){

    /**
     * You must implement this function
     * You need some Qt skills.
     */

}

/**
 * Shutdown MailServer
 *
 * -Set "isItClosed" variable false
 * -Handle other stuff
 */
void MailServer::shutdownMailServer(){
   /**
     * You must implement this function
     */

}

/**
 * Print All available commands On The Screen
 *
 * -Use "writeGivenStringOnTheScreen" function for print
 */
void MailServer::helpMailServerForCommands(){

    /**
     * You must implement this function
     */


}

void MailServer::on_pushButton_clicked()
{
    QString from=ui->from->text();
    QString to=ui->to->text();
    QString subject=ui->subject->text();
    QString composeMail=ui->composeMail->toPlainText();


    //For the Test.
    QMessageBox::information(this,"From",from);
    QMessageBox::information(this,"To",to);
    QMessageBox::information(this,"Subject",subject);
    QMessageBox::information(this,"Compose email",composeMail);


    //islem bitince ekrani kapatma.Suanlik kapali kalsin.
    //MailServer::close();
}
