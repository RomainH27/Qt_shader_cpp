#pragma once

#include <vector>
#include <QObject>
#include <QQuickImageProvider>

class ScanObject : public QObject
{
    Q_OBJECT

signals:
    void valueChanged();

public:
    static constexpr int kScanSize{2000};

    Q_PROPERTY(float test_val READ GetTest WRITE SetTest NOTIFY valueChanged)

    Q_INVOKABLE void ComputeData();
    Q_INVOKABLE std::vector<std::array<float, kScanSize>> GetData();

    float GetTest();
    void SetTest(float test_val);

private:

    std::vector<std::array<float, kScanSize>> m_scan_data{};
    float m_test{0.0};
};


class ColorImageProvider : public QQuickImageProvider
{
public:
    ColorImageProvider()
               : QQuickImageProvider(QQuickImageProvider::Image)
    {
    }

   QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override
    {
        // 'id' is whatever comes after "image://myprovider/"
        // e.g. for "image://myprovider/foo/bar", id == "foo/bar"

        QImage image(256, 256, QImage::Format_ARGB32_Premultiplied);
        image.fill(Qt::magenta); // obvious "missing image" placeholder

        if (size)
            *size = image.size();

        if (requestedSize.width() > 0 && requestedSize.height() > 0)
            image = image.scaled(requestedSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

        return image;
    }
};