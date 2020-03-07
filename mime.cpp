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
