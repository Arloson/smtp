#include "smtp.h"
#include "server.h"


Smtp::Smtp(QObject *parent) : QObject(parent), s(new Server(this))
{

}

void Smtp::connect_host(QString mail)
{

}

void Smtp::login()
{


}

void Smtp::mail_from(QString mail)
{

}

void Smtp::rcpt_to(QString mail)
{

}

void Smtp::data(QString)
{

}

void Smtp::quit()
{

}
