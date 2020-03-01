#ifndef SMTP_H
#define SMTP_H

#include <QObject>

class Server;

class Smtp : public QObject
{
    Q_OBJECT
public:
    explicit Smtp(QObject *parent = nullptr);


    void connect_host(QString mail);
    void login();
    void mail_from(QString mail);
    void rcpt_to(QString mail);
    void data(QString);
    void quit();
signals:


private:
    Server* s;
};

#endif // SMTP_H
