#include "smtp.h"
#include "server.h"
#include <QDebug>


Smtp::Smtp(QObject *parent) : QObject(parent), s(new Server(this))
{

}

void Smtp::connect_host(QString host, int port)
{
     s->init(host, port);

}

void Smtp::login(QString mail, QString passwd)
{
    mail.append(mail);

    s->write("HELO "+mail+rn);


    log = '\0'+ mail.toUtf8()+
            '\0'+ passwd.toUtf8();
    s->write("AUTH PLAIN "+ log.toBase64()+rn);

}

void Smtp::mail_from(QString mail)
{
      s->write(from+mail+rn);
}

void Smtp::rcpt_to(QString mail)
{
    s->write(to+mail+rn);
}


void Smtp::data(QString mes)
{
    qDebug()<<"Mail is "<< mail;
    s->write(data_);
    s->write("From:"+mail+rn+message+mes+rn);
    s->write(".\r\n");
}

void Smtp::quit()
{
    s->write("QUIT"+rn);
}
