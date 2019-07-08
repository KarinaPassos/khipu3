#ifndef KHIPUSPACE_H
#define KHIPUSPACE_H

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

private:
    int m_id;
    QString m_name;
    QString m_type;
};

#endif // KHIPUSPACE_H
