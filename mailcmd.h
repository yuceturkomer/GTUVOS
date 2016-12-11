#ifndef MAILCMD_H
#define MAILCMD_H
#include <QApplication>
#include <vector>
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
    bool readMailFile(string fileName);
    void writeToFile();
private:
    vector<Mail> mails;
    vector<Mail> sendMail;
};

#endif // MAILCMD_H
