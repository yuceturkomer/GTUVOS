#ifndef ICommand_H
#define ICommand_H
#include "gtuvos.h"
#include <QApplication>

class ICommand{
public :
    inline ICommand(QStringList params){
        mParams=params;
    }
    virtual void execute(Ui::MainWindow *window)=0;
    virtual ~ICommand(){}
    QStringList mParams;
private:

};




#endif // ICommand_H