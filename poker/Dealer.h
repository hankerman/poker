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
	void distribution(); //�������
	Card mapComparison(); //��������� ����
	void acceptingBets(int i); //����� ������
	void distributionDealer(); //��������� ���� �������
	void addPlayer(Player p);

};

