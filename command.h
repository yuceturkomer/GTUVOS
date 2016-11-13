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
    static inline void printTerm(Ui::MainWindow* window,QString str,QString color="black"){
            QString text = "";
            text.append("<span style=\"color:").append(color).append(";\">").append(str).append("</span><br>");
            window->terminalScreen->insertHtml(text);
    }
    QStringList mParams;
private:

};

#endif // ICommand_H
