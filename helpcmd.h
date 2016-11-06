#ifndef HELPCMD_H
#define HELPCMD_H
#include <QApplication>
#include "command.h"
#include <string>
#include "gtuvos.h"

class HelpCMD : public ICommand
{
public:
    ~HelpCMD();
    HelpCMD(QStringList params);
    void execute(Ui::MainWindow *window);
};

#endif // HELPCMD_H
