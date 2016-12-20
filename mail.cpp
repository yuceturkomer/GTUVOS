#include "mail.h"

/*
 * No parameter constructor for mail object
 */
Mail::Mail()
{
    setFrom("");
    setTo("");
    setCC("");
    setSubject("");
    setBody("");
}


Mail::Mail(string From, string To, string Subject, string Body,string CC){
    setFrom(From);
    setTo(To);
    setCC(CC);
    setSubject(Subject);
    setBody(Body);
}

string Mail::getFrom(){
    return from;
}

string Mail::getTo(){
    return to;
}

string Mail::getCC(){
    return cc;
}

string Mail::getSubject(){
    return subject;
}

string Mail::getBody(){
    return body;
}

void Mail::setFrom(string From){
    from=From;
}

void Mail::setTo(string To){
    to=To;
}

void Mail::setCC(string CC){
    cc=CC;
}

void Mail::setSubject(string Subject){
    subject=Subject;
}

void Mail::setBody(string Body){
    body=Body;
}



