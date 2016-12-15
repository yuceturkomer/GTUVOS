/**
 * Virtual Operating System Clear Command
 *
 * File:   clearcmd.h
 *
 * @author CSE_343_Software Engineering_Group_2
 * @since Thursday 15 December 2016
 */

#ifndef CLEARCMD_H
#define CLEARCMD_H

#include <QApplication>
#include "command.h"

class ClearCMD :public ICommand
{
public:
    ~ClearCMD();
    ClearCMD(QStringList params);
    void execute(Ui::MainWindow *mainWindow);
private:

};

#endif // CLEARCMD_H
