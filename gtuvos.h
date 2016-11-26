#ifndef GTUVOS_H
#define GTUVOS_H

#include <vector>
#include <string>
#include <QApplication>
#include "mainwindow.h"
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

    MailServer& getMailServer();

    /*
     * Check the our source directory
     *
     * -Check the our source directory which is called "SourceFileGtuOS".
     * if the "SourceFileGtuOS" directory doesn't exist then create it.
     */
    void checkSourceFileDirectory();

    Ui::MainWindow *window;

private:
    //MailServer object.To open the new window.
    void prepareSystem();
    GTUVOS(); // singleton design
    string name;
    double version;
    static GTUVOS *instance;
    MailServer mailServer;

};


#endif // GTUVOS_H
