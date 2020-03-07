#ifndef SSL_ERROR_H
#define SSL_ERROR_H

#include <QObject>




class QSslSocket;
class QSslError;

class Server : public QObject
{
    Q_OBJECT

private:

    QSslSocket* socket = nullptr;
public:
    explicit Server(QObject *parent = nullptr);
    virtual ~Server();
    void check(QByteArray);
    void init(QString host, int port);
    int write(QString);
    void write(QByteArray message);

signals:

public slots:

    void error(const QList<QSslError> &errors);

};

#endif // SSL_ERROR_H
