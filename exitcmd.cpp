#include "exitcmd.h"
#include "command.h"
#include "QApplication"
#include "gtuvos.h"


#include <iostream>
using namespace  std;


ExitCMD::~ExitCMD(){
}

ExitCMD::ExitCMD(QStringList params):ICommand(params)
{
    cout<<"ExitCmd constructed!!"<<endl;
}

void ExitCMD::execute(Ui::MainWindow *mainWindow){
    cout<<"ExitCmd constructed!!"<<endl;
}
