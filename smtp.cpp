#include "smtp.h"
#include "server.h"
#include <QDebug>
#include <QFile>

Smtp::Smtp(QObject *parent) : QObject(parent), s(new Server(this)), f(new QFile(this))
{

}

void Smtp::connect_host(QString host, int port)
{
     s->init(host, port);


}

void Smtp::login(QString mail, QString passwd)
{
    this->mail = mail;
    //HELO
    s->write(QByteArray("HELO ")+mail);
    s->write(rn);


    log = '\0'+mail.toUtf8()+
            '\0'+ passwd.toUtf8();
    s->write(QByteArray("AUTH PLAIN " + log.toBase64()+"\r\n"));

}

void Smtp::mail_from(QString mail)
{
    QByteArray raw;
    raw.append(from);
    raw.append(mail.toUtf8());
    raw.append(rn);
    s->write(raw);
}

void Smtp::rcpt_to(QString mail)
{
    mail_to = mail;
    QByteArray raw(QString(to+mail+rn).toUtf8());
    s->write(raw);
}


void Smtp::data(QByteArray mes)
{
    qDebug()<<"Mail is "<< mail;
    QFile fl("E:\\tmp\\mail\\m.cpp");
    fl.open(QFile::ReadOnly);
    QByteArray file = fl.readAll();


    QByteArray m;
    m.append(data_);
    m.append("From:"+mail+rn);
    m.append("To: "+mail_to+rn);
    //заголовок
    m.append(message + mes+"\r\n");
    m.append(rn+rn);
    //тело
    m.append(file);
    m.append(rn);

    //конец
    m.append(rn+"."+rn);

    s->write(m);


}

void Smtp::quit()
{
    QByteArray raw(QString("QUIT"+rn).toUtf8());
    s->write(raw);
}
