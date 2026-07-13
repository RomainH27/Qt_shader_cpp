#include "scan.hpp"

void ScanObject::ComputeData(){
    for(int i =0; i<1000; i++){        
        m_scan_data.emplace_back(std::array<float, kScanSize>{1.0});
    }
}

std::vector<std::array<float, ScanObject::kScanSize>> ScanObject::GetData(){
    return m_scan_data;
}

float ScanObject::GetTest(){
    return m_test;
}

void ScanObject::SetTest(float test_val){
    m_test = test_val;
    emit valueChanged();
}