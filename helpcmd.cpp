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
    mainWindow->terminalScreen->insertPlainText("The available commands are:\n"
                                                "help\n"
                                                "cp <file_1> <file_2>\n"
                                                "mail\n"
                                                "ls\n\n");


}
