#include "mail.h"

Mail::Mail()
{
    setFrom("");
    setTo("");
    setCC("");
    setBCC("");
    setSubject("");
    setBody("");

}

Mail::Mail(string From, string To){
    setFrom(From);
    setTo(To);
    setCC("");
    setBCC("");
    setSubject("");
    setBody("");
}

Mail::Mail(string From, string To, string Body){
    setFrom(From);
    setTo(To);
    setCC("");
    setBCC("");
    setSubject("");
    setBody(Body);

}

Mail::Mail(string From, string To, string Subject, string Body){
    setFrom(From);
    setTo(To);
    setCC("");
    setBCC("");
    setSubject(Subject);
    setBody(Body);
}

Mail::Mail(string From, string To, string CC, string BCC, string Subject, string Body){

    setFrom(From);
    setTo(To);
    setCC(CC);
    setBCC(BCC);
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

string Mail::getBCC(){
    return bcc;
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
void Mail::setBCC(string BCC){
    bcc=BCC;
}

void Mail::setSubject(string Subject){
    subject=Subject;
}

void Mail::setBody(string Body){
    body=Body;
}


