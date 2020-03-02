#include "smtp.h"
#include "server.h"
#include <QDebug>


Smtp::Smtp(QObject *parent) : QObject(parent), s(new Server(this))
{

}

void Smtp::connect_host(QString host, int port)
{
     s->init(host, port);
     s->write(QByteArray("HELO Arloson1@yandex.com"));



}

void Smtp::login(QString mail, QString passwd)
{
    this->mail = mail;


    QByteArray login = '\0'+ QString("Arloson1@yandex.com").toUtf8()+
            '\0'+ QString("cthutq161").toUtf8();
    s->write(QByteArray("AUTH PLAIN " + login.toBase64()+"\r\n"));
    s->write(QByteArray("AUTH PLAIN " + login.toBase64()+"\r\n"));
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

    QByteArray m;
    m.append(data_);
    m.append("From:"+mail+rn);
    m.append("To: "+mail_to+rn);
    //заголовок
    m.append(message + "Заголовок нужно что то придумать\r\n");
    m.append(rn+rn);
    //тело
    m.append(mes);
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
