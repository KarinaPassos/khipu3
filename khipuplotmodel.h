#ifndef KHIPUPLOTMODEL_H
#define KHIPUPLOTMODEL_H
#include <QAbstractListModel>
#include <QHash>
#include <khipuplot.h>
#include <QList>
#include <khipuspace.h>

class KhipuPlotModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum PlotRoles {
        ExpressionRole = Qt::UserRole + 1,
        SpaceIdRole,
        IdRole
    };

    KhipuPlotModel(QObject *parent = nullptr);

    Q_INVOKABLE void addPlot(QString expression, int spaceID);
    Q_INVOKABLE bool removePlot(QString expression, int row);
    Q_INVOKABLE void setPlot(QString expression, int row);
    Q_INVOKABLE void setPlotList(const KhipuSpace &currentSpace);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<KhipuPlot*> m_plotList;
};

#endif // KHIPUPLOTMODEL_H
