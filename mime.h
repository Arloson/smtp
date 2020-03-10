#ifndef MAMI_H
#define MAMI_H

#include <QObject>



class Mime : public QObject
{
    Q_OBJECT
public:
    explicit Mime(QObject *parent = nullptr);

    QString getMami();
    void setFileName(const QString& name);
    //content-type:
    QString header(const QString& s);
    //tipe
    void setType(const QString &);
    
    

signals:

private:
    void operator=(const Mime&);
    Mime(const Mime&);
    
    
    QString nameFile;
    const QString content = "Content-Transfer-Encoding: binary\r\n";
    const QString mami_version = "MIME-Version: 1.0\r\n";
    const QString type = "Content-Type:application/zip;";
};

#endif // MAMI_H
