#include "khipudata.h"
#include "QModelIndex"

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

        qDebug() << spaceList[i]->model()->rowCount();

        QJsonArray plots;

        auto *plotsModel = spaceList[i]->model();

        for (int j = 0; j < spaceList[i]->model()->rowCount(); j++){
            QJsonObject plot;
            auto plotIndex = plotsModel->index(j, 0);
            auto data = plotsModel->data(plotIndex, Analitza::PlotsModel::DescriptionRole);

            plot["expression"] = data.toString();
            //qDebug() << spaceList[i]->plots().at(j)->strExpression();*/
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

bool KhipuData::loadData(QString fileName)
{
    Q_UNUSED(fileName)
    return true;
}
