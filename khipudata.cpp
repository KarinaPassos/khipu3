#include "khipudata.h"
#include "khipuspace.h"

#include <QModelIndex>
#include <QDebug>
#include <QJsonDocument>

KhipuData::KhipuData()
{

}

bool KhipuData::saveData(const QList<KhipuSpace*>& spaceList, const QString& fileName)
{
    QFile file(fileName + QStringLiteral(".json"));
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Could not open file for writting, verify your permissions" << file.errorString();
        return false;
    }

    QJsonArray spaces;
    for (auto *space : spaceList){
        auto spaceObj = QJsonObject {
            {"name", space->name()},
            {"type", space->type()}
        };

        QJsonArray plots;
        auto *plotsModel = space->model();

        for (int j = 0, end = plotsModel->rowCount(); j < end; j++){
            const QModelIndex plotIndex = plotsModel->index(j, 0);
            const QString expression = plotsModel->data(plotIndex, Analitza::PlotsModel::DescriptionRole).toString();
            plots.append(QJsonObject{ {"expression", expression}} );
        }
        spaceObj["plots"] = plots;

        spaces.append(spaceObj);
    }

    QJsonObject document;
    document.insert("spaces",spaces);

    QJsonDocument doc(document);
    file.write(doc.toJson());
    file.close();

    return true;
}

QList<KhipuSpace*> KhipuData::loadData(const QString& fileName)
{
    QFile file(QUrl(fileName).toLocalFile());

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
        KhipuSpace* space = new KhipuSpace(spaceObj["name"].toString(),spaceObj["type"].toInt());
        QJsonArray plots = spaceObj["plots"].toArray();

        for (int j = 0; j < plots.size(); ++j) {
            QJsonObject plotObj = plots[j].toObject();
            space->addPlot(plotObj["expression"].toString());
        }

        spaceList.append(space);
    }

    return spaceList;
}
