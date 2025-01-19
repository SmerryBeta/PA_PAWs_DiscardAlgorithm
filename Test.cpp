#include "DrawMachine.h"
#include <map>
#include <iostream>

using namespace std;

#include "Color.h"
#include "Card.h"
#include "Type.h"

#include<iostream>

map<int, vector<Card>> DEEP_SOLUTION;

Card matchDesktopCard(Card card, Card desktop) {
    // ը�������޷��ı䵱ǰ���е�������
    switch(card.getType()){
        case Type::TNT:
        case Type::CROSSBOW:
        case Type::BANANA:
            return desktop;
    }
    return card;
}

void path(vector<Card> cards, Card desktop, vector<Card> solution, int num) {
    Color d_color = desktop.getColor();
    Type d_type = desktop.getType();

    num++;
    int i = 0;
    for (auto& card : cards) {
        if (card.getColor() == d_color 
            || card.getType() == d_type 
            || ((card.getColor() == Color::WILD && card.getType() != Type::TNT) 
                || // ������غϲ��ܳ�����ը��
                (card.getType() == Type::TNT && cards.size() < 3))) {

            vector<Card> new_cards = cards;
            new_cards.erase(new_cards.begin() + i);

            vector<Card> new_solution = solution;
            new_solution.push_back(card);

            Card new_desktop = matchDesktopCard(card, desktop);

            path(new_cards, new_desktop, new_solution, num);
            DEEP_SOLUTION[num] = new_solution;
        }
        i++;
    }
}


int main() {
    Card desktop(Color::PURPLE, Type::ZERO);

    // ���岢��ʼ����������
    vector<Card> cards = {
        Card(Color::PURPLE, Type::TWO),
        Card(Color::BLUE, Type::TWO),
        Card(Color::YELLOW, Type::TWO),
        Card(Color::YELLOW, Type::TWO),
        Card(Color::YELLOW, Type::ICE_GUN),
        Card(Color::PURPLE, Type::BUMERANG),
        Card(Color::GREEN, Type::ZERO),
        Card(Color::GREEN, Type::TWO),
        Card(Color::GREEN, Type::SHOVEL),
        Card(Color::WILD, Type::RANDOM),
        Card(Color::WILD, Type::POSITION),
        Card(Color::GREEN, Type::CROSSBOW),
        Card(Color::WILD, Type::TNT)
    };

    vector<Card> solution;

    path(cards, desktop, solution, 0);

    auto maxKey = DEEP_SOLUTION.rbegin()->first;
    vector<Card> final_solution = DEEP_SOLUTION[maxKey];

    std::cout << "����������ɳ�" << maxKey << "�Σ�����ʱ���濨�� -> " << desktop.parseName() << endl;
    int i = 1;
    for (auto c : final_solution)
       std::cout << i++ << ":" << c.parseName() << endl;

    std::cout << (maxKey == cards.size() ? "\n���ѳ���" : "\n���޷�����") << endl;
    return 0;
}