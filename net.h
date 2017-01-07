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
  void getIsFinished(QNetworkReply*);
  void putIsFinished(QNetworkReply *);
  void saveFile();
public:
  explicit Net(QObject *parent = 0);

  void SiteOperations(QString url, QString username="", QString password="", int port=-1);
private:
  QNetworkReply *reply;
  QFile *file;
};


#endif // NET_H
