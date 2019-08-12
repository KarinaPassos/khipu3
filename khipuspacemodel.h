#ifndef KHIPUSPACEMODEL_H
#define KHIPUSPACEMODEL_H
#include <Analitza5/analitzaplot/plotsmodel.h>
#include <QAbstractListModel>
#include <QHash>
#include <qqml.h>
#include <khipuspace.h>
#include <QList>

class KhipuSpaceModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(KhipuSpace* currentSpace READ currentSpace WRITE setCurrentSpace NOTIFY currentSpaceChanged)

public:
    enum Roles {
        NameRole = Qt::UserRole + 1,
        TypeRole
    };

    KhipuSpaceModel(QObject *parent = nullptr);

    Q_INVOKABLE void addSpace(QString name, QString type);
    Q_INVOKABLE bool removeSpace(int row);
    Q_INVOKABLE void rename(int row, const QString& name);
    Q_INVOKABLE QString getType(int row);
    Q_INVOKABLE KhipuSpace *spaceAt(int row);
    Q_INVOKABLE void *removeFunction(int row);
    Q_INVOKABLE QString functionFixing(QString str);
    Q_INVOKABLE void save(QString name);
    Q_INVOKABLE void load(QString path);
    Q_INVOKABLE void plotDict();

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    KhipuSpace *currentSpace() const;
    void setCurrentSpace(KhipuSpace *space);

signals:
    void currentSpaceChanged(KhipuSpace *space);

private:
    int strCheckDim(QString dim);
    QString intCheckDim(int dim);
    void addSpace(KhipuSpace* space);
    QList<KhipuSpace*> m_spaceList;
    KhipuSpace *m_currentSpace = nullptr;
};

#endif // KHIPUSPACEMODEL_H
