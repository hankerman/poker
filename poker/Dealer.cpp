#include "Dealer.h"

void Dealer::shou(Card card)
{
	if (card.nominal_value == 11) {
		cout << card.suit << "J" << " ";
	}
	else if (card.nominal_value == 12) {
		cout << card.suit << "Q" << " ";
	}
	else if (card.nominal_value == 13) {
		cout << card.suit << "K" << " ";
	}
	else if (card.nominal_value == 14) {
		cout << card.suit << "A" << " ";
	}
	else {
		cout << card.suit << card.nominal_value << " ";
	}
	cout << " ";	
}

Dealer::Dealer()
{
	deck.mix();
	countPlayer = 4;
	play = 0;
	players = new Player[countPlayer];
	countCard = 51;
	bank = 0;
}

Dealer::~Dealer()
{
	delete[] players;
}

void Dealer::print(int i)
{
	if (i == 1) {
		for (int j = 0; j < 3; j++) {
			shou(table[j]);
		}
	}
	else if (i == 2) {
		for (int j = 0; j < 4; j++) {
			shou(table[j]);
		}
	}
	else if (i == 3) {
		for (int j = 0; j < 5; j++) {
			shou(table[j]);
		}
	}
}

void Dealer::distribution()
{
	/*for (auto& player : players) {
		player.distribution(deck.getCard(countCard--), deck.getCard(countCard--));
	}*/

	for (int i = 0; i < countPlayer; i++) {
		players[i].distribution(deck.getCard(countCard--), deck.getCard(countCard--));
	}
	
	for (int i = 0; i < 5; i++) {
		table.push_back(deck.getCard(countCard--));
	}

}

int Dealer::mapComparison()
{

	int num = 0, num2 = 2, res = 0;

	if (players[0].getRes() < players[1].getRes()) {
		num = 1;
	}
	else if (players[0].getRes() == players[1].getRes()) {
		if (players[0].getCard() < players[0].getCard()) {
			num = 1;
		}
		else {
			num = 0;
		}
	}
	else {
		num = 0;
	}
	if (players[2].getRes() < players[3].getRes()) {
		num = 1;
	}
	else if (players[2].getRes() == players[3].getRes()) {
		if (players[2].getCard() < players[3].getCard()) {
			num2 = 3;
		}
		else {
			num2 = 2;
		}
	}
	else {
		num2 = 2;
	}

	if (players[num].getRes() < players[num2].getRes()) {
		res = num2;
	}
	else if (players[num].getRes() == players[num2].getRes()) {
		if (players[num].getCard() < players[num2].getCard()) {
			res = num2;
		}
		else {
			res = num;
		}
	}
	else {
		res = num;
	}

	return res;
}



void Dealer::acceptingBets(int i)
{
	bank += i;
}

void Dealer::addPlayer(Player& p)
{
	//players.push_back(p);
	players[play++] = p;
}

//void Dealer::addPlayer(vector<Player> play)
//{
//	for (int i = 0; i < play.size(); i++) {
//		players.push_back(play[i]);
//	}
//}

Player Dealer::getPlayer(int i)
{
	return players[i];
}
