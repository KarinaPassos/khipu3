#include "khipuspace.h"
#include <Analitza5/analitza/expression.h>
#include <Analitza5/analitzaplot/plotsmodel.h>
#include <Analitza5/analitza/variables.h>

KhipuSpace::KhipuSpace()
{
}

KhipuSpace::KhipuSpace(const QString& name, const QString& type) :
    m_name(name),
    m_type(type),
    m_vars(new Analitza::Variables)
{
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
    if (m_type == "2D"){
        m_model->addFunction(expression, Analitza::Dim2D, m_vars);
    }
    else if (m_type == "3D"){
        m_model->addFunction(expression, Analitza::Dim3D, m_vars);
    }
}

Analitza::PlotsModel *KhipuSpace::model()
{
    return m_model;
}

QSharedPointer<Analitza::Variables> KhipuSpace::variables() const
{
    return m_vars;
}