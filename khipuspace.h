#ifndef KHIPUSPACE_H
#define KHIPUSPACE_H
#include <QList>
#include <QString>
#include <khipuplot.h>
#include <Analitza5/analitzaplot/plotsmodel.h>

class KhipuSpace : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString type READ type CONSTANT)

public:
    KhipuSpace();
    KhipuSpace(const QString& name, const QString& type, int index);

    int id() const;

    QString name() const;
    void setName(const QString &name);

    QString type() const;

    Q_INVOKABLE QList<KhipuPlot*> plots() const;
    void addPlots(QString expression);

public Q_SLOTS:
    Analitza::PlotsModel* model();

signals:
    void nameChanged(const QString& name);

private:
    int m_id;
    QString m_name;
    QString m_type;
    QList<KhipuPlot*> m_plots;
    Analitza::PlotsModel* m_model = new Analitza::PlotsModel;

};

#endif // KHIPUSPACE_H
