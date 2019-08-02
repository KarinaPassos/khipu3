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

    QJsonObject spaces;
    for (int i = 0; i < spaceList.size(); i++){
        QJsonObject space;
        space["name"] = spaceList[i]->name();
        space["id"] = spaceList[i]->id();
        space["type"] = spaceList[i]->type();

        qDebug() << spaceList[i]->model()->rowCount();

        QJsonObject plots;
        for (int j = 0; j < spaceList[i]->model()->rowCount(); j++){
            QJsonObject plot;
            //plot["expression"] = spaceList[i]->model()->data(QModelIndex(), Analitza::PlotsModel::DescriptionRole);
            //qDebug() << spaceList[i]->plots().at(j)->strExpression();*/
            plots.insert(QString::number(j),plot);
        }
        space["plots"] = plots;

        spaces.insert(QString::number(i),space);
    }

    QJsonDocument doc(spaces);
    file.write(doc.toJson());
    file.close();

    return true;
}

bool KhipuData::loadData(QString fileName)
{
    Q_UNUSED(fileName)
    return true;
}
