#ifndef LSCMD
#define LSCMD

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

class ListCMD : public ICommand
{
public:
    ~ListCMD();
    ListCMD(QStringList params);
    void traversepath(Ui::MainWindow* window,const char* path);
    void execute(Ui::MainWindow *mainWindow);

};
#endif // LSCMD
