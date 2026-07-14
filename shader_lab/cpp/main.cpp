#include "scan.hpp"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QUrl>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QQmlApplicationEngine engine;

  qmlRegisterType<ScanObject>("hello", 1, 0, "ScanObject");

  ScanObject scan;

  engine.addImageProvider(QStringLiteral("scanProvider"),
                          new ColorImageProvider(&scan));

//   engine.rootContext()->setContextProperty("scanSettings", &scan);

  qmlRegisterSingletonInstance("hello", 1, 0, "ScanSettings", &scan);

  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
      []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

  engine.loadFromModule("hello", "Main");

  scan.ComputeData();

  return app.exec();
}