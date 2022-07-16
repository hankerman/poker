#pragma once
#include <iostream>
using namespace std;

struct Card
{
	char suit;
	int nominal_value;
};

class Deck_of_cards
{
private:
	enum suits{ Hearts = 3 , Diamonds = 4 , Clubs = 5 , Spades = 6};
	const int size = 52;
	Card* deck;
public:
	Deck_of_cards();
	~Deck_of_cards();
	void print();
	void mix();
	Card getCard(int i);
};

