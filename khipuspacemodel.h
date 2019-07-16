#ifndef KHIPUSPACEMODEL_H
#define KHIPUSPACEMODEL_H
#include <QAbstractListModel>
#include <QHash>
#include <khipuspace.h>
#include <QList>

class KhipuSpaceModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(KhipuSpace* currentSpace READ currentSpace WRITE setCurrentSpace NOTIFY currentSpaceChanged)

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
    Q_INVOKABLE KhipuSpace *spaceAt(int row);
    Q_INVOKABLE void addPlots(QString expression, int row);
    /*Q_INVOKABLE void editPlots(QString expression, int row, int column);
    Q_INVOKABLE void removePlots(QString expression, int row, int column);*/


    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    KhipuSpace *currentSpace() const;
    void setCurrentSpace(KhipuSpace *space);

signals:
    void currentSpaceChanged(KhipuSpace *space);

private:
    bool isIndexValid(int id) const;
    int getAvailableIndex();
    QList<KhipuSpace*> m_spaceList;
    KhipuSpace *m_currentSpace;
};

#endif // KHIPUSPACEMODEL_H
