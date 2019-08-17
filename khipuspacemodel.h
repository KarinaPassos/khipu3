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

    Q_INVOKABLE KhipuSpace *addSpace(QString name, QString type); //creates a new space
    Q_INVOKABLE bool removeSpace(int row); //removes spaces of the list
    Q_INVOKABLE void rename(const QString& name, const int row); //renames current space
    Q_INVOKABLE QString getType(int row) const; //returns current space type
    Q_INVOKABLE KhipuSpace *spaceAt(int row) const; //returns the space at the given position
    Q_INVOKABLE void *removeFunction(int row); //removes a function
    Q_INVOKABLE QString functionFixing(QString str) const; //corrects the input to fix plotting errors of functions like z=x**2
    Q_INVOKABLE void save(QString name) const; //saves the current spacelist in a json file
    Q_INVOKABLE void load(QString path); //loads a given file
    Q_INVOKABLE void plotDict(); //creates two spaces with examples to the user
    Q_INVOKABLE void searchSpace(QString text); //function to be used by the search bar

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    KhipuSpace *currentSpace() const;
    void setCurrentSpace(KhipuSpace *space);

signals:
    void currentSpaceChanged(KhipuSpace *space);

private:
    int strCheckDim(QString dim) const; //converts the type from str to int to be easier to use in c++
    QString intCheckDim(int dim) const; //converts the type from int to str to be easier to use in qml
    void addSpace(KhipuSpace* space); //creates a new space
    QList<KhipuSpace*> m_spaceList;
    QList<KhipuSpace*> searchResult;
    KhipuSpace *m_currentSpace = nullptr;
};

#endif // KHIPUSPACEMODEL_H
