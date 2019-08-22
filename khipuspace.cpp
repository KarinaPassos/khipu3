#include "khipuspace.h"
#include <Analitza5/analitza/expression.h>
#include <Analitza5/analitzaplot/plotsmodel.h>
#include <Analitza5/analitza/variables.h>

KhipuSpace::KhipuSpace()
{
}

KhipuSpace::KhipuSpace(const QString& name, const int type) :
    m_name(name),
    m_type(type),
    m_vars(new Analitza::Variables)
{
}

KhipuSpace::KhipuSpace(const QString &name, const int type, Analitza::PlotsModel *model) :
    m_name(name),
    m_type(type),
    m_model(model),
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

int KhipuSpace::type() const
{
    return m_type;
}

QString KhipuSpace::strType() const
{
    if (m_type == Analitza::Dim2D){
        return "2D";
    }
    else if (m_type == Analitza::Dim3D){
        return "3D";
    }
    return "";
}

void KhipuSpace::addPlot(const QString& expression)
{
    if (m_type == Analitza::Dim2D){
        m_model->addFunction(expression, Analitza::Dim2D, m_vars);
    }
    else if (m_type == Analitza::Dim3D){
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