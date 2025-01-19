#include "DrawMachine.h"
#include "Prize.h" // ���� Prize �ඨ��

// ��ʼ����̬��Ա����
std::map<std::string, double> DrawMachine::TYPE_RATES = {
    {"Ť����", 0.405},
    {"����ͷ��", 0.075},
    {"����ͷ���", 0.075},
    {"����ͷ����", 0.075},
    {"�����ƣ����飩", 0.075},
    {"����Զ�ŵذ���", 0.025},
    {"������ɡ�����", 0.025},
    {"��������", 0.025},
    {"��������ëë", 0.025},
    {"����ȭ��̩��", 0.025},
    {"����񶷰ű�", 0.025},
    {"���������", 0.025},
    {"��������³˹", 0.025},
    {"����ͷ��˹�", 0.025},
    {"���꺣������", 0.025},
    {"����ɹٿ�����", 0.02},
    {"����ɹ�̩��", 0.02},
    {"�������ֱ���", 0.005}
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

