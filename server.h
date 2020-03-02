#ifndef SSL_ERROR_H
#define SSL_ERROR_H

#include <QObject>




class QSslSocket;
class QSslError;

class Server : public QObject
{
    Q_OBJECT

private:
   const int code[25] = {200, 211, 214, 220,
                 221, 250, 251, 252,
                 354, 421, 450, 451,
                 452, 500, 501, 502,
                 503, 504, 521, 530,
                 550, 551, 552, 553,
                 554};
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
