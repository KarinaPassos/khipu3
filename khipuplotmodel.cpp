#include "khipuplotmodel.h"

KhipuPlotModel::KhipuPlotModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

void KhipuPlotModel::addPlot(QString expression, int spaceID)
{
    beginInsertRows(QModelIndex(), m_plotList.size(), m_plotList.size());
    m_plotList.append(new KhipuPlot(expression,spaceID));
    endInsertRows();
}

void KhipuPlotModel::setPlot(QString expression, int row)
{
    m_plotList[row]->setExpression(expression);
}

bool KhipuPlotModel::removePlot(int row)
{
    beginRemoveRows(QModelIndex(), row, row);
    m_plotList.removeAt(row);
    endRemoveRows();
    return true;
}

int KhipuPlotModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_plotList.size();
}

QVariant KhipuPlotModel::data(const QModelIndex &index, int role) const
{
    switch(role){
        case PlotRoles::ExpressionRole:
            return m_plotList[index.row()]->expression();
        case PlotRoles::SpaceIdRole:
            return m_plotList[index.row()]->spaceID();
        case PlotRoles::IdRole:
            return m_plotList[index.row()]->id();
    }
    return {};
}

QHash<int, QByteArray> KhipuPlotModel::roleNames() const
{
    return {
        {PlotRoles::ExpressionRole, "expression"},
        {PlotRoles::SpaceIdRole, "spaceID"},
        {PlotRoles::IdRole, "id"}
    };
}

QList<KhipuPlot *> KhipuPlotModel::plotList() const
{
    return m_plotList;
}

void KhipuPlotModel::setSpace(KhipuSpace *space)
{
    beginResetModel();
    m_currentSpace = space;
    m_plotList = m_currentSpace->plots();
    endResetModel();
}