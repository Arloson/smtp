#include <QObject>
#include <QCoreApplication>

#include <QDebug>




#define SMTP 465
#include "smtp.h"
#include "server.h"

QString ya = "smtp.yandex.ru";




//Server ser;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Smtp smtp;
    //подключение к хосту
    smtp.connect_host(ya, SMTP);
    //авторизаци€
    smtp.login("Arloson1@yandex.com", "cthutq161");
    //кому от кого
    smtp.mail_from("Arloson1@yandex.com");
    smtp.rcpt_to("sergeyantonov3083@gmail.com");
    //текст сообщени€
    smtp.data("ѕривет мир");
    //QUIT
    smtp.quit();

  /*  ser.init(ya, SMTP);

  ser.write(QByteArray("HELO Arloson1@yandex.com\r\n"));

    QByteArray login = '\0'+ QString("Arloson1@yandex.com").toUtf8()+
            '\0'+ QString("cthutq161").toUtf8();

    ser.write(QByteArray("AUTH PLAIN " + login.toBase64()+"\r\n"));

    ser.write(QByteArray("MAIL FROM: Arloson1@yandex.com\r\n"));

    ser.write(QByteArray("RCPT TO: sergeyantonov3083@gmail.com\r\n"));

    ser.write(QByteArray("DATA\r\n"));
    ser.write(QByteArray("From:Arloson1@yandex.com\r\n"));
    ser.write(QByteArray("Subject: second\r\n.\r\n"));


    ser.write(QByteArray("QUIT\r\n"));

*/


    return a.exec();
}
