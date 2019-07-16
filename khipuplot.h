#ifndef KHIPUPLOT_H
#define KHIPUPLOT_H
#include <QString>
#include <QObject>

class KhipuPlot : public QObject
{
    Q_OBJECT

public:
    KhipuPlot();
    KhipuPlot(QString expression);
    KhipuPlot(QString expression, int spaceID);

    QString expression() const;
    void setExpression(const QString &value);

    int spaceID() const;

    int id() const;

private:
    QString m_expression;
    int m_spaceID;
    int m_id;
};

#endif // KHIPUPLOTS_H
