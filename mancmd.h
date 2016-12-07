#ifndef MANCMD
#define MANCMD


#include <QApplication>
#include "command.h"
#include <string>

#include <iostream>
#include <sys/sendfile.h>  // sendfile
#include <fcntl.h>         // open
#include <unistd.h>        // close
#include <sys/stat.h>      // fstat
#include <sys/types.h>     // fstat
#include <dirent.h>        // DIR

using namespace  std;

class manCMD : public ICommand
{
public:
    ~manCMD();
    manCMD(QStringList params);
    void execute(Ui::MainWindow *mainWindow);
private:
    void DisplayManual(Ui::MainWindow* window,const char* path);

};





#endif // MANCMD

