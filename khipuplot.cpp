#include "khipuplot.h"

KhipuPlot::KhipuPlot()
{
}

KhipuPlot::KhipuPlot(Analitza::Expression expression):
m_expression(expression)
{
}

Analitza::Expression KhipuPlot::expression()
{
    return m_expression;
}

QString KhipuPlot::strExpression() const
{
    return m_expression.toString();
}

void KhipuPlot::setExpression(const QString &expression)
{
    m_expression = Analitza::Expression(expression,false);
}

int KhipuPlot::id() const
{
    return m_id;
}
