#include "khipuspacemodel.h"

#include "khipudata.h"

#include <QDebug>

KhipuSpaceModel::KhipuSpaceModel(QObject *parent) :
    QAbstractListModel(parent),
    m_currentSpace(nullptr)
{
    qmlRegisterType<QAbstractItemModel>();
    qRegisterMetaType<QSharedPointer<Analitza::Variables>>("QSharedPointer<Analitza::Variables>");
}

void KhipuSpaceModel::addSpace(QString name, QString type)
{
    int dim = strCheckDim(type);
    beginInsertRows(QModelIndex(), m_spaceList.size(), m_spaceList.size());
    m_spaceList.append(new KhipuSpace(name, dim));
    endInsertRows();
}

bool KhipuSpaceModel::removeSpace(int row)
{
    if (m_spaceList.size()>1){
        beginRemoveRows(QModelIndex(), row, row);
        m_spaceList.removeAt(row);
        endRemoveRows();
        return true;
    }
    return false;
}

void KhipuSpaceModel::rename(int row, const QString &name)
{
    m_spaceList[row]->setName(name);
}

QString KhipuSpaceModel::getType(int row)
{
    return intCheckDim(m_spaceList[row]->type());
}

KhipuSpace* KhipuSpaceModel::spaceAt(int row)
{
    return m_spaceList.at(row);
}

void *KhipuSpaceModel::removeFunction(int row)
{
    m_currentSpace->model()->removeRow(row);
}

QString KhipuSpaceModel::functionFixing(QString str)
{
    if (str.contains("x") == false) {
        str = str + " + 0x";
    }
    if (str.contains("y") == false) {
        str = str + " + 0y";
    }
    return str;
}

void KhipuSpaceModel::save()
{
    KhipuData::saveData(m_spaceList,"testejson");
}

void KhipuSpaceModel::load(QString path)
{
    if (path.contains(".json")){
        QList<KhipuSpace*> newSpaces = KhipuData::loadData("testejson");
        beginInsertRows(QModelIndex(), m_spaceList.size(), m_spaceList.size() + newSpaces.size() - 1);
        m_spaceList.append(newSpaces);
        endInsertRows();
    }
}

void KhipuSpaceModel::plotDict()
{
    KhipuSpace* space2D = new KhipuSpace("2D Examples",Analitza::Dim2D);
    space2D->addPlot("y = x**2");
    space2D->addPlot("y = sin(x)");
    space2D->addPlot("x**2 + y**2 = 1");
    space2D->addPlot("x = 3 + 0y");
    space2D->addPlot("y = 3 + 0x");

    KhipuSpace* space3D = new KhipuSpace("3D Examples",Analitza::Dim3D);
    space3D->addPlot("x**2 + y**2 + z**2 = 1");
    space3D->addPlot("z = sin(xy)");
    space3D->addPlot("z = x**2 + 0y");
    space3D->addPlot("z = x**2 + y**2");

    addSpace(space2D);
    addSpace(space3D);

    if (m_spaceList.size() == 2)
        setCurrentSpace(spaceAt(0));
}

int KhipuSpaceModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_spaceList.size();
}

QVariant KhipuSpaceModel::data(const QModelIndex &index, int role) const
{
    switch(role){
        case Roles::NameRole:
            return m_spaceList[index.row()]->name();
        case Roles::TypeRole:
            return m_spaceList[index.row()]->strType();
    }
    return {};
}

QHash<int, QByteArray> KhipuSpaceModel::roleNames() const
{
    return {
        {Roles::NameRole, "name"},
        {Roles::TypeRole, "type"}
    };
}

KhipuSpace* KhipuSpaceModel::currentSpace() const {
    return m_currentSpace;
}

void KhipuSpaceModel::setCurrentSpace(KhipuSpace *space) {
    m_currentSpace = space;
    emit currentSpaceChanged(space);
}

int KhipuSpaceModel::strCheckDim(QString dim)
{
    if (dim == "2D")
        return Analitza::Dim2D;
    else if (dim == "3D")
        return Analitza::Dim3D;
}

QString KhipuSpaceModel::intCheckDim(int dim)
{
    if (dim == Analitza::Dim2D)
        return "2D";
    else if (dim == Analitza::Dim3D)
        return "3D";
}

void KhipuSpaceModel::addSpace(KhipuSpace *space)
{
    beginInsertRows(QModelIndex(), m_spaceList.size(), m_spaceList.size());
    m_spaceList.append(space);
    endInsertRows();
}
