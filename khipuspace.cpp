#include "khipuspace.h"

KhipuSpace::KhipuSpace()
{

}

int KhipuSpace::Id() const
{
    return m_Id;
}

void KhipuSpace::setId(int Id)
{
    m_Id = Id;
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

void KhipuSpace::setType(const QString &type)
{
    m_type = type;
}
