#include "scan.hpp"

void ScanObject::ComputeData() {
  for (int i = 0; i < kTempRowNumber; i++) {
    std::array<float, kScanSize> row;

    for (int j = 0; j < kScanSize; j++) {
      row[j] = (static_cast<float>(j) / static_cast<float>(kScanSize)) +
               static_cast<float>(i) / static_cast<float>(kTempRowNumber);

      row[j] = std::clamp(row[j], 0.0f, 1.0f);
    }

    m_scan_data.emplace_back(row);
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

QPixmap ScanObject::ToPixmap() const {
  if (m_scan_data.empty())
    return QPixmap();

  const int height = static_cast<int>(m_scan_data.size());
  const int width = kScanSize;

  QImage image(width, height, QImage::Format_RGB32);

  for (int y = 0; y < height; ++y) {
    QRgb *scanLine = reinterpret_cast<QRgb *>(image.scanLine(y));
    const auto &row = m_scan_data[y];
    for (int x = 0; x < width; ++x) {
      float v = row[x];

      // simple blue->red gradient as an example colormap
      int r = static_cast<int>(v * 255.0f);
      int g = static_cast<int>(0.0);
      int b = static_cast<int>(0.0);

      scanLine[x] = qRgb(r, 0, b);
    }
  }

  return QPixmap::fromImage(image);
}

QPixmap ColorImageProvider::requestPixmap(const QString &id, QSize *size,
                                          const QSize &requestedSize) {

  QPixmap pixmap = m_scan->ToPixmap();

  if (size)
    *size = pixmap.size();

  if (requestedSize.isValid() && requestedSize.width() > 0 &&
      requestedSize.height() > 0)
    pixmap = pixmap.scaled(requestedSize, Qt::IgnoreAspectRatio,
                           Qt::SmoothTransformation);

  return pixmap;
}