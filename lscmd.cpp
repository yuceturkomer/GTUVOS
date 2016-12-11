#include "lscmd.h"
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
#include <unistd.h>
#include <sys/wait.h>
#define BUFSIZE 256
#define FIFO_MODES O_RDONLY
#define FIFO_PERM  (0666)
#include <unistd.h>

ListCMD::~ListCMD(){
}

ListCMD::ListCMD(QStringList params):ICommand(params)
{
    cout<<"Listcommand consturcted"<<endl;
}
void ListCMD::execute(Ui::MainWindow* window){
    if(mParams.size()==1){
        char path[255];
        getcwd(path,255);
        printTerm(window,"Path: "+QString::fromUtf8(path));
        traversepath(window,path);
    }else{
        printTerm(window,"Path: "+mParams[1]);
        traversepath(window,mParams[1].toStdString().c_str());
    }
}


void ListCMD::traversepath(Ui::MainWindow* window,const char* path)
{
    struct dirent *direntp;
    DIR *dirp;
    int total=0;

    if ((dirp = opendir(path)) == NULL) { /* Dosya acilamazsa */
        printTerm(window,"Failed to open directory","red");
        return;
    }

    /* Dosyanin icindekileri konsola yazdirir. */
    while ((direntp = readdir(dirp)) != NULL) {
        QString str="";
        if(strcmp(direntp->d_name , "..")!=0 && strcmp(direntp->d_name , ".")!=0){
            if(direntp->d_type==DT_DIR){
                str.append("Dir->");
                str.append(direntp->d_name).append("\n");
                printTerm(window,str,"LawnGreen");
            }else{
                str.append(direntp->d_name).append("\n");
                printTerm(window,str,"DeepSkyBlue");
            }
            ++total;
        }
    }
    QString totalNum ="Total: ";
    totalNum.append(QString::number(total));
    printTerm(window,totalNum,"red");

    /* Dosya kapatilir. */
    while ((closedir(dirp) == -1) && (errno == EINTR)) ;
}
