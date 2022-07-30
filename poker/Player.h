#pragma once
#include "Deck_of_cards.h"
#include <vector>
#include <string>
using namespace std;

struct Res {
	int prior;
	Card glavCard;
};

enum combin{High_hand = 0, One_pair, Two_pairs, Three_of_a_kind, Straight, Flush, Full_house, Four_of_a_kind, Straight_flush, Royal_flush};

class Player
{
private:
	string Name;
	Card* card;
	int coint;
	Res res;
	void bubleSort(Card* cards, int size);
	void bubleSort2(Card* cards, int size);
	bool isPair(vector<Card> cardvec); //пара
	bool isTwoPairs(vector<Card> cardvec); //две пары
	bool isThree(vector<Card> cardvec); //сет или тройка
	bool isStraight(vector<Card> cardvec); //стрит
	bool isFlush(vector<Card> cardvec); //флеш
	bool isHouse(vector<Card> cardvec); //фулхаус
	bool isFour(vector<Card> cardvec); //каре
	bool isStFlush(vector<Card> cardvec); //стритфлеш
	bool isRoFlush(vector<Card> cardvec); //роялфлеш
public:
	Player();
	Player(string name);
	~Player();
	void distribution(Card card1, Card card2);
	void print();
	Card getCard(int i);
	int addCoin(int i);
	int rates(int i);
	void compare(vector<Card> cardvec);
	int getRes(); // приоретет
	int getCard(); // номинал карты
	void setName(string name);
	string getName();
};

