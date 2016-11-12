#include "exitcmd.h"
#include "command.h"
#include "QApplication"
#include "gtuvos.h"
#include <QTimer>


#include <iostream>
using namespace  std;


ExitCMD::~ExitCMD(){
}

ExitCMD::ExitCMD(QStringList params):ICommand(params)
{
    cout<<"ExitCmd constructed!!"<<endl;
}

void ExitCMD::execute(Ui::MainWindow *mainWindow){
    printTerm(mainWindow,"GOOD BYE","red");
    //TODO: timer kullanarak ekranda mesaj belli bir sure gonrunsun
    // daha sonra kapansın program
    QApplication::quit();
}
