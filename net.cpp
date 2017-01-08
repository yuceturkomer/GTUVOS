#include "net.h"

#include <iostream>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QIODevice>
#include <QFile>
#include <stdio.h>
#include <QObject>
#include <QDir>
#include "gtuexceptions.h"


Net::Net(QObject *parent) : QObject(parent)
{
    putmanager = new QNetworkAccessManager(this);
    connect(putmanager,SIGNAL(finished(QNetworkReply*)),this,SLOT(putIsFinished(QNetworkReply*)));
}

void Net::getIsFinished(QNetworkReply* reply)
{
    QByteArray arr = reply->readAll();
    qDebug()<<"GetFileFromFTP Finished\n";

}
void Net::putIsFinished(QNetworkReply *reply){
    this->reply=reply;
    errorMessage.append(reply->errorString());
    /*QByteArray bytes = reply->readAll();
    QString str = QString::fromUtf8(bytes.data(), bytes.size());*/
    qDebug()<<"PUT STATUS: "<<errorMessage;
}

void Net::saveFile(){
    std::cerr<<"SaveFile started\n";
    QFile *file = new QFile("testf.txt");
    if(!file->isOpen())
        file->open(QIODevice::WriteOnly);
    QByteArray bytes = reply->readAll();
    QString str = QString::fromUtf8(bytes.data(), bytes.size());
    qDebug()<<str;
}

void Net::setURL(QString url){
    this->url.setUrl(url);
}

QUrl Net::getURL(){
    return this->url;
}

QNetworkReply* Net::getReply(){
    return this->reply;
}

void Net::sendFileToFTP(QString fileName)
{

    //getmanager = new QNetworkAccessManager();
    /*reply = getmanager->get(req);

    connect(reply, SIGNAL(readyRead()),
            this, SLOT(saveFile()));
*/

    QNetworkRequest req(this->url);

    file.setFileName(fileName);
    if(!file.exists()){
        std::cerr<<"here";
        throw FILE_PATH_EXCEPTION();
    }

    if(file.open(QIODevice::ReadOnly)){
        putmanager->put(req ,&file);
    }

    /*fclose(fp); // Bunlar error verebiliyor dikkat. Verirse comment'e al
    file.close(); // Bunlar error verebiliyor dikkat. Verirse comment'e al*/

    QEventLoop loop;
    connect(putmanager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    loop.exec();

    if(reply->error()!=QNetworkReply::NetworkError::NoError){
        throw FTP_EXCEPTION();
    }

}
