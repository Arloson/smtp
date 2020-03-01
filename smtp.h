#ifndef SMTP_H
#define SMTP_H

#include <QObject>



class Server;

class Smtp : public QObject
{
    Q_OBJECT
public:
    explicit Smtp(QObject *parent = nullptr);

    void connect_host(QString mail, int port);
    void login(QString mail, QString passwd);
    void mail_from(QString mail);
    void rcpt_to(QString mail);
    void data(QString);
    void quit();
signals:


private:
    Server* s;
    const QString rn = "\r\n";
    QString mail;



    QByteArray log ;/*= '\0'+ QString("Arloson1@yandex.com").toUtf8()+'\0'+ QString("cthutq161").toUtf8();*/
    QString to = "RCPT TO: ";
    QString from = "MAIL FROM:";
    QString data_ = "DATA\r\n";
    QString message = "Subject: ";

};

#endif // SMTP_H
