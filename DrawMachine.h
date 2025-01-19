#ifndef DRAWMACHINE_H
#define DRAWMACHINE_H

#include <map>
#include <string>
#include <vector>
#include <random>
#include <iostream>

class Prize; // 前向声明 Prize 类

class DrawMachine {
private:
    static std::map<std::string, double> TYPE_RATES; // 奖品类型及概率
    static std::vector<Prize> prizes;               // 奖品范围

    std::map<std::string, int> PRIZE_NUM;           // 抽取到的奖品统计
    std::mt19937 generator;                         // 随机数生成器
    std::uniform_real_distribution<> distribution;  // 随机数分布

    std::string insertPrize(const std::string& type); // 插入奖品到统计表

public:
    DrawMachine();  // 构造函数
    std::string draw(); // 抽取单个奖品
    std::vector<std::string> draw(int count); // 抽取指定数量的奖品
    int drawToComplete(); // 抽到所有奖品需要的次数
    bool hasAll(); // 返回是否收集到的所有
    bool print(); // 打印当前奖品统计表
};

#endif // DRAWMACHINE_H
