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
    window->terminalScreen->insertPlainText("ListCMD execute cmd\n");
    traversepath(window);
}


void ListCMD::traversepath(Ui::MainWindow* window)
{
    char directory[1024];
    getcwd(directory, sizeof(directory));
    struct dirent *direntp;
    DIR *dirp;

    if ((dirp = opendir(directory)) == NULL) { /* Dosya acilamazsa */
        perror ("Failed to open directory");
        //return -1;
    }

    /* Eger dosyanin icinde baska dosya yoksa */
    if(getNumberOfSubDirectory(directory) == 0) {
        /* Dosyanin icindekileri konsola yazdirir. */
        while ((direntp = readdir(dirp)) != NULL) {
            if(direntp->d_type == DT_REG)
                if(strcmp(direntp->d_name , ".." )!=0){
                    window->terminalScreen->insertPlainText(direntp->d_name);
                    window->terminalScreen->insertPlainText("\n");
                }

        }
    }

    /* Dosya kapatilir. */
    while ((closedir(dirp) == -1) && (errno == EINTR)) ;
}

int ListCMD::getNumberOfSubDirectory(char *directory)
{
    DIR * currentDirectory = NULL;
    struct dirent *myDirectory = NULL;

    int numOfSubDirectory=0;

    currentDirectory = opendir(directory); /* Dosya acilir. */

    while((myDirectory = readdir(currentDirectory)) != NULL)
    {
       if(myDirectory->d_type == DT_DIR && strcmp(myDirectory->d_name , ".") &&
          strcmp( myDirectory->d_name , ".." ) )
            numOfSubDirectory++;
    }

    closedir(currentDirectory); /* Dosya kapatilir. */

    return numOfSubDirectory;
}
