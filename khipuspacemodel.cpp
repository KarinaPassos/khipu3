#include "khipuspacemodel.h"
#include <QDebug>

KhipuSpaceModel::KhipuSpaceModel(QObject *parent) :
    QAbstractListModel(parent)
{

}

void KhipuSpaceModel::addSpace(QString name, QString type, int index)
{
    beginInsertRows(QModelIndex(), m_spaceList.size(), m_spaceList.size());
    m_spaceList.append(KhipuSpace(name,type,index));
    endInsertRows();
}

bool KhipuSpaceModel::removeSpace(int row)
{
    if (isIndexValid(row)){
        beginRemoveRows(QModelIndex(), m_spaceList.size(), m_spaceList.size());
        m_spaceList.removeAt(row);
        endRemoveRows();
        return true;
    } else { return false; }
}

void KhipuSpaceModel::rename(int row, const QString &name)
{
    if (isIndexValid(row))
        m_spaceList[row].name() = name;
}

int KhipuSpaceModel::rowCount(const QModelIndex &parent) const
{
    return m_spaceList.size();
}

QVariant KhipuSpaceModel::data(const QModelIndex &index, int role) const
{
    switch(role){
        case Roles::IdRole:
            return m_spaceList[index.row()].id();
        case Roles::NameRole:
            return m_spaceList[index.row()].name();
        case Roles::TypeRole:
            return m_spaceList[index.row()].type();
    }
}

QHash<int, QByteArray> KhipuSpaceModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::IdRole] = "id";
    roles[Roles::NameRole] = "name";
    roles[Roles::TypeRole] = "type";
    return roles;
}

bool KhipuSpaceModel::isIndexValid(int id) const
{
    if (id >= 0 && id < m_spaceList.size())
        return true;
    else
        return false;
}
