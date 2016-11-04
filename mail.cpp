#include "mail.h"

mail::mail()
{
    setFrom("");
    setTo("");
    setCC("");
    setBCC("");
    setSubject("");
    setBody("");

}

mail::mail(string From, string To){
    setFrom(From);
    setTo(To);
    setCC("");
    setBCC("");
    setSubject("");
    setBody("");
}

mail::mail(string From, string To, string Body){
    setFrom(From);
    setTo(To);
    setCC("");
    setBCC("");
    setSubject("");
    setBody(Body);

}

mail::mail(string From, string To, string Subject, string Body){
    setFrom(From);
    setTo(To);
    setCC("");
    setBCC("");
    setSubject(Subject);
    setBody(Body);
}

mail::mail(string From, string To, string CC, string BCC, string Subject, string Body){

    setFrom(From);
    setTo(To);
    setCC(CC);
    setBCC(BCC);
    setSubject(Subject);
    setBody(Body);
}

string mail::getFrom(){
    return from;
}

string mail::getTo(){
    return to;
}

string mail::getCC(){
    return cc;
}

string mail::getBCC(){
    return bcc;
}

string mail::getSubject(){
    return subject;
}

string mail::getBody(){
    return body;
}

void mail::setFrom(string From){
    from=From;
}

void mail::setTo(string To){
    to=To;
}

void mail::setCC(string CC){
    cc=CC;
}
void mail::setBCC(string BCC){
    bcc=BCC;
}

void mail::setSubject(string Subject){
    subject=Subject;
}

void mail::setBody(string Body){
    body=Body;
}


