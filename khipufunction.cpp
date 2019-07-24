#include "khipufunction.h"

using namespace Analitza;

KhipuFunction* KhipuFunction::s_self=nullptr;
KhipuFunction* KhipuFunction::self() { return s_self; }

Q_DECLARE_METATYPE(QSharedPointer<Analitza::Variables>)

KhipuFunction::KhipuFunction(QObject* parent)
    : QObject(parent), m_functionsModel(nullptr), m_vars(new Analitza::Variables)
{
    Q_ASSERT(s_self==nullptr);
    s_self=this;

    /*const auto uri = "org.kde.kalgebra.mobile";
    qmlRegisterType<PluginsModel>("org.kde.kalgebra.mobile", 1, 0, "PluginsModel");
    qmlRegisterType<ConsoleModel>("org.kde.kalgebra.mobile", 1, 0, "ConsoleModel");
    qmlRegisterType<Clipboard>(uri, 1, 0, "Clipboard");*/
    qmlRegisterType<QSortFilterProxyModel>("org.kde.kalgebra.mobile", 1, 0, "QSortFilterProxyModel");
    qmlRegisterType<QAbstractItemModel>();
    qmlRegisterUncreatableType<Analitza::Expression>("org.kde.kalgebra.mobile", 1, 0, "Expression", QStringLiteral("because"));
    qRegisterMetaType<QSharedPointer<Analitza::Variables>>("QSharedPointer<Analitza::Variables>");
}

PlotsModel* KhipuFunction::functionsModel()
{
    if(!m_functionsModel) {
        m_functionsModel = new Analitza::PlotsModel(this);
        connect(m_functionsModel, &QAbstractItemModel::rowsRemoved, this, &KhipuFunction::functionRemoved);
        connect(m_functionsModel, &QAbstractItemModel::dataChanged, this, &KhipuFunction::functionModified);
        connect(m_functionsModel, &QAbstractItemModel::rowsInserted, this, &KhipuFunction::functionInserted);
    }

    return m_functionsModel;
}

void KhipuFunction::functionRemoved(const QModelIndex& parent, int start, int end)
{
    Q_ASSERT(!parent.isValid());
    for(int i=start; i<=end; i++) {
        QModelIndex idx = functionsModel()->index(i);
        m_vars->remove(functionsModel()->data(idx, Qt::DisplayRole).toString());
    }
}

void KhipuFunction::functionModified(const QModelIndex& idxA, const QModelIndex& idxB)
{
    if(idxB.column()==1) {
        for(int i=idxA.row(); i<idxB.row(); ++i) {
            QModelIndex idx = functionsModel()->index(i, 1);
            m_vars->modify(idx.sibling(i,0).data().toString(), Analitza::Expression(idx.data().toString()));
        }
    }
}


void KhipuFunction::functionInserted(const QModelIndex& parent, int start, int end)
{
    Q_ASSERT(!parent.isValid());
    for(int i=start; i<=end; i++) {
        QModelIndex idx = functionsModel()->index(i, 1);
        m_vars->modify(idx.sibling(i,0).data().toString(), Analitza::Expression(idx.data().toString()));
    }
}


QSharedPointer<Variables> KhipuFunction::variables() const
{
    return m_vars;
}
