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
    void data(QByteArray);
    void quit();
signals:


private:
    const int code[25] = {
                  200, 211, 214, 220,
                  221, 250, 251, 252,
                  354, 421, 450, 451,
                  452, 500, 501, 502,
                  503, 504, 521, 530,
                  550, 551, 552, 553,
                  554};


    Server* s;
    const QString rn = "\r\n";
    const QString auth = "AUTH PLAIN ";
    const QString to = "RCPT TO: ";
    const QString from = "MAIL FROM:";
    const QString data_ = "DATA\r\n";
    const QString message = "Subject: ";

    QString mail;
    QString mail_to;
    QByteArray log ;/*= '\0'+ QString("Arloson1@yandex.com").toUtf8()+'\0'+ QString("***").toUtf8();*/




};

#endif // SMTP_H
