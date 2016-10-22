#ifndef MAILSERVER_H
#define MAILSERVER_H

namespace GTUVOS {

class MailServer{

    public:
public:
    /**
    * Default Constructors
    *
    * -Check MailBox Directory
    * -Check the mailArchive file
    */
    MailBox();

    /**
    * Virtual Constructors
    */
    virtual ~MailBox();

    /**
    * Run MailBox
    *
    * -Set "widget" variable
    * -Set "isItClosed" variable true
    * -Call the readInput function for read input from the terminal
    */
    void runMailBox();

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
     *      -shutdownMailBox
     *      -helpMailBoxForCommands
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
     * Check the mailbox directory
     *
     * -Check the mailbox directory which is called "MailBox".
     * "MailBox" directory is in the our source directory which is called "SourceFileGtuOS"
     * if the "MailBox" directory doesn't exist then create it.
     *
     */
    void checkMailBoxDirectory();

    /**
     * Check the mailArchive file
     *
     * -Set mailArchiveFileName
     * -Check the mailArchive file..
     * mailArchive file is in the "MailBox" directory.
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
     * Shutdown MailBox
     *
     * -Set "isItClosed" variable false
     * -Handle other stuff
     */
    void shutdownMailBox();

    /**
     * Print All available commands On The Screen
     *
     * -Use "writeGivenStringOnTheScreen" function for print
     */
    void helpMailBoxForCommands();

    /**
     * Get widget
     */
    Ui::MailBox getWidget() const{return widget;}

    /**
     * Set widget
     */
    void setWidget() {widget.setupUi(this);}

    /**
     * Get isItClosed
     */
    bool getIsItClosed() const{return isItClosed;}

    /**
     * Set isItClosed
     */
    void setIsItClosed(bool newBoolValue) {isItClosed = newBoolValue ;}

    /**
     * Get mailArchiveFileName
     */
    string getMailArchiveFileName() const{return mailArchiveFileName;}

    /**
     * Set mailArchiveFileName
     */
    void setMailArchiveFileName(string newMailArchiveFileName) {mailArchiveFileName = newMailArchiveFileName ;}


private:
    /**
     * Widget
     */
    Ui::MailBox widget;

    /**
    * -if this variable is true, MailBox continues to run
    * -if this variable is false, MailBox doesn't continues to run
    */
    bool isItClosed;

    /**
     * Mail Archive File Name
     */
    string mailArchiveFileName;

}
}


#endif // MAILSERVER_H
