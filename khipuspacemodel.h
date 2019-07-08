#ifndef KHIPUSPACEMODEL_H
#define KHIPUSPACEMODEL_H

#include <QAbstractListModel>
#include <QHash>
#include <khipuspace.h>
#include <QList>

class KhipuSpaceModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        TypeRole
    };

    KhipuSpaceModel(QObject *parent = nullptr);

    QModelIndex addSpace(const KhipuSpace& space);
    Q_INVOKABLE void rename(int row, const QString& name);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    Q_INVOKABLE bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;
    QHash<int, QByteArray> roleNames() const override;

private:
    bool isIndexValid(const QModelIndex& index) const;

    QList<KhipuSpace> m_spaceList;
};

#endif // KHIPUSPACEMODEL_H
