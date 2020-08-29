#include "getip.h"
#include <stdio.h>

GetIP::GetIP(QObject *parent) : QObject(parent)
{
    this->ip = "0.0.0.0";
}

void GetIP::load()
{
    QString str = this->exeCmd("ip a");

    if (str.isEmpty())
        this->ip = "Error during execute command";
    else
    {
        str = this->parse(str);
        if (str.isEmpty())
            this->ip = "Can't find IP address";
        else
            this->ip = str;
    }
    emit this->ipChanged();
}

QString GetIP::getIp() const
{
    return this->ip;
}
void GetIP::setIp(QString value)
{
    this->ip = value;
}

QString GetIP::exeCmd(const char * cmd)
{
    FILE *      file;
    const int   bufSize = 128;
    char        buf[bufSize];
    QString     result;

    file = popen(cmd, "r");
    if (file)
    {
        while (fgets(buf, bufSize, file) != NULL)
            result.append(buf);
        pclose(file);
    }

    return result;
}
QString GetIP::parse(QString & str)
{
    int     begin;
    int     end;

    // find interface other than loopback
    begin = str.indexOf("BROADCAST,MULTICAST");
    if (begin == -1)
        return "";

    // searching IPv4
    begin = str.indexOf("inet", begin);
    if (begin == -1)
    {
        // IPv4 not exist, searching IPv6
        begin = str.indexOf("inet6", begin);
        if (begin == -1)
            return "";
        begin += 6;
    }
    else
        begin += 5;

    // searching space after IP address
    end = str.indexOf(" ", begin);
    if (end == -1)
        return "";

    return str.mid(begin, end - begin);
}
