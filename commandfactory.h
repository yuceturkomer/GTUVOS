#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "command.h"

class CommandFactory
{
public:
    ICommand* getCommand(QString str);
    QStringList parseStr(QString str);

    static CommandFactory* getInstance(){
        if(instance == NULL)
            instance = new CommandFactory();
        return instance;
    }

private:
    CommandFactory();
    static CommandFactory *instance;

};

#endif // COMMANDFACTORY_H
