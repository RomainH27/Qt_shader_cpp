#include <QApplication>
#include <QQmlApplicationEngine>
#include <QUrl>
#include "scan.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<ScanObject>("hello", 1, 0, "ScanObject");

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("hello", "Main");

    return app.exec();
}