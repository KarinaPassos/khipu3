#ifndef KHIPUSPACEMODEL_H
#define KHIPUSPACEMODEL_H
#include <Analitza5/analitzaplot/plotsmodel.h>
#include <QSortFilterProxyModel>
#include <QAbstractListModel>
#include <QHash>
#include <qqml.h>
#include <khipuspace.h>
#include <QList>
#include <QColor>

class KhipuSpaceModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(KhipuSpace* currentSpace READ currentSpace WRITE setCurrentSpace NOTIFY currentSpaceChanged)
    Q_PROPERTY(QSortFilterProxyModel *filterModel MEMBER m_filterModel)

public:
    enum Roles {
        NameRole = Qt::UserRole + 1,
        TypeRole
    };

    KhipuSpaceModel(QObject *parent = nullptr);

    Q_INVOKABLE KhipuSpace *addSpace(const QString& name, const QString& type); //creates a new space
    Q_INVOKABLE bool removeSpace(const int row); //removes spaces of the list
    Q_INVOKABLE void rename(const QString& name, const int row); //renames current space
    Q_INVOKABLE QString getType(const int row) const; //returns current space type
    Q_INVOKABLE KhipuSpace *spaceAt(const int row) const; //returns the space at the given position
    Q_INVOKABLE void removeFunction(const int row); //removes a function
    Q_INVOKABLE QString functionFixing(QString str) const; //corrects the input to fix plotting errors of functions like z=x**2
    Q_INVOKABLE void save(const QString& name) const; //saves the current spacelist in a json file
    Q_INVOKABLE void load(const QString& path); //loads a given file
    Q_INVOKABLE void plotDict(); //creates two spaces with examples to the user
    Q_INVOKABLE int getPlotCurrentIndex() const;
    Q_INVOKABLE void setPlotCurrentIndex(const int value);
    Q_INVOKABLE void setVisibility(const bool visibility);
    Q_INVOKABLE void setExpression(const QString& expression);
    Q_INVOKABLE void setColor(const QColor& color);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    KhipuSpace *currentSpace() const;
    void setCurrentSpace(KhipuSpace *space);

signals:
    void currentSpaceChanged(KhipuSpace *space);

private:
    int strCheckDim(const QString& dim) const; //converts the type from str to int to be easier to use in c++
    QString intCheckDim(const int& dim) const; //converts the type from int to str to be easier to use in qml
    void addSpace(KhipuSpace* space); //creates a new space
    QList<KhipuSpace*> m_spaceList;
    KhipuSpace *m_currentSpace = nullptr;
    int plotCurrentIndex = 0;
    QSortFilterProxyModel *m_filterModel;
};

#endif // KHIPUSPACEMODEL_H
