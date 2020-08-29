#ifndef GETIP_H
#define GETIP_H

#include <QObject>
#include <QString>

class GetIP : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString ip READ getIp WRITE setIp NOTIFY ipChanged)

public:
    explicit GetIP(QObject *parent = nullptr);

signals:
    void ipChanged();

public slots:
    void load();

private:
    QString ip;
    QString getIp() const;
    void    setIp(QString value);

    QString exeCmd(const char * cmd);
    QString parse(QString & str);
};

#endif // GETIP_H
