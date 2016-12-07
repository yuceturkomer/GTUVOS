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
        printTerm(window,"Invalid command");
        printTerm(window,"Usage: man [command]");
        DisplayManual(window,path);
    }else if(mParams.size()==2){
        printTerm(window,"Command: "+mParams[1]);
        DisplayManual(window,mParams[1].toStdString().c_str());
    }
}

void manCMD::DisplayManual(Ui::MainWindow* window,const char* command){
//will be implement

    QString piece = mParams[1];

    if(piece.compare("ls")==0){

        //printTerm(window,"LS good ");

    }else if(piece.compare("ls")==0){

        //will implement

    } else if(piece.compare("ls")==0){



    }else if(piece.compare("ls")==0){



    }


}
