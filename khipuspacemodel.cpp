#include "khipuspacemodel.h"
#include "qdebug.h"

KhipuSpaceModel::KhipuSpaceModel(QObject *parent) :
    QAbstractListModel(parent),
    m_currentSpace(nullptr),
    m_vars(new Analitza::Variables)
{
    qmlRegisterType<QAbstractItemModel>();
    qRegisterMetaType<QSharedPointer<Analitza::Variables>>("QSharedPointer<Analitza::Variables>");
}

void KhipuSpaceModel::addSpace(QString name, QString type)
{
    beginInsertRows(QModelIndex(), m_spaceList.size(), m_spaceList.size());
    m_spaceList.append(new KhipuSpace(name, type, getAvailableIndex()));
    endInsertRows();
}

bool KhipuSpaceModel::removeSpace(int row)
{
    if (isIndexValid(row) && m_spaceList.size()>1){
        beginRemoveRows(QModelIndex(), row, row);
        m_spaceList.removeAt(row);
        endRemoveRows();
        return true;
    }
    return false;
}

void KhipuSpaceModel::rename(int row, const QString &name)
{
    if (isIndexValid(row)) {
        m_spaceList[row]->setName(name);
    }
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

int KhipuSpaceModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_spaceList.size();
}

QVariant KhipuSpaceModel::data(const QModelIndex &index, int role) const
{
    switch(role){
        case Roles::IdRole:
            return m_spaceList[index.row()]->id();
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
        {Roles::IdRole, "id"},
        {Roles::NameRole, "name"},
        {Roles::TypeRole, "type"}
    };
}

bool KhipuSpaceModel::isIndexValid(int id) const
{
    return (id >= 0 && id < m_spaceList.size());
}

KhipuSpace* KhipuSpaceModel::currentSpace() const {
    return m_currentSpace;
}

void KhipuSpaceModel::setCurrentSpace(KhipuSpace *space) {
    m_currentSpace = space;
    emit currentSpaceChanged(space);
}

int KhipuSpaceModel::getAvailableIndex()
{
    for(int i=0;;i++){
        int count = 0;
        for(int j=0;j<m_spaceList.size();j++){
            if (m_spaceList[j]->id() == i)
                count++;
        }
        if (count == 0){
            return i;
        }
    }
}

QSharedPointer<Analitza::Variables> KhipuSpaceModel::variables() const
{
    return m_vars;
}
