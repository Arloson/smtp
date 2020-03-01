#include <QObject>
#include <QCoreApplication>

#include <QDebug>




#define SMTP 465
#include "smtp.h"


static const QString ya = "smtp.yandex.ru";






int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Smtp smtp;
    //подключение к хосту
    smtp.connect_host(ya, SMTP);
    //авторизация
    smtp.login("Arloson1@yandex.com", "cthutq161");
    //кому от кого
    smtp.mail_from("Arloson1@yandex.com");
    smtp.rcpt_to("sergeyantonov3083@gmail.com");
    //текст сообщения
    smtp.data("привет мир");
    //QUIT
    smtp.quit();
/*
    ser.init(ya, SMTP);

    ser.write("HELO Arloson1@yandex.com\r\n");

    QByteArray login = '\0'+ QString("Arloson1@yandex.com").toUtf8()+
            '\0'+ QString("cthutq161").toUtf8();

    ser.write("AUTH PLAIN " + login.toBase64()+"\r\n");

    ser.write("MAIL FROM: Arloson1@yandex.com\r\n");

    ser.write("RCPT TO: sergeyantonov3083@gmail.com\r\n");

    ser.write("DATA\r\n");
    ser.write("From:Arloson1@yandex.com\r\n");
    ser.write("Subject: second\r\n.\r\n");


    ser.write("QUIT\r\n");

*/


    return a.exec();
}
