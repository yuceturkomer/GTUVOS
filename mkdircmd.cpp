#include "mkdircmd.h"
#include "gtuexceptions.h"

MkdirCMD::~MkdirCMD(){
}

MkdirCMD::MkdirCMD(QStringList params):ICommand(params)
{
    cout<<"Mkdir cmd constructed"<<endl;
}

void MkdirCMD::execute(Ui::MainWindow *window){
    cout<<"Mkdir execute started."<<endl;
    try{
        if(mParams.size()!=2){
            printTerm(window,"Invalid mkdir parameter","red");
            printTerm(window,"Please check help manual","LawnGreen");
            return;
        }

        QString path = mParams[1];
        cout<<"Path:"<<path.toStdString()<<endl;
        QDir dir(path);

        if(dir.exists()){
            throw DIR_EXIST_EXCEPTION();
        }else{
            dir.mkpath(".");
            printTerm(window,"Directory created : "+path,"LawnGreen");
        }
    }catch(exception& e){
        ICommand::printTerm(window,e.what(),"red");
    }

}
