#include "mancmd.h"
#include "command.h"
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

manCMD::~manCMD(){
}

manCMD::manCMD(QStringList params):ICommand(params)
{
    cout<<"Man command consturcted"<<endl;
}
void manCMD::execute(Ui::MainWindow* window){
    if(mParams.size()==1){
        char path[255];
        getcwd(path,255);
        printTerm(window,"Path: "+QString::fromUtf8(path));
        DisplayManual(window,path);
    }else{
        printTerm(window,"Path: "+mParams[1]);
        DisplayManual(window,mParams[1].toStdString().c_str());
    }
}

void manCMD::DisplayManual(Ui::MainWindow* window,const char* path){
//will be implement


}
