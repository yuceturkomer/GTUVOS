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
     * "MailServer" directory is in the our source directory which is called "GTUVOSROOT"
     * if the "MailServer" directory doesn't exist then create it.
     *
     */
    string checkMailServerDirectory();

    /**
     * Check the mailArchive file
     *
     * -Set mailArchiveFileName
     * -Check the mailArchive file..
     * mailArchive file is in the "MailServer" directory.
     * if the mailArchive file doesn't exist then create it.
     */
    string checkMailArchiveFile(string path);

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

    const string getMailServerPath() const{
        return MAILSERVERPATH;
    }

    void addDraft(mail newMail){ draftMail.push_back(newMail);};
    const string getMailFileName() const{
        return MAILFILENAME;
    }



private slots:
    /**
     * push the sendMail button
     */
    void on_pushButton_clicked();

private:
    /**
     * Mail Archive File Name
     */
    string sentMailFile;
    string recievedMailFile;

    const string MAILSERVERPATH = ".MailServer"; // hidden directory
    const string MAILFILENAME = ".mails.txt";

    vector<Mail> sentMail;
    vector<Mail> recievedMail;
    vector<Mail> draftMail;
};

#endif // MAILSERVER_H
