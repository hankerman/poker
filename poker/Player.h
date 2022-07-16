#pragma once
#include "Deck_of_cards.h"
class Player
{
private:
	Card* card;
public:
	Player();
	~Player();
	void distribution(Card card1, Card card2);
	void print();
	Card getCard(int i);
};

