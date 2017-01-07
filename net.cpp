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

Net::Net(QObject *parent) : QObject(parent)
{

}

void Net::getIsFinished(QNetworkReply* reply)
{
    QByteArray arr = reply->readAll();
    cerr << "Reply: "<<arr.toStdString();
    std::cout<<"Finished getting the stuff."<<std::endl;

}
void Net::putIsFinished(QNetworkReply *reply){
    QByteArray bytes = reply->readAll();
    QString str = QString::fromUtf8(bytes.data(), bytes.size());
    qDebug()<<"PUT INFORMATION: "<<reply->error();
    std::cout<<"Finished putting the stuff."<<std::endl;
}

void Net::saveFile(){
    cerr<<"SaveFile started\n";
    QFile *file = new QFile("testf.txt");
    if(!file->isOpen())
            file->open(QIODevice::WriteOnly);
     QByteArray bytes = reply->readAll();
     QString str = QString::fromUtf8(bytes.data(), bytes.size());
     qDebug()<<str;

}

/**
 * @brief Net::SiteOperations
 *
 * !!!! Simdilik sadece verilen URL'i html olarak çekiyor ve stderr'a bastiriyor !!
 *
 * @param url
 * @param username
 * @param password
 * @param port
 */
void Net::SiteOperations(QString url, QString username, QString password, int port)
{

    QUrl *myurl = new QUrl(url);
    /*myurl->setHost(url);
    myurl->setScheme("ftp");
    myurl->setUserName(username);
    myurl->setPassword(password);*/
    std::cerr<<"URL: "<<myurl->toString().toStdString()<<"\n";
    /*if(port>=0)
        myurl.setPort(port);*/


    //getmanager = new QNetworkAccessManager();


    QNetworkRequest req(*myurl);

    putmanager = new QNetworkAccessManager(this);
    connect(putmanager,SIGNAL(finished(QNetworkReply*)),
            this,SLOT(putIsFinished(QNetworkReply*)));

    /*reply = getmanager->get(req);

    connect(reply, SIGNAL(readyRead()),
            this, SLOT(saveFile()));
*/
         // Bu kisimda file oluşturup açildi mi diye baktim, asil olay alt tarafta
         FILE *fp = fopen("test.txt","rw+");
         if(fp==NULL){
             std::cout << "File couldn't openededed"<<std::endl;
             return;
         }


        file = new QFile();
         if(file->open(fp, QIODevice::ReadOnly)){
             //file->write("file append test");

         putmanager->put(req ,file);


         }

        /*fclose(fp); // Bunlar error verebiliyor dikkat. Verirse comment'e al
        file.close(); // Bunlar error verebiliyor dikkat. Verirse comment'e al*/
        std::cerr<<"end site operations\n";

}
