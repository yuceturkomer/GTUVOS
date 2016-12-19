#ifndef MAILCMD_H
#define MAILCMD_H
#include <QApplication>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include "gtuvos.h"
#include "command.h"
#include "precompiledxml.h"

using namespace rapidxml;

class MailCMD : public ICommand
{
public:
    MailCMD(QStringList str);
    ~MailCMD();
    void execute(Ui::MainWindow *window);
    bool readMailFile(string fileName, vector<Mail>&);
    void writeToFile(vector<Mail>);
//private:
//    vector<Mail> mails;
//    vector<Mail> sendMail;
};

#endif // MAILCMD_H
