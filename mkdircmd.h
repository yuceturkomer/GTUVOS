#ifndef MKDIRCMD_H
#define MKDIRCMD_H

#include <command.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "dirent.h"
#include <QDir>

class MkdirCMD : public ICommand
{
public:
    MkdirCMD(QStringList params);
    ~MkdirCMD();
    void execute(Ui::MainWindow *window);
private:

};

#endif // MKDIRCMD_H
