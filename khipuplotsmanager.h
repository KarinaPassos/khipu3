#ifndef KHIPUPLOTSMANAGER_H
#define KHIPUPLOTSMANAGER_H
#include <QAbstractProxyModel>

class KhipuPlotsManager : public QAbstractProxyModel
{
public:
    KhipuPlotsManager();
    QModelIndex mapToSource(const QModelIndex &proxyIndex) const = 0;
    QModelIndex mapFromSource(const QModelIndex &sourceIndex) const = 0;
};

#endif // KHIPUPLOTSMANAGER_H
