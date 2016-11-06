#ifndef MAILSERVER_H
#define MAILSERVER_H
#include <string>
#include <vector>
#include "mail.h"

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;


class MailServer
{

public:
    MailServer();
    ~MailServer();
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
    void sendMail(Mail mail);

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
     * Print All available commands On The Screen
     *
     * -Use "writeGivenStringOnTheScreen" function for print
     */
    void helpMailServerForCommands();

    vector<Mail> getAllMails() const;


    /**
     * Get mailArchiveFileName
     */
    string getSentMailArchiveFileName() const{return sentMailFile;}
    string getRecievedMailArchiveFileName() const{return recievedMailFile;}


private:
    /**
     * Mail Archive File Name
     */
    string sentMailFile;
    string recievedMailFile;

    vector<Mail> sentMail;
    vector<Mail> recievedMail;
    vector<Mail> draftMail;
};

#endif // MAILSERVER_H
