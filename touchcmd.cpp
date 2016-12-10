#include "touchcmd.h"
#include "gtuexceptions.h"

TouchCMD::~TouchCMD(){

}

TouchCMD::TouchCMD(QStringList params):ICommand(params)
{
    cout<<"Touch cmd constructed"<<endl;
}

void TouchCMD::execute(Ui::MainWindow *window){
    cout<<"Touch execute started."<<endl;

    try{
        if(mParams.size()!=2){
            printTerm(window,"Invalid touch parameter","red");
            printTerm(window,"Please check help manual","DeepSkyBlue");
            return;
        }

        QString path=mParams[1];
        cout<<"Path:"<<path.toStdString()<<endl;

        QFile myFile(path);

        if(myFile.exists()){
            throw FILE_EXIST_EXCEPTION();
        }
        else{
            myFile.open(QIODevice::WriteOnly);
            myFile.close();
            printTerm(window,"File created : "+path,"DeepSkyBlue");
        }
    }catch(exception& e){
        ICommand::printTerm(window,e.what(),"red");
    }

}
