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
    // 映射 Type 到字符串
    static const std::map<Type, std::string> typeNames = {
    {ZERO, "零"}, {ONE, "一"}, {TWO, "二"}, {THREE, "三"},
    {FOUR, "四"}, {FIVE, "五"}, {SIX, "六"}, {SEVEN, "七"},
    {EIGHT, "八"}, {NINE, "九"}, {UNKNOWN, "未知"},
    {STUN_GUN, "电击枪"}, {ICE_GUN, "冰枪"}, {RANDOM, "随机蛋"},
    {BUMERANG, "回旋镖"}, {SHOVEL, "铲子"}, {CROSSBOW, "弩"},
    {POSITION, "药水"}, {TNT, "炸弹"}, {BANANA, "香蕉皮"}
    };


    // 映射 Color 到字符串
    static const std::map<Color, std::string> colorNames = {
        {BLUE, "蓝色"}, {PURPLE, "紫色"}, {YELLOW, "黄色"},
        {GREEN, "绿色"}, {WILD, "泛型"}
    };

    // 获取名称
    std::string typeName = typeNames.at(type);   // 获取 type 对应的字符串
    std::string colorName = colorNames.at(color); // 获取 color 对应的字符串

    // 返回组合名称
    return colorName + "的" + typeName;
}