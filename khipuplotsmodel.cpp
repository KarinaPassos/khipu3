#include "khipuplotsmodel.h"

KhipuPlotsModel::KhipuPlotsModel()
{

}

void KhipuPlotsModel::setVisibility(int row, const bool visibility)
{
    setData(index(row), visibility, Qt::CheckStateRole);
}

void KhipuPlotsModel::setExpression(int row, const QString& expression)
{
    setData(index(row), expression, Qt::EditRole);
}

void KhipuPlotsModel::setColor(int row, const QColor& color)
{
    //setData(index(row), color, Qt::DecorationRole);
}
