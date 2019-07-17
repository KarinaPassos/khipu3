#include "khipuplotmodel.h"

KhipuPlotModel::KhipuPlotModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

void KhipuPlotModel::addPlot(QString expression, int spaceID)
{
    m_plotList.append(new KhipuPlot(expression,spaceID));
}

bool KhipuPlotModel::removePlot(QString expression, int row)
{
    Q_UNUSED(expression)
    m_plotList.removeAt(row);
    return true;
}

void KhipuPlotModel::setPlot(QString expression, int row)
{
    m_plotList[row]->setExpression(expression);
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

void KhipuPlotModel::setPlotList(const KhipuSpace &currentSpace)
{
    m_plotList = currentSpace.plots();
}