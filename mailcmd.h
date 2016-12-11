#ifndef MAILCMD_H
#define MAILCMD_H
#include <QApplication>
#include <Vector>
#include "gtuvos.h"
#include "command.h"
#include"rapidxml.hpp"
#include"rapidxml_utils.hpp"

class MailCMD : public ICommand
{
public:
    MailCMD(QStringList str);
    ~MailCMD();
    void execute(Ui::MainWindow *window);
    void readMailFile(string fileName);
    void writeToFile();
private:
	vector<Mail> mails;
    vector<Mail> sendMail;
};

#endif // MAILCMD_H
