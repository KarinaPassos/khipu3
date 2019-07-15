#include "khipuplot.h"

KhipuPlot::KhipuPlot()
{
}

KhipuPlot::KhipuPlot(QString expression, int spaceID):
m_expression(expression),
m_spaceID(spaceID)
{
}

QString KhipuPlot::expression() const
{
    return m_expression;
}

void KhipuPlot::setExpression(const QString &expression)
{
    m_expression = expression;
}

int KhipuPlot::spaceID() const
{
    return m_spaceID;
}

int KhipuPlot::id() const
{
    return m_id;
}
