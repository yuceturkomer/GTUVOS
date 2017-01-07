#ifndef FTPCMD_H
#define FTPCMD_H
#include <QApplication>
#include "command.h"
#include <string>
#include "gtuvos.h"
#include "net.h"

class ftpcmd : public ICommand
{
public:
    ~ftpcmd();
    ftpcmd(QStringList params);
    void execute(Ui::MainWindow *window);
    Net *netobj;

};
#endif // FTPCMD_H
