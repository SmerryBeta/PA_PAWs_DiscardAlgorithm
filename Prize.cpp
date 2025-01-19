#include "Prize.h"

// 构造函数实现
Prize::Prize(double begin, double end, const std::string& type)
    : begin(begin), end(end), type(type) {}

// 遵守左闭右开区间的判断
bool Prize::isThat(double num) const {
    return num >= begin && num < end;
}

// 获取 type 字符串
std::string Prize::getType() const {
    return type;
}
