#ifndef FTPCMD_H
#define FTPCMD_H
#include <QApplication>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <string>
#include "gtuexceptions.h"
#include "command.h"
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
