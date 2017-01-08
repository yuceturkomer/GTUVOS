#ifndef NET_H
#define NET_H

#include <QObject>
#include <QtCore>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Net : public QObject
{
Q_OBJECT

public:
  explicit Net(QObject *parent = 0);
  void setURL(QString url);
  QUrl getURL();
  void sendFileToFTP(QString fileName);

private slots:
  void getIsFinished(QNetworkReply*);
  void putIsFinished(QNetworkReply *);
  void saveFile();

private:
  QNetworkReply *reply;
  QFile file;
  QUrl url;
  QNetworkAccessManager *getmanager;
  QNetworkAccessManager *putmanager;

};


#endif // NET_H
