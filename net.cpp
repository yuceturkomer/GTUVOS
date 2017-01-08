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
    QByteArray bytes = reply->readAll();
    QString str = QString::fromUtf8(bytes.data(), bytes.size());
    qDebug()<<"PUT INFORMATION: "<<reply->error();
    std::cout<<"Finished putting the stuff."<<std::endl;
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

/**
 * @brief Net::SiteOperations
 *
 */
void Net::sendFileToFTP(QString fileName)
{

    //getmanager = new QNetworkAccessManager();
    /*reply = getmanager->get(req);

    connect(reply, SIGNAL(readyRead()),
            this, SLOT(saveFile()));
*/

    QNetworkRequest req(this->url);

    file.setFileName(fileName);
    if(!file.exists())
        throw FILE_PATH_EXCEPTION();

    if(file.open(QIODevice::ReadOnly)){
        putmanager->put(req ,&file);
    }

    /*fclose(fp); // Bunlar error verebiliyor dikkat. Verirse comment'e al
    file.close(); // Bunlar error verebiliyor dikkat. Verirse comment'e al*/
    std::cerr<<"end site operations\n";

}
