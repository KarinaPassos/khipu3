#include "khipuspace.h"

#include <Analitza5/analitza/expression.h>
#include <Analitza5/analitzaplot/plotsmodel.h>
#include <Analitza5/analitza/variables.h>

KhipuSpace::KhipuSpace()
{
}

KhipuSpace::KhipuSpace(const QString& name, const QString& type, int index) :
    m_id(index),
    m_name(name),
    m_type(type)
{
}

int KhipuSpace::id() const
{
    return m_id;
}

QString KhipuSpace::name() const
{
    return m_name;
}

void KhipuSpace::setName(const QString &name)
{
    m_name = name;
}

QString KhipuSpace::type() const
{
    return m_type;
}

void KhipuSpace::addPlot(QString expression)
{
    /** FIXME: Isso aqui está completamente errado. Foi criado apenas para teste.
     *
     * Eu não deveria criar um Analitza::Variables, pois ele já existe no KhipuSpaceModel */
    const QSharedPointer<Analitza::Variables> vars(new Analitza::Variables);
    m_model->addFunction(expression, Analitza::Dim2D, vars);
}

/*QList<KhipuPlot*> KhipuSpace::plots() const
{
    return m_model.;
}*/

Analitza::PlotsModel *KhipuSpace::model()
{
    return m_model;
}