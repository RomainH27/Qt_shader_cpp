#pragma once

#include <vector>
#include <QObject>

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