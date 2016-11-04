#ifndef MAILCMD_H
#define MAILCMD_H
#include <QApplication>
#include "command.h"

class MailCMD : public ICommand
{
public:
    MailCMD(QStringList str);
    ~MailCMD();
    void execute();
};

#endif // MAILCMD_H
