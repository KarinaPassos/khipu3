#ifndef KHIPUSPACE_H
#define KHIPUSPACE_H
#include <QList>
#include <QString>
#include <Analitza5/analitzaplot/plotsmodel.h>
#include <Analitza5/analitza/variables.h>
#include <QSharedPointer>

class KhipuSpace : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString type READ strType CONSTANT)
    Q_PROPERTY(QSharedPointer<Analitza::Variables> variables READ variables NOTIFY variablesChanged)

public:
    KhipuSpace();
    KhipuSpace(const QString& name, const int type);
    KhipuSpace(const QString& name, const int type, Analitza::PlotsModel* model);

    QString name() const;
    void setName(const QString &name);

    int type() const;
    QString strType() const;

    Q_INVOKABLE void addPlot(QString expression);

    Q_INVOKABLE QSharedPointer<Analitza::Variables> variables() const;
    void notifyVariablesChanged() { variablesChanged(); }

public Q_SLOTS:
    Analitza::PlotsModel* model();

signals:
    void nameChanged(const QString& name);
Q_SIGNALS:
    void variablesChanged();

private:
    QString m_name;
    int m_type;
    Analitza::PlotsModel* m_model = new Analitza::PlotsModel();
    QSharedPointer<Analitza::Variables> m_vars;
};

#endif // KHIPUSPACE_H
