#ifndef EXITCMD_H
#define EXITCMD_H
#include <QApplication>
#include "command.h"
#include <string>
#include "gtuvos.h"

class ExitCMD : public ICommand
{
public:
    ~ExitCMD();
    ExitCMD(QStringList params);
    void execute(Ui::MainWindow *window);
};

#endif // EXITCMD_H
