#include "khipuspacemodel.h"
#include "khipudata.h"
#include <QDebug>
#include <QFileDialog>

KhipuSpaceModel::KhipuSpaceModel(QObject *parent) :
    QAbstractListModel(parent),
    m_currentSpace(nullptr)
{
    qmlRegisterType<QAbstractItemModel>();
    qRegisterMetaType<QSharedPointer<Analitza::Variables>>("QSharedPointer<Analitza::Variables>");
}

KhipuSpace* KhipuSpaceModel::addSpace(const QString& name, const QString& type)
{
    int dim = strCheckDim(type);
    auto space = new KhipuSpace(name, dim);
    beginInsertRows(QModelIndex(), m_spaceList.size(), m_spaceList.size());
    m_spaceList.append(space);
    endInsertRows();
    return space;
}

bool KhipuSpaceModel::removeSpace(const int& row)
{
    if (m_spaceList.size()>1){
        beginRemoveRows(QModelIndex(), row, row);
        m_spaceList.removeAt(row);
        endRemoveRows();
        return true;
    }
    return false;
}

void KhipuSpaceModel::rename(const QString& name, const int& row)
{
    currentSpace()->setName(name);
    dataChanged(index(0),index(row));
}

QString KhipuSpaceModel::getType(const int& row) const
{
    return intCheckDim(m_spaceList[row]->type());
}

KhipuSpace* KhipuSpaceModel::spaceAt(const int& row) const
{
    return m_spaceList.at(row);
}

void KhipuSpaceModel::removeFunction(const int& row)
{
    m_currentSpace->model()->removeRow(row);
}

QString KhipuSpaceModel::functionFixing(QString str) const
{
    if (m_currentSpace->type() == Analitza::Dim3D) {
        if ((str.contains("x") == false || str.contains("y") == false)
                && str.contains("z") == false && str.contains("=")) {
            str = str + " + 0z";
        }
    }
    if (str.contains("x") == false && str.contains("=") == true) {
        str = str + " + 0x";
    }
    if (str.contains("y") == false && str.contains("=") == true) {
        str = str + " + 0y";
    }
    return str;
}

void KhipuSpaceModel::save(const QString& name) const
{
    KhipuData::saveData(m_spaceList,name);
}

void KhipuSpaceModel::load(const QString& path)
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

    if (m_spaceList.size() == 2){
        setCurrentSpace(spaceAt(0));
    }
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

int KhipuSpaceModel::strCheckDim(const QString& dim) const
{
    if (dim == "2D"){
        return Analitza::Dim2D;
    }
    else if (dim == "3D"){
        return Analitza::Dim3D;
    }
    return -1;
}

QString KhipuSpaceModel::intCheckDim(const int& dim) const
{
    if (dim == Analitza::Dim2D){
        return "2D";
    }
    else if (dim == Analitza::Dim3D){
        return "3D";
    }
    return "";
}

void KhipuSpaceModel::addSpace(KhipuSpace *space)
{
    beginInsertRows(QModelIndex(), m_spaceList.size(), m_spaceList.size());
    m_spaceList.append(space);
    endInsertRows();
}

int KhipuSpaceModel::getPlotCurrentIndex() const
{
    return plotCurrentIndex;
}

void KhipuSpaceModel::setPlotCurrentIndex(const int& value)
{
    plotCurrentIndex = value;
}

void KhipuSpaceModel::setVisibility(const bool& visibility)
{
    m_currentSpace->model()->setData(index(plotCurrentIndex), visibility, Qt::CheckStateRole);
}

void KhipuSpaceModel::setExpression(const QString& expression)
{
    m_currentSpace->model()->setData(index(plotCurrentIndex), expression, Qt::EditRole);
    qDebug() << m_currentSpace->model()->data(index(plotCurrentIndex-1));
}

void KhipuSpaceModel::setColor(const QColor& color)
{
    m_currentSpace->model()->setData(index(plotCurrentIndex), color, Qt::DecorationRole);
}
