#ifndef GTUVOS_H
#define GTUVOS_H

#include <vector>
#include <string>
#include <QApplication>
#include "mailserver.h"

using std::vector;
using std::string;

class GTUVOS{

public:

    // singleton system design
    static GTUVOS* getInstance(){
        if(instance == NULL)
            instance = new GTUVOS();

        return instance;
    }

    bool executeCMD(QString cmd); // execute command and return result

    double getVersion() const; // get system version number
    string getName() const; // get system name

    /*
     * Check the our source directory
     *
     * -Check the our source directory which is called "SourceFileGtuOS".
     * if the "SourceFileGtuOS" directory doesn't exist then create it.
     */
    void checkSourceFileDirectory();

    /*
     * Get MailBox Object and run it.
     */
    MailServer getMailBox();


    /*EXTRA COMMANDS*/

    /*
     * It works like LINUX 'ls' command
     */
    void ls();

    /*
     * It works like LINUX 'mkdir' command
     */
    void mkdir();

    /*
     * It works like LINUX 'mkdir' command
     */
    void cd();

private:
    //MailServer object.To open the new window.
    MailServer mailServerUi;

    void prepareSystem();
    GTUVOS(); // singleton design
    string name;
    double version;
    static GTUVOS *instance;

    /*
     * This function parses the str, then calls the appropriate function
     *
     * -parse the newString
     * -return tokens vector, if str doesnt has meaningful tokens
     * return vector wich include error message
     *
     * Available commands:
     *      -copyFile
     *      -getMailBox
     *      -shutdownOS
     *      -helpOSForCommands
     *
     * @param newString will parsed
     */
    //QStringList parseStr(QString str);

};


#endif // GTUVOS_H
