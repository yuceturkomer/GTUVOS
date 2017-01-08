#include "ftpcmd.h"

/*
   ~ftpcmd();
    ftpcmd(QStringList params);
    void execute(Ui::MainWindow *window);
    Net *netobj;
*/


ftpcmd::ftpcmd(QStringList params):ICommand(params){
    netobj = new Net();
}

// ftp hmenn:hm1@159.203.133.30/vos/test.txt test.txt
void ftpcmd::execute(Ui::MainWindow *window){
    cout<<"ftp's execute started! parameter size ->"<<mParams.size()<<endl;

    //netobj->SiteOperations("ftp://hmenn:hm2@159.203.133.30/vos/file.txt");

    try{
        if(mParams.size()!=3){
            printTerm(window,"Insufficient number of parameters","red");
            return;
        }

        // ftp://username:pass@host/location
        QString url = "ftp://";
        url.append(mParams[1]);

        netobj->setURL(url);
        qDebug()<<"FTP URL:"<<netobj->getURL();
        netobj->sendFileToFTP(mParams[2]);
    }catch(exception e){
         ICommand::printTerm(window,e.what(),"red");
    }

    ICommand::printTerm("File sent success","red");
}
ftpcmd::~ftpcmd()
{
    delete netobj;
}
