#ifndef TOUCHCMD_H
#define TOUCHCMD_H

#include <command.h>
#include <QFile>

class TouchCMD : public ICommand
{
public:
    TouchCMD(QStringList params);
    ~TouchCMD();
    void execute(Ui::MainWindow *window);
private:

};

#endif // TOUCHCMD_H
