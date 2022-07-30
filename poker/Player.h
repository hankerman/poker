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
	bool isPair(vector<Card> cardvec); //����
	bool isTwoPairs(vector<Card> cardvec); //��� ����
	bool isThree(vector<Card> cardvec); //��� ��� ������
	bool isStraight(vector<Card> cardvec); //�����
	bool isFlush(vector<Card> cardvec); //����
	bool isHouse(vector<Card> cardvec); //�������
	bool isFour(vector<Card> cardvec); //����
	bool isStFlush(vector<Card> cardvec); //���������
	bool isRoFlush(vector<Card> cardvec); //��������
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
	int getRes(); // ���������
	int getCard(); // ������� �����
	void setName(string name);
	string getName();
};

