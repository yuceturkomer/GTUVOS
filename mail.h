
#ifndef MAIL_H
#define MAIL_H


#include<iostream>
#include <string>

using namespace std;

class Mail
{
public:
    Mail();
    Mail(string From, string To, string Subject, string Body,string CC="");

    string getFrom();
    string getTo();
    string getCC();
    string getSubject();
    string getBody();

    void setFrom(string);
    void setTo(string);
    void setCC(string);
    void setSubject(string);
    void setBody(string);

private:

    string from;
    string to;
    string cc;
    string subject;
    string body;


};

#endif // MAIL_H
