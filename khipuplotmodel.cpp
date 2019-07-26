#include "khipuplotmodel.h"
#include "qdebug.h"

KhipuPlotModel::KhipuPlotModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

void KhipuPlotModel::addPlot(QString expression)
{
    beginInsertRows(QModelIndex(), m_plotList.size(), m_plotList.size());
    m_plotList.append(new KhipuPlot(Analitza::Expression(expression,false)));
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
            return m_plotList[index.row()]->strExpression();
        case PlotRoles::IdRole:
            return m_plotList[index.row()]->id();
    }
    return {};
}

QHash<int, QByteArray> KhipuPlotModel::roleNames() const
{
    return {
        {PlotRoles::ExpressionRole, "expression"},
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
    qDebug() << "oi";
}