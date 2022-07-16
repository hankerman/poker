#include "Player.h"

Player::Player()
{
	card = new Card[2];
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
