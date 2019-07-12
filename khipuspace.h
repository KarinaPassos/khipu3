#ifndef KHIPUSPACE_H
#define KHIPUSPACE_H
#include <QVector>
#include <QString>

class KhipuSpace
{
public:
    KhipuSpace(QString name, QString type, int index);

    int id() const;
    void setId(int Id);

    QString name() const;
    void setName(const QString &name);

    QString type() const;
    void setType(const QString &type);

    QVector<QString> elements() const;
    void addElement(QString expression);
    void editElement(QString expression, int index);
    void removeElement(int index);

private:
    int m_id;
    QString m_name;
    QString m_type;
    QVector<QString> m_elements;
};

#endif // KHIPUSPACE_H
