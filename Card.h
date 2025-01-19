#ifndef CARD_H
#define CARD_H

#include<iostream>

using namespace std;

enum Color;
enum Type;

class Card
{
private:
	Color color;
	Type type;
public:
	Card(Color color, Type type);
	string parseName();
	Color getColor();
	Type getType();
};

#endif