#pragma once

#include <iostream>
#include <vector>
#include <QObject>
#include <QQuickImageProvider>
#include <QPainter>

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
               : QQuickImageProvider(QQuickImageProvider::Pixmap)
    {
    }

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override
    {
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

};