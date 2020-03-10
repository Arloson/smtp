#include "mime.h"

Mime::Mime(QObject *parent) : QObject(parent)
{

}

QString Mime::getMami()
{
    return QString(mami_version+type +"filename="+ nameFile +"\r\n");
}

void Mime::setFileName(const QString &name)
{
    nameFile = name;
}

 QString Mime::header(const QString &s)
{
    QString header("MIME-Version: 1.0\r\n");
    header.append("Content_Type: multipart/mixed; boundary=""");
    return header;
}
