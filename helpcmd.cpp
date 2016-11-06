#include "helpcmd.h"
#include "command.h"
#include "QApplication"
#include "gtuvos.h"

#include <iostream>
using namespace  std;


HelpCMD::~HelpCMD(){
}

HelpCMD::HelpCMD(QStringList params):ICommand(params)
{
    cout<<"HelpCmd constructed!!"<<endl;
}

void HelpCMD::execute(Ui::MainWindow *mainWindow){
    // Information for running the command
    mainWindow->terminalScreen->insertPlainText("HelpCMD execute cmd\n\n");

    mainWindow->terminalScreen->insertPlainText("The available commands are:\n"
                                                "help\n"
                                                "cp <file_1> <file_2>\n"
                                                "mail list\n"
                                                "mail send to title subject\n"
                                                "ls");


}
