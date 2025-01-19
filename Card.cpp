#include "Card.h"
#include "Type.h"
#include "Color.h"

#include <map>

Card::Card(Color color, Type type) 
	: color(color), type(type) {}

Color Card::getColor() {
	return this->color;
}

Type Card::getType() {
	return this->type;
}

std::string Card::parseName() {
    // ӳ�� Type ���ַ���
    static const std::map<Type, std::string> typeNames = {
    {ZERO, "��"}, {ONE, "һ"}, {TWO, "��"}, {THREE, "��"},
    {FOUR, "��"}, {FIVE, "��"}, {SIX, "��"}, {SEVEN, "��"},
    {EIGHT, "��"}, {NINE, "��"}, {UNKNOWN, "δ֪"},
    {STUN_GUN, "���ǹ"}, {ICE_GUN, "��ǹ"}, {RANDOM, "�����"},
    {BUMERANG, "������"}, {SHOVEL, "����"}, {CROSSBOW, "��"},
    {POSITION, "ҩˮ"}, {TNT, "ը��"}, {BANANA, "�㽶Ƥ"}
    };


    // ӳ�� Color ���ַ���
    static const std::map<Color, std::string> colorNames = {
        {BLUE, "��ɫ"}, {PURPLE, "��ɫ"}, {YELLOW, "��ɫ"},
        {GREEN, "��ɫ"}, {WILD, "����"}
    };

    // ��ȡ����
    std::string typeName = typeNames.at(type);   // ��ȡ type ��Ӧ���ַ���
    std::string colorName = colorNames.at(color); // ��ȡ color ��Ӧ���ַ���

    // �����������
    return colorName + "��" + typeName;
}