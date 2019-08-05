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
    KhipuData();
    bool saveData(QList<KhipuSpace*> spaceList, QString fileName);
    QList<KhipuSpace*> loadData(QList<KhipuSpace*> spaceList, QString fileName);
};

#endif // KHIPUDATA_H
