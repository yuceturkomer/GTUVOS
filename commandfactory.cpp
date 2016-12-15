#include "commandfactory.h"

#include <QApplication>

CommandFactory *CommandFactory::instance=NULL;

CommandFactory::CommandFactory(){
    cout<<"CommandFactory constructed!"<<endl;
}

ICommand* CommandFactory::getCommand(QString str){
    ICommand* cmd=NULL;
    QStringList parses = parseStr(str);// Call of parseStr function.

    cout<<"TestParser:";
    foreach (QString itr, parses) {
        cout<<itr.toStdString()<<endl;
    }

    QString command = parses[0];// First element of vector parses. Used for deciding the command.

    if(command.compare("cp")==0){
        cmd = new CopyCMD(parses);
    }else if (command.compare("mail")==0){
        QStringList mailParses =parseMailCMD(str);
        cmd = new MailCMD(mailParses);
    }else if (command.compare("help")==0){
        cmd = new HelpCMD(parses);
    }else if (command.compare("exit")==0){
        cmd = new ExitCMD(parses);
    }else if(command.compare("ls")==0){
        cmd = new ListCMD(parses);
    }else if(command.compare("mkdir")==0){
        cmd = new MkdirCMD(parses);
    }else if(command.compare("touch")==0){
        cmd=new TouchCMD(parses);
    }else if(command.compare("man")==0){
        cmd=new ManCMD(parses);
    }else if(command.compare("clear")==0){
        cmd=new ClearCMD(parses);
    }
    else throw INVALID_COMMAND_EXCEPTION();

    return cmd;
}

/* Function takes a QString type string and splits it according to spaces in it, then returns that
 * in a vector form. If the str's size is 0, the "Insufficient Tokens" will be pushed to de vector and returns vector instantly.
 * If the size is not 0, for each element in stringList, which was already split by whitespaces, will be transformed into a
 * standart string from QString type and then it is pushed to the return vector which named as parses.
 *
 * @param str the QString type string
 * @return A vector of strings. Each element is parsed and will not include any whitespaces. *
 */
QStringList CommandFactory::parseStr(QString str){
    cout<<endl<<"parseStr is started, param: "<<str.toStdString()<<endl;

    QStringList stringlist =str.split(" ",QString::SkipEmptyParts);

    cout<<"ParseSize::"<<stringlist.size();

    if(stringlist.empty()){
        stringlist.append("InsufficientNumberOfTokens");
    }

    return stringlist;
}

/* This function executes the command if possible and returns true. To decide this it calls the parseStr function and
 * looks at the return value's first element.
 * Else if not possible function will return false.
 *
 * @param str the QString type string which contains full command and parameters for commands if there can be.
 * @return If it's an available command returns true, else returns false.
 *
 */

QStringList CommandFactory::parseMailCMD(QString str){
    cout<<"CommandFactory::parseMailCMD, str:"<<str.toStdString()<<endl;

    // mail send "to to to" "tit le le le" "sub sub sub sub"
    QStringList mailTkn = str.split("\"",QString::SkipEmptyParts);
    QString cmd = mailTkn[0];
    QStringList tokens = cmd.split(" ",QString::SkipEmptyParts);
    if(mailTkn.size()==6){
        tokens.append(mailTkn[1]);
        tokens.append(mailTkn[3]);
        tokens.append(mailTkn[5]);
    }
    foreach (QString itr, tokens) {
       cout<<"Token: "<<itr.toStdString()<<endl;
    }
    return tokens;
}
