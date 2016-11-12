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
    printTerm(mainWindow,"--- Help Manual ---","blue");

    printTerm(mainWindow,"The available commands are:<br>"
                                                "help<br>"
                                                "cp <file_1> <file_2><br>"
                                                "mail list<br>"
                                                "mail send to title subject<br>"
                                                "ls path?");


}
