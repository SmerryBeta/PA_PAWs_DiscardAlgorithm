#include "Prize.h"

// ���캯��ʵ��
Prize::Prize(double begin, double end, const std::string& type)
    : begin(begin), end(end), type(type) {}

// ��������ҿ�������ж�
bool Prize::isThat(double num) const {
    return num >= begin && num < end;
}

// ��ȡ type �ַ���
std::string Prize::getType() const {
    return type;
}
