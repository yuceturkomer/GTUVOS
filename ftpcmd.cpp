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
void ftpcmd::execute(Ui::MainWindow *window){
    cout<<"ftp's execute started! parameter size ->"<<mParams.size()<<endl;

    cout<<"ftp test\n";
    netobj->SiteOperations("ftp://hmenn:hm2@159.203.133.30/vos/file.txt","hmenn","hm1");
    //netobj->SiteOperations("ftp://localhost/home/hasan/test.txt","hmenn","hm1");
    /*
    if(mParams.size()==1){
        printTerm(window,"Insufficient number of parameters","red");
        return;
    }else if(mParams.size()==2){
        netobj->SiteOperations(mParams[1]);
    }else if(mParams.size()==3){
        netobj->SiteOperations(mParams[1],mParams[2]);
    }else if(mParams.size()==4){
        netobj->SiteOperations(mParams[1],mParams[2],mParams[3]);
    }else if(mParams.size()==5){
        netobj->SiteOperations(mParams[1],mParams[2],mParams[4],mParams[5].toInt());
    }
*/
}
ftpcmd::~ftpcmd()
{
    delete netobj;
}