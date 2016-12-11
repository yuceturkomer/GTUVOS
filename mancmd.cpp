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

ManCMD::~ManCMD(){
}

ManCMD::ManCMD(QStringList params):ICommand(params)
{
    cout<<"Man command consturcted"<<endl;
}
void ManCMD::execute(Ui::MainWindow* window){
    if(mParams.size()==1){
        char path[255];
        getcwd(path,255);
        printTerm(window,"Invalid command");
        printTerm(window,"Usage: man [command]");
    }else if(mParams.size()==2){
        printTerm(window,"Manual: "+mParams[1]);
        DisplayManual(window);
    }else throw INSUFFICIENT_PARAMS_EXCEPTION();
}

void ManCMD::DisplayManual(Ui::MainWindow* window){
//will be implement

    QString piece = mParams[1];

    if(piece.compare("ls")==0){
        printTerm(window,"- list directory contents","green");
    }else if(piece.compare("mkdir")==0){
        printTerm(window,"- make directories","green");
    }else if(piece.compare("man")==0){
        printTerm(window,"- an interface to the on-line reference manuals","green");
    }


}
