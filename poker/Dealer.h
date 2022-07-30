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
	//vector<Player> players;
	Player* players;
	int countPlayer;
	int bank;
	int countCard;
	int play;
	void shou(Card card);

public:
	Dealer();
	~Dealer();
	void print(int i);
	void distribution(); //раздача
	int mapComparison(); //сравнение карт
	void acceptingBets(int i); //прием ставок
	void addPlayer(Player& p);//добавление игроков
	//void addPlayer(vector<Player> play);//добавление игроков
	Player getPlayer(int i);

};

