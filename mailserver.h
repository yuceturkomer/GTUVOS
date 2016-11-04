#ifndef MAILSERVER_H
#define MAILSERVER_H
#include <QWidget>
#include <QPushButton>
#include <string>
#include <vector>
#include "mail.h"
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;


namespace Ui {
class MailServer;
}

class MailServer : public QWidget
{
    Q_OBJECT

public:
    explicit MailServer(QWidget *parent = 0);
    ~MailServer();

   Ui::MailServer* getUI(){
   return ui;}

    /**
    * Run MailServer
    *
    * -Set "widget" variable
    * -Set "isItClosed" variable true
    * -Call the readInput function for read input from the terminal
    */
    void runMailServer();

    /**
     * This function is read input from the terminal
     *
     * -Read input from the terminal
     * -Call the parseString function
     * -If "isItClosed" variable true then wait the next input.
     * -if "isItClosed" variable false then interrupt loop
     */
    void readInput();

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
    void parseString(string newString);

    /**
     * Print all mail Archive
     *
     * -Read mailArchive file. Call the function
     * "writeGivenStringOnTheScreen" and print the all mail Archive.
     */
    void readMail();

    /**
     * Send Mail
     *
     * -Write mail into mailArchive file
     */
    void sendMail();

    /**
     * Check the MailServer directory
     *
     * -Check the MailServer directory which is called "MailServer".
     * "MailServer" directory is in the our source directory which is called "SourceFileGtuOS"
     * if the "MailServer" directory doesn't exist then create it.
     *
     */
    void checkMailServerDirectory();

    /**
     * Check the mailArchive file
     *
     * -Set mailArchiveFileName
     * -Check the mailArchive file..
     * mailArchive file is in the "MailServer" directory.
     * if the mailArchive file doesn't exist then create it.
     */
    void checkMailArchiveFile();

    /**
     * Print Given String On The Screen
     *
     * @param newString will written
     */
    void writeGivenStringOnTheScreen(string newString);

    /**
     * Shutdown MailServer
     *
     * -Set "isItClosed" variable false
     * -Handle other stuff
     */
    void shutdownMailServer();

    /**
     * Print All available commands On The Screen
     *
     * -Use "writeGivenStringOnTheScreen" function for print
     */
    void helpMailServerForCommands();



    /**
     * Get mailArchiveFileName
     */
    string getSentMailArchiveFileName() const{return sentMailFile;};
    string getRecievedMailArchiveFileName() const{return recievedMailFile;}






private slots:
    /**
     * push the sendMail button
     */
    void on_pushButton_clicked();

private:
    /**
     * For MailServer user interface
    */
    Ui::MailServer *ui;

    /**
     * Mail Archive File Name
     */
    string sentMailFile;
    string recievedMailFile;
//    ifstream recievedMailFileArchive;
//    ofstream sentMailFileArchive;

    vector<mail> sentMail;
    vector<mail> recievedMail;
    vector<mail> draftMail;
};

#endif // MAILSERVER_H
