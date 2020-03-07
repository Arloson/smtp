#ifndef MAMI_H
#define MAMI_H

#include <QObject>

class Mami : public QObject
{
    Q_OBJECT
public:
    explicit Mami(QObject *parent = nullptr);

signals:

};

#endif // MAMI_H
