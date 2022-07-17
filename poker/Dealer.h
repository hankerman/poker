#pragma once
#include "Deck_of_cards.h"
#include "Player.h"
#include <vector>
using namespace std;

class Dealer
{
private:
	
	Deck_of_cards deck;
	vector<Card> table;
	vector<Player> players;
	int bank;
	int countCard;
	
public:
	Dealer();	
	void print(int i);
	void distribution(); //раздача
	Card mapComparison(); //сравнение карт
	void acceptingBets(int i); //прием ставок
	void distributionDealer(); //получение карт дилером
	void addPlayer(Player p);

};

