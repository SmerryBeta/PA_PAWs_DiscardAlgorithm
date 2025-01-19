#ifndef PRIZE_H
#define PRIZE_H

#include <string>

class Prize {
private:
    double begin;
    double end;
    std::string type;

public:
    // ���캯��
    Prize(double begin, double end, const std::string& type);

    /**
     * ��������ҿ�����
     * */
    bool isThat(double num) const;

    // ��ȡ type
    std::string getType() const;
};

#endif // PRIZE_H
