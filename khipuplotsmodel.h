#ifndef KHIPUPLOTSMODEL_H
#define KHIPUPLOTSMODEL_H
#include "analitzaplot/plotsmodel.h"

class KhipuPlotsModel : public Analitza::PlotsModel
{
public:
    KhipuPlotsModel();
    Q_INVOKABLE void setVisibility(int row, const bool visibility);
    Q_INVOKABLE void setExpression(int row, const QString& expression);
    Q_INVOKABLE void setColor(int row, const QColor& color);
};

#endif // KHIPUPLOTSMODEL_H
