#include "khipudata.h"

#include "khipuspace.h"

#include <QModelIndex>
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
    document.insert("spaces",spaces);

    QJsonDocument doc(document);
    file.write(doc.toJson());
    file.close();

    return true;
}

QList<KhipuSpace*> KhipuData::loadData(QString fileName)
{
    fileName = fileName + ".json";
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Não foi possível abrir o arquivo";
        return QList<KhipuSpace*>();
    }

    QByteArray data = file.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(data));
    QJsonArray spaces = loadDoc["spaces"].toArray();

    QList<KhipuSpace*> spaceList;

    for (int i = 0; i < spaces.size(); ++i) {
        QJsonObject spaceObj = spaces[i].toObject();
        KhipuSpace* space = new KhipuSpace(spaceObj["name"].toString(),spaceObj["type"].toString());
        QJsonArray plots = spaceObj["plots"].toArray();

        for (int j = 0; j < plots.size(); ++j) {
            QJsonObject plotObj = plots[i].toObject();
            space->addPlot(plotObj["expression"].toString(),spaceObj["type"].toString());
        }

        spaceList.append(space);
    }

    return spaceList;
}
