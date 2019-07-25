#ifndef KHIPUFUNCTION_H
#define KHIPUFUNCTION_H
#include <Analitza5/analitzaplot/plotsmodel.h>
#include <Analitza5/analitza/variables.h>
#include <qobject.h>
#include <qsharedpointer.h>
#include <QSortFilterProxyModel>
#include <qqml.h>
#include <Analitza5/analitza/expression.h>

class QModelIndex;
namespace Analitza {
    class Variables;
    class PlotsModel;
}

class KhipuFunction : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QSharedPointer<Analitza::Variables> variables READ variables NOTIFY variablesChanged)
    public:
        explicit KhipuFunction(QObject* parent=nullptr);

        static KhipuFunction* self();
        void notifyVariablesChanged() { variablesChanged(); }
        Q_INVOKABLE QString functionFixing(QString str);

    public Q_SLOTS:
        Analitza::PlotsModel* functionsModel();
        QSharedPointer<Analitza::Variables> variables() const;

    private Q_SLOTS:
        void functionRemoved(const QModelIndex& parent, int start, int end);
        void functionModified(const QModelIndex& idxA, const QModelIndex& idxB);
        void functionInserted(const QModelIndex& parent, int start, int end);

    Q_SIGNALS:
        void variablesChanged();

    private:
        static KhipuFunction* s_self;

        Analitza::PlotsModel* m_functionsModel;
        QSharedPointer<Analitza::Variables> m_vars;
};

#endif // KHIPUFUNCTION_H
