#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "command.h"
#include "gtuexceptions.h"
#include "copycmd.h"
#include "mailcmd.h"
#include "helpcmd.h"
#include "gtuvos.h"
#include "exitcmd.h"
#include "lscmd.h"
#include "mkdircmd.h"
#include "touchcmd.h"

class CommandFactory
{
public:
    ICommand* getCommand(QString str);

    static CommandFactory* getInstance(){
        if(instance == NULL)
            instance = new CommandFactory();
        return instance;
    }

private:
    CommandFactory();
    static CommandFactory *instance;
    QStringList parseStr(QString str);
    QStringList parseMailCMD(QString str);
};

#endif // COMMANDFACTORY_H
