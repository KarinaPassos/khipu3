#ifndef KHIPUDATA_H
#define KHIPUDATA_H
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <khipuspacemodel.h>
#include <QJsonArray>

class KhipuData
{
public:
    static bool saveData(const QList<KhipuSpace*>& spaceList,const QString& fileName);
    static QList<KhipuSpace*> loadData(const QString& fileName);

private:
    KhipuData();
};

#endif // KHIPUDATA_H
