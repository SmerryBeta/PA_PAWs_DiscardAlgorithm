#ifndef DRAWMACHINE_H
#define DRAWMACHINE_H

#include <map>
#include <string>
#include <vector>
#include <random>
#include <iostream>

class Prize; // ǰ������ Prize ��

class DrawMachine {
private:
    static std::map<std::string, double> TYPE_RATES; // ��Ʒ���ͼ�����
    static std::vector<Prize> prizes;               // ��Ʒ��Χ

    std::map<std::string, int> PRIZE_NUM;           // ��ȡ���Ľ�Ʒͳ��
    std::mt19937 generator;                         // �����������
    std::uniform_real_distribution<> distribution;  // ������ֲ�

    std::string insertPrize(const std::string& type); // ���뽱Ʒ��ͳ�Ʊ�

public:
    DrawMachine();  // ���캯��
    std::string draw(); // ��ȡ������Ʒ
    std::vector<std::string> draw(int count); // ��ȡָ�������Ľ�Ʒ
    int drawToComplete(); // �鵽���н�Ʒ��Ҫ�Ĵ���
    bool hasAll(); // �����Ƿ��ռ���������
    bool print(); // ��ӡ��ǰ��Ʒͳ�Ʊ�
};

#endif // DRAWMACHINE_H
