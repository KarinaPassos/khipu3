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
    beginInsertRows(QModelIndex(), m_spaceList.size(), m_spaceList.size());
    m_spaceList.append(new KhipuSpace(name, type));
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
    return m_spaceList[row]->type();
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
        str = str + " + 0*x";
    }
    if (str.contains("y") == false) {
        str = str + " + 0*y";
    }
    return str;
}

void KhipuSpaceModel::save()
{
    KhipuData::saveData(m_spaceList,"testejson");
}

void KhipuSpaceModel::load()
{
    QList<KhipuSpace*> newSpaces = KhipuData::loadData("testejson");
    qDebug() << "O arquivo continha " << newSpaces.size() << " espaços.";
    beginInsertRows(QModelIndex(), m_spaceList.size(), m_spaceList.size() + newSpaces.size() - 1);
    m_spaceList.append(newSpaces);
    endInsertRows();
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
            return m_spaceList[index.row()]->type();
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
