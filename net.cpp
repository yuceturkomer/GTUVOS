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


}
