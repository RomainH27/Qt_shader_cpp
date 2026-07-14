#include "scan.hpp"

void ScanObject::ComputeData() {
  for (int i = 0; i < 1000; i++) {
    std::array<float, kScanSize> row;

    for (int j = 0; j < kScanSize; j++) {
      row[j] = static_cast<float>(j) / static_cast<float>(kScanSize);
    }

    m_scan_data.emplace_back();
  }
}

std::vector<std::array<float, ScanObject::kScanSize>> ScanObject::GetData() {
  return m_scan_data;
}

float ScanObject::GetTest() { return m_test; }

void ScanObject::SetTest(float test_val) {
  m_test = test_val;
  emit valueChanged();
}

float ScanObject::GetRatio() {
  return (static_cast<float>(kScanSize) /
          static_cast<float>(m_scan_data.size()));
}

QPixmap ColorImageProvider::requestPixmap(const QString &id, QSize *size,
                                          const QSize &requestedSize) {
  const int defaultW = 10, defaultH = 10;

  QColor color(id);
  if (!color.isValid())
    color = Qt::magenta;

  QSize targetSize = (requestedSize.width() > 0 && requestedSize.height() > 0)
                         ? requestedSize
                         : QSize(defaultW, defaultH);

  if (size)
    *size = targetSize;

  QPixmap pixmap(targetSize);

  pixmap.fill(color);
  return pixmap;
}