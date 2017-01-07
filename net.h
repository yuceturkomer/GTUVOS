#ifndef NET_H
#define NET_H

#include <QObject>
#include <QtCore>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Net : public QObject
{
Q_OBJECT
  QNetworkAccessManager *getmanager;
  QNetworkAccessManager *putmanager;
private slots:
  void getIsFinished(QNetworkReply *);
  void putIsFinished(QNetworkReply *);
public:
  explicit Net(QObject *parent = 0);

  void SiteOperations(QString url, QString username="", QString password="", int port=-1);
};


#endif // NET_H
