#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <startrequest.h>
#include <readalldata.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    StartRequest startRequest_object;
    qmlRegisterType<ReadAllData>("ReadAllData_class", 1, 0, "ReadAllData_item");
    qRegisterMetaType<satellitePositions>();
    QQmlContext* rootContex = engine.rootContext();
    rootContex->setContextProperty("Read_data", QVariant::fromValue(&startRequest_object.readAllData_object));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    startRequest_object.startRequest();
    return app.exec();
}
