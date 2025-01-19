#include "DrawMachine.h"
#include "Prize.h" // 包含 Prize 类定义

// 初始化静态成员变量
std::map<std::string, double> DrawMachine::TYPE_RATES = {
    {"扭蛋币", 0.405},
    {"闪魂头像", 0.075},
    {"闪魂头像框", 0.075},
    {"闪魂头名牌", 0.075},
    {"来打牌（表情）", 0.075},
    {"闪魂远古地包天", 0.025},
    {"闪魂雨伞玛奇朵", 0.025},
    {"闪魂玉兔", 0.025},
    {"闪魂雨衣毛毛", 0.025},
    {"闪魂拳王泰哥", 0.025},
    {"闪魂格斗芭比", 0.025},
    {"闪魂救世主", 0.025},
    {"闪魂篮球布鲁斯", 0.025},
    {"闪魂和服八公", 0.025},
    {"闪魂海盗豆豆", 0.025},
    {"闪魂荷官卡罗特", 0.02},
    {"闪魂荷官泰哥", 0.02},
    {"闪魂牌手宝珀", 0.005}
};

std::vector<Prize> DrawMachine::prizes;

DrawMachine::DrawMachine()
    : generator(std::random_device{}()), distribution(0.0, 1.0) {
    double begin = 0.0;
    for (const auto& pair : TYPE_RATES) {
        const std::string& key = pair.first;
        double rate = pair.second;
        prizes.emplace_back(begin, begin + rate, key);
        begin += rate;
    }
}


std::string DrawMachine::draw() {
    double randomValue = distribution(generator);
    for (const auto& prize : prizes) 
        if (prize.isThat(randomValue)) 
            return insertPrize(prize.getType());
    return {};
}

std::vector<std::string> DrawMachine::draw(int count) {
    std::vector<std::string> result;
    for (int i = 0; i < count; ++i) 
        result.push_back(draw());

    return result;
}

int DrawMachine::drawToComplete() {
    int sum = 10;
    draw(10);
    while (PRIZE_NUM.size() < TYPE_RATES.size()) {
        draw();
        ++sum;
    }
    return sum;
}

std::string DrawMachine::insertPrize(const std::string& type) {
    PRIZE_NUM[type]++;
    return type;
}

bool DrawMachine::hasAll() {
    return PRIZE_NUM.size() == TYPE_RATES.size();
}

bool DrawMachine::print() {
    for (const auto& pair : PRIZE_NUM) {
        const std::string& key = pair.first;
        int count = pair.second;
        std::cout << key << ": " << count << "\n";
    }
    return hasAll();
}

