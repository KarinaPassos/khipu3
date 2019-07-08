#ifndef KHIPUSPACE_H
#define KHIPUSPACE_H

#include <QString>

class KhipuSpace
{
public:
    KhipuSpace();

    int Id() const;
    void setId(int Id);

    QString name() const;
    void setName(const QString &name);

    QString type() const;
    void setType(const QString &type);

private:
    int m_Id;
    QString m_name;
    QString m_type;
};

#endif // KHIPUSPACE_H
