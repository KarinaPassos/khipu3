#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <khipuspacemodel.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    KhipuSpaceModel model;
    model.addSpace(KhipuSpace("space 1", "2D", 0));
    model.addSpace(KhipuSpace("space 2", "2D", 1));
    model.addSpace(KhipuSpace("space 3", "3D", 2));
    model.addSpace(KhipuSpace("robson", "2D", 3));

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("spaceModel2", &model);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
