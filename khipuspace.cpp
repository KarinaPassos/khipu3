#include "khipuspace.h"

KhipuSpace::KhipuSpace(QString name, QString type, int index) :
    m_id(index),
    m_name(name),
    m_type(type)
{
}

int KhipuSpace::id() const
{
    return m_id;
}

void KhipuSpace::setId(int id)
{
    m_id = id;
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

QVector<QString> KhipuSpace::elements() const
{
    return m_elements;
}

void KhipuSpace::addElement(QString expression)
{
    m_elements.append(expression);
}

void KhipuSpace::editElement(QString expression, int index)
{
    m_elements[index] = expression;
}

void KhipuSpace::removeElement(int index)
{
    m_elements.removeAt(index);
}
