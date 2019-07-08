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

    Q_INVOKABLE void addSpace(QString name, QString type, int index);
    Q_INVOKABLE bool removeSpace(int row);
    Q_INVOKABLE void rename(int row, const QString& name);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    bool isIndexValid(int id) const;

    QList<KhipuSpace> m_spaceList;
};

#endif // KHIPUSPACEMODEL_H
