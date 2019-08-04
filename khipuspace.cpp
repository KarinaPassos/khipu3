#include "khipuspace.h"

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
    //m_model->addFunction(expression,,m_vars);
}

/*QList<KhipuPlot*> KhipuSpace::plots() const
{
    return m_model.;
}*/

Analitza::PlotsModel *KhipuSpace::model()
{
    return m_model;
}