#include <QObject>
#include <QCoreApplication>

#include <QDebug>

#include <QSslSocket>
#include <QList>


#include "server.h"
#define SMTP 465

static const QString ya = "smtp.yandex.ru";
Server ser;







int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString t = "123 shdf";
    qDebug()<<t.contains("123");

    ser.init(ya, SMTP);

    ser.write("HELO Arloson1@yandex.com\r\n");

    QByteArray login = '\0'+ QString("Arloson1@yandex.com").toUtf8()+
            '\0'+ QString("cthutq161").toUtf8();
    ser.write("AUTH PLAIN " + login.toBase64()+"\r\n");



    ser.write("MAIL FROM: Arloson1@yandex.com\r\n");

    ser.write("RCPT TO: sergeyantonov3083@gmail.com\r\n");

    ser.write("DATA\r\n");
    ser.write("From:Arloson1@yandex.com\r\n");
    ser.write("Subject: Hello, frend\r\n.\r\n");


    ser.write("QUIT\r\n");


    return a.exec();
}
