#pragma once

#include <QObject>
#include <QPainter>
#include <QQuickImageProvider>
#include <iostream>
#include <vector>

class ScanObject : public QObject {
  Q_OBJECT

signals:
  void valueChanged();

public:
  static constexpr int kScanSize{2000};

  Q_PROPERTY(float test_val READ GetTest WRITE SetTest NOTIFY valueChanged)
  Q_PROPERTY(float ratio READ GetRatio)

  Q_INVOKABLE void ComputeData();
  Q_INVOKABLE std::vector<std::array<float, kScanSize>> GetData();

  float GetTest();
  void SetTest(float test_val);

  float GetRatio();

private:
  std::vector<std::array<float, kScanSize>> m_scan_data{};
  float m_test{0.0};
};

class ColorImageProvider : public QQuickImageProvider {

public:
  ColorImageProvider(ScanObject *scan)
      : QQuickImageProvider(QQuickImageProvider::Pixmap), m_scan(scan) {}

  QPixmap requestPixmap(const QString &id, QSize *size,
                        const QSize &requestedSize) override;

private:
  ScanObject *m_scan;
};