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

    ~GTUVOS();

    // singleton system design
    static GTUVOS* getInstance(){
        if(instance == NULL)
            instance = new GTUVOS();

        return instance;
    }

    bool executeCMD(QString cmd); // execute command and return result

    double getVersion() const; // get system version number

    string getName() const; // get system name

    string getRootPath() const; // get os root file directory path

    MailServer* getMailServer();

    Ui::MainWindow *window;

private:
    /*
     * This method prepares OS before system run.
     * Checks root directory files
     * Existing sources and makes some stuff
     */
    void prepareSystem();

    GTUVOS(); // singleton private constructor

    string name; // name of os
    double version; // version of os
    string ROOTFileName = ".GTUVOSROOT";

    MailServer* mailServer;

    static GTUVOS *instance; //singleton gtu vos instance

    /*
     * Check the our root directory
     *
     * -Check the root source directory which is called "GTUVOSROOT".
     * if the "GTUVOSROOT" directory doesn't exist then create it.
     */
    void checkRootFile();

};


#endif // GTUVOS_H
