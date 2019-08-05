#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <khipuspacemodel.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    KhipuSpaceModel spaceModel;
    KhipuSpaceModel plotDict;

    //spaceModel.load();

    QQmlApplicationEngine engine;

    qmlRegisterType<KhipuSpace>();
    qmlRegisterType<KhipuPlot>();

    plotDict.addSpace("2D examples","2D");
    plotDict.addSpace("3D examples","3D");

    engine.rootContext()->setContextProperty("khipuModel", &spaceModel);
    engine.rootContext()->setContextProperty("dictModel", &plotDict);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
