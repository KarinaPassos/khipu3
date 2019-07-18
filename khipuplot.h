#ifndef KHIPUPLOT_H
#define KHIPUPLOT_H
#include <QString>
#include <QObject>
#include <Analitza5/analitza/expression.h>

class KhipuPlot : public QObject
{
    Q_OBJECT

public:
    KhipuPlot();
    KhipuPlot(Analitza::Expression expression);

    Analitza::Expression expression();
    QString strExpression() const;

    void setExpression(const QString &value);

    int id() const;

private:
    Analitza::Expression m_expression;
    int m_id;
};

#endif // KHIPUPLOTS_H
