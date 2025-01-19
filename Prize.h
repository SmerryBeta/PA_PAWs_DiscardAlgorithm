#ifndef PRIZE_H
#define PRIZE_H

#include <string>

class Prize {
private:
    double begin;
    double end;
    std::string type;

public:
    // 构造函数
    Prize(double begin, double end, const std::string& type);

    /**
     * 遵守左闭右开区间
     * */
    bool isThat(double num) const;

    // 获取 type
    std::string getType() const;
};

#endif // PRIZE_H
