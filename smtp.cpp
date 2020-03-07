#include "smtp.h"
#include "server.h"
#include <QDebug>
#include "mime.h"

#include <QFile>

Smtp::Smtp(QObject *parent) : QObject(parent), s(new Server(this))
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

    QFile f("E:\\tmp\\mail\\z.zip");
    f.open(QFile::ReadOnly);
    int siz = f.size();


    s->write(data_.toUtf8());
    s->write("From:"+mail+rn);
    s->write("To: "+mail_to+rn);
    s->write(message+"Test"+rn);

    s->write("MIME-Version: 1.0"+rn);
    //s->write("Content-Type:image/git"+rn);
    s->write("Content-Type:application/zip;attachment;filename=gif.zip"+rn);
    s->write("Content-Transfer-Encoding:Base64"+rn);
   // s->write("Content-Disposition:attachment; filename=gif.zip"+rn);



    s->write(rn+rn);
    s->write(f.readAll().toBase64());

    s->write(rn+"."+rn);

    //    QByteArray m;
//    m.append(data_);
//    m.append("From:"+mail+rn);
//    m.append("To: "+mail_to+rn);
//

//    m.append(message + mes+"\r\n");
//    m.append(rn+rn);
   //
   // m.append(mes);
  //  m.append(rn);


  //  m.append(rn+"."+rn);

  //  s->write(m);


}

void Smtp::quit()
{
    QByteArray raw(QString("QUIT"+rn).toUtf8());
    s->write(raw);
}
