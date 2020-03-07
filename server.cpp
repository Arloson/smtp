#include "server.h"



#include <QSslSocket>
#include <QList>
#include <QDebug>
#include <QSslError>
#include <QString>



Server::Server(QObject *parent) :
    QObject(parent), socket(new QSslSocket(this))
{


    connect(socket, QOverload<const QList<QSslError> &>::of(&QSslSocket::sslErrors)
            , this, &Server::error);
    connect(socket, &QSslSocket::connected, [=](){qDebug()<<"connected";} );
    connect(socket, &QSslSocket::readyRead,
            [=](){

               check(socket->readAll());
    });


}

Server::~Server()
{
    disconnect(socket, QOverload<const QList<QSslError> &>::of(&QSslSocket::sslErrors),
               this, &Server::error);
    disconnect(socket, &QSslSocket::connected, this, nullptr);
    disconnect(socket, &QSslSocket::readyRead,this, nullptr);

    if(socket->isOpen())
    {
        qDebug("Close socket");
        socket->close();
    }

}



void Server::check(QByteArray c)
{
    qDebug(c);
    QByteArray responseText(c.trimmed());
    int responseCode = responseText.left(3).toInt();
    if(responseCode == 221){
        this->~Server();
    }



}
void Server::init(QString host, int port){
    socket->connectToHostEncrypted(host, port);

    if(!socket->waitForConnected()){
       qDebug()<<"don't connected";
       this->~Server();
    }
}

int Server::write(QString msg)
{
    socket->write(msg.toStdString().c_str());
    socket->waitForBytesWritten();
    return 0;
}



void Server::write(QByteArray message)
{
    socket->write(message);
    socket->waitForBytesWritten();
}

void Server::error(const QList<QSslError> &errors)
{
    for(QSslError err : errors)
    {
        qDebug()<<err.errorString()<<'\n';
    }
}
