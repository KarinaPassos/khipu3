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

QList<KhipuPlot*> KhipuSpace::plots() const
{
    return m_plots;
}

void KhipuSpace::addPlots(QString expression)
{
    m_plots.append(new KhipuPlot(expression));
}

/*void KhipuSpace::editPlots(QString expression, int index)
{
    m_plots[index] = KhipuPlot(expression);
}

void KhipuSpace::removePlots(int index)
{
    m_plots.removeAt(index);
}*/
