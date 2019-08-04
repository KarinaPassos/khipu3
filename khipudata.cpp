#include "khipudata.h"
#include "QModelIndex"
#include <qjsondocument.h>

KhipuData::KhipuData()
{

}

bool KhipuData::saveData(QList<KhipuSpace*> spaceList, QString fileName)
{
    fileName = fileName + ".json";
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Não deu pra salvar o arquivo";
        return false;
    }

    QJsonArray spaces;
    for (int i = 0; i < spaceList.size(); i++){
        QJsonObject space;
        space["name"] = spaceList[i]->name();
        space["id"] = spaceList[i]->id();
        space["type"] = spaceList[i]->type();

        QJsonArray plots;

        auto *plotsModel = spaceList[i]->model();

        for (int j = 0; j < spaceList[i]->model()->rowCount(); j++){
            QJsonObject plot;
            auto plotIndex = plotsModel->index(j, 0);
            auto data = plotsModel->data(plotIndex, Analitza::PlotsModel::DescriptionRole);

            plot["expression"] = data.toString();
            plots.append(plot);
        }
        space["plots"] = plots;

        spaces.append(space);
    }

    QJsonObject document;
    document.insert(QString::number(0),spaces);

    QJsonDocument doc(document);
    file.write(doc.toJson());
    file.close();

    return true;
}

bool KhipuData::loadData(QList<KhipuSpace*> spaceList, QString fileName)
{
    fileName = fileName + ".json";
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Não foi possível abrir o arquivo";
        return false;
    }

    QByteArray data = file.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(data));
    QJsonArray spaces = loadDoc["spaces"].toArray();

    qDebug() << spaces.size();

    for (int i = 0; i < spaces.size(); i++){
        qDebug() << "se chegar aqui é pq o bug foi resolvido... ou nao";
        QJsonObject spaceObj = spaces[i].toObject();
        KhipuSpace* space = new KhipuSpace(spaceObj["name"].toString(),spaceObj["type"].toString(),spaceList.size());
        QJsonArray plots = spaceObj["plots"].toArray();

        /*for (int j = 0; j < plots.size(); j++){
            space->addPlot(plots[i].toString());
        }*/

        spaceList.append(space);
    }

    return true;
}
