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

    Q_INVOKABLE void addSpace(QString name, QString type);
    Q_INVOKABLE bool removeSpace(int row);
    Q_INVOKABLE void rename(int row, const QString& name);
    Q_INVOKABLE QString getType(int row);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    bool isIndexValid(int id) const;
    int getAvailableIndex();
    QList<KhipuSpace> m_spaceList;
};

#endif // KHIPUSPACEMODEL_H
