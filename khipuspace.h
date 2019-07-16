#ifndef KHIPUSPACE_H
#define KHIPUSPACE_H
#include <QList>
#include <QString>
#include <khipuplot.h>

class KhipuSpace : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString type READ type CONSTANT)

public:
    KhipuSpace(const QString& name, const QString& type, int index);

    int id() const;

    QString name() const;
    void setName(const QString &name);

    QString type() const;

    QList<KhipuPlot> elements() const;
    /*void addElement(QString expression);
    void editElement(QString expression, int index);
    void removeElement(int index);*/

signals:
    void nameChanged(const QString& name);

private:
    int m_id;
    QString m_name;
    QString m_type;
    QList<KhipuPlot> m_elements;
};

#endif // KHIPUSPACE_H
