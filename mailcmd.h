#ifndef MAILCMD_H
#define MAILCMD_H
#include <QApplication>
#include "gtuvos.h"
#include "command.h"

class MailCMD : public ICommand
{
public:
    MailCMD(QStringList str);
    ~MailCMD();
    void execute(Ui::MainWindow *window);
};

#endif // MAILCMD_H
