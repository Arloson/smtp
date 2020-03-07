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



    return a.exec();
}
