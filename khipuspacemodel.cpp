#include "khipuspacemodel.h"

KhipuSpaceModel::KhipuSpaceModel(QObject *parent) :
    QAbstractListModel(parent)
{

}

QModelIndex KhipuSpaceModel::addSpace(const KhipuSpace &space)
{
    m_spaceList.append(space);
}

void KhipuSpaceModel::rename(int row, const QString &name)
{
    if (isIndexValid(index(row)))
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

bool KhipuSpaceModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return false;
}

bool KhipuSpaceModel::removeRows(int row, int count, const QModelIndex &parent)
{
    return false;
}

QHash<int, QByteArray> KhipuSpaceModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::IdRole] = "id";
    roles[Roles::NameRole] = "name";
    roles[Roles::TypeRole] = "type";
    return roles;
}

bool KhipuSpaceModel::isIndexValid(const QModelIndex &index) const
{
    if (index.row() >= 0 && index.row() < m_spaceList.size())
        return true;
    else
        return false;
}
