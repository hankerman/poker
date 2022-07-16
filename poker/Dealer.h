#pragma once
#include "Deck_of_cards.h"

class Dealer
{
private:
	int count_players;
	int players;
	Deck_of_cards deck;
	Card* table;
	bool chekPlayer;
public:
	Dealer();
	~Dealer();
	void print(int i);

};

