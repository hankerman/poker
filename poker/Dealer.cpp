#include "Dealer.h"

Dealer::Dealer()
{
	deck.mix();
	countCard = 51;
	bank = 0;
}

void Dealer::distribution()
{
	for (auto& player : players) {
		player.distribution(deck.getCard(countCard--), deck.getCard(countCard--));
	}
	
}

void Dealer::acceptingBets(int i)
{
	bank += i;
}

void Dealer::distributionDealer()
{
	table.push_back(deck.getCard(countCard--));
}

void Dealer::addPlayer(Player p)
{
	players.push_back(p);
}
