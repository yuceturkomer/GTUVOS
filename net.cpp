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

void Net::getIsFinished(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
    std::cout<<"Finished getting the stuff."<<std::endl;

}
void Net::putIsFinished(QNetworkReply *reply){
    qDebug() << reply->readAll();
    std::cout<<"Finished putting the stuff."<<std::endl;
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

    QUrl myurl(url);
    myurl.setUserName(username);
    myurl.setPassword(password);
    if(port>=0)
        myurl.setPort(port);


    getmanager = new QNetworkAccessManager(this);
    getmanager->get(QNetworkRequest(myurl));

    connect(getmanager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getIsFinished(QNetworkReply*)));

    /*
         // Bu kisimda file oluşturup açildi mi diye baktim, asil olay alt tarafta
         FILE *fp = fopen("test.txt","w+r");
         if(fp==NULL){
             std::cout << "File couldn't openededed"<<std::endl;
             return;
         }

         QFile file;

         if(file.open(fp, QIODevice::ReadWrite)){
             std::cout<<"Dude, YES.."<<std::endl;
             file.write("msg HEHEYT ahey");
             QTextStream in(&file);
             file.seek(0);
             std::cout<<"File content first line ---> "<<in.readLine().toStdString()<<std::endl;
         }

        // Asil olay
         putmanager = new QNetworkAccessManager(this);
         putmanager->put(QNetworkRequest(testurl),&file);
         connect(putmanager,SIGNAL(finished(QNetworkReply*)),
                 this,SLOT(putIsFinished(QNetworkReply*)));

         }

        fclose(asdf); // Bunlar error verebiliyor dikkat. Verirse comment'e al
        file.close(); // Bunlar error verebiliyor dikkat. Verirse comment'e al
        */

}
