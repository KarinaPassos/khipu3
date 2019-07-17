#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <khipuspacemodel.h>
#include <khipuplotmodel.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    KhipuSpaceModel spaceModel;
    KhipuPlotModel plotModel;

    QQmlApplicationEngine engine;

    qmlRegisterType<KhipuSpace>();
    qmlRegisterType<KhipuPlot>();

    engine.rootContext()->setContextProperty("khipuModel", &spaceModel);
    engine.rootContext()->setContextProperty("plotModel", &plotModel);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
