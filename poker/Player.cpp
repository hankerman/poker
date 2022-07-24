#include "Player.h"



void Player::bubleSort(Card* cards, int size)
{
	
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (cards[j].nominal_value > cards[j + 1].nominal_value) {
				Card tmp = cards[j];
				cards[j] = cards[j + 1];
				cards[j + 1] = tmp;
			}
		}
	}
}

void Player::bubleSort2(Card* cards, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (cards[j].suit > cards[j + 1].suit) {
				Card tmp = cards[j];
				cards[j] = cards[j + 1];
				cards[j + 1] = tmp;
			}
		}
	}
}

bool Player::isPair(vector<Card> cardvec)
{
	int size = cardvec.size();
	bool flag = false;
	Card* cards = new Card[size];
	for (int i = 0; i < size; i++) {
		cards[i] = cardvec[i];
	}

	bubleSort(cards, size);
	//print(cards);

	for (int i = size - 2; i != -1; i--) {
		if (cards[i].nominal_value == cards[i + 1].nominal_value) {
			flag = true;
		}
	}

	delete[] cards;

	return flag;
}

bool Player::isTwoPairs(vector<Card> cardvec)
{
	int size = cardvec.size();
	bool flag = false;
	Card* cards = new Card[size];
	for (int i = 0; i < size; i++) {
		cards[i] = cardvec[i];
	}

	bubleSort(cards, size);
	

	for (int i = size - 2; i != -1; i--) {
		if (cards[i].nominal_value == cards[i + 1].nominal_value) {
			for (int j = i - 1; j != -1; j--) {
				if (cards[j].nominal_value == cards[j + 1].nominal_value) {
					flag = true;
				}
			}
		}
	}
	delete[] cards;
	return flag;
}

bool Player::isThree(vector<Card> cardvec)
{
	int size = cardvec.size();
	bool flag = false;
	Card* cards = new Card[size];
	for (int i = 0; i < size; i++) {
		cards[i] = cardvec[i];
	}

	bubleSort(cards, size);
	
	for (int i = size - 2; i != 0; i--) {
		if (cards[i].nominal_value == cards[i + 1].nominal_value && cards[i].nominal_value == cards[i - 1].nominal_value) {
			flag = true;
		}
	}
	delete[] cards;
	return flag;
}

bool Player::isStraight(vector<Card> cardvec)
{
	int size = cardvec.size();
	bool flag = false;
	Card* cards = new Card[size];
	for (int i = 0; i < size; i++) {
		cards[i] = cardvec[i];
	}

	bubleSort(cards, size);
	//print(cards);

	for (int i = 1; i < 3; i++) {
		if (cards[i].nominal_value + 1 == cards[i + 1].nominal_value && cards[i].nominal_value == cards[i - 1].nominal_value + 1) {
			int count = 0;
			for (int j = i - 1; j < size; j++) {
				if (cards[j].nominal_value + 1 == cards[j + 1].nominal_value) {
					count++;
				}
			}
			if (count == 5) {
				flag = true;
			}
		}
	}
	delete[] cards;
	return flag;
}

bool Player::isFlush(vector<Card> cardvec)
{
	int size = cardvec.size();
	bool flag = false;
	Card* cards = new Card[size];
	for (int i = 0; i < size; i++) {
		cards[i] = cardvec[i];
	}

	bubleSort2(cards, size);
	//print(cards);

	for (int i = 1; i < 3; i++) {
		if (cards[i].suit == cards[i + 1].suit && cards[i].suit == cards[i - 1].suit) {
			int count = 0;
			for (int j = i - 1; j < size; j++) {
				if (cards[j].suit == cards[j + 1].suit) {
					count++;
				}
			}
			if (count == 5) {
				flag = true;
			}
		}
	}
	delete[] cards;
	return flag;
}

bool Player::isHouse(vector<Card> cardvec)
{
	int size = cardvec.size();
	int count = 0;
	int posPair = -1;
	int posThree = -1;
	if (isPair(cardvec)) {		
		for (int i = 0; i < size - 1; i++) {
			if (cardvec[i].nominal_value == cardvec[i + 1].nominal_value) {
				count++;

			}
		}
	}
	return false;
}

bool Player::isFour(vector<Card> cardvec)
{
	int size = cardvec.size();
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		if (cardvec[i].nominal_value == cardvec[i + 1].nominal_value) {
			count++;
		}
	}
	if (count == 3) {
		return true;
	}
	return false;
}

bool Player::isStFlush(vector<Card> cardvec)
{
	int size = cardvec.size();
	int count = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (cardvec[j].nominal_value + 1 == cardvec[j+1].nominal_value && cardvec[j].suit == cardvec[j + 1].suit) {
				count++;
			}
		}
		if (count == 4) {
			return true;
		}
	}
	return false;
}

bool Player::isRoFlush(vector<Card> cardvec)
{
	int size = cardvec.size();
	if (isStFlush(cardvec)) {
		if (cardvec[size - 1].nominal_value == 14) {
			if (cardvec[size - 3].nominal_value == 12) {
				if (cardvec[size - 5].nominal_value == 10) {
					return true;
				}
			}
		}
	}
	return false;
}

Player::Player()
{
	card = new Card[2];
	coint = 0;
}

Player::~Player()
{
	delete[] card;
}

void Player::distribution(Card card1, Card card2)
{
	card[0] = card1;
	card[1] = card2;
}

void Player::print()
{
	//cout << card[0].suit << " " << card[0].nominal_value << "\t" << card[1].suit << card[1].nominal_value;
	
	if (card[0].nominal_value == 11) {
		cout << card[0].suit << "J" << " ";
	}
	else if (card[0].nominal_value == 12) {
		cout << card[0].suit << "Q" << " ";
	}
	else if (card[0].nominal_value == 13) {
		cout << card[0].suit << "K" << " ";
	}
	else if (card[0].nominal_value == 14) {
		cout << card[0].suit << "A" << " ";
	}
	else {
		cout << card[0].suit << card[0].nominal_value << " ";
	}
	cout << " ";
	if (card[1].nominal_value == 11) {
		cout << card[1].suit << "J" << " ";
	}
	else if (card[1].nominal_value == 12) {
		cout << card[1].suit << "Q" << " ";
	}
	else if (card[1].nominal_value == 13) {
		cout << card[1].suit << "K" << " ";
	}
	else if (card[1].nominal_value == 14) {
		cout << card[1].suit << "A" << " ";
	}
	else {
		cout << card[1].suit << card[1].nominal_value << " ";
	}
}

Card Player::getCard(int i)
{
	Card tmp = card[i];
	return tmp;
}

int Player::addCoin(int i)
{
	return coint += i;
}

int Player::rates(int i)
{
	if (i < coint) {
		return 0;
	}

	return coint -= i;
}

void Player::compare(vector<Card> cardvec)
{
	if (card[0].nominal_value > card[1].nominal_value) {
		res.glavCard = card[0];
	}
	else {
		res.glavCard = card[1];
	}
	cardvec.push_back(card[0]);
	cardvec.push_back(card[1]);
	//bubleSort(cardvec);
	int size = cardvec.size()-1;
	int start = 0;
	
}

