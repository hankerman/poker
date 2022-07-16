#include "Deck_of_cards.h"

Deck_of_cards::Deck_of_cards()
{
	deck = new Card[size];

	for (int i = 0, t = 0; i < 4; i++) {
		for (int j = 2; j < 15; j++, t++) {
			if (i == 0) {
				deck[t].suit = Hearts;
			}
			else if (i == 1) {
				deck[t].suit = Diamonds;
			}
			else if (i == 2) {
				deck[t].suit = Clubs;
			}
			else if (i == 3) {
				deck[t].suit = Spades;
			}
			deck[t].nominal_value = j;
		}
	}
}

Deck_of_cards::~Deck_of_cards()
{
	delete[] deck;
}

void Deck_of_cards::print()
{
	for (int i = 0, j = 0; i < size; i++, j++) {
		if (j == 13) {
			cout << endl;
			j = 0;
		}
		if (deck[i].nominal_value == 11) {
			cout << deck[i].suit << "J" << " ";
		}
		else if (deck[i].nominal_value == 12) {
			cout << deck[i].suit << "Q" << " ";
		}
		else if (deck[i].nominal_value == 13) {
			cout << deck[i].suit << "K" << " ";
		}
		else if (deck[i].nominal_value == 14) {
			cout << deck[i].suit << "A" << " ";
		}
		else {
			cout << deck[i].suit << deck[i].nominal_value << " ";
		}
	}
}

void Deck_of_cards::mix()
{
	Card tmp;
	int count_mix = rand();
	for (int i = 0; i < count_mix; i++) {
		int count_position = rand() % 51;
		for (int i = 0; i < size; i++) {
			tmp.nominal_value = deck[i].nominal_value;
			tmp.suit = deck[i].suit;
			deck[i].nominal_value = deck[count_position].nominal_value;
			deck[i].suit = deck[count_position].suit;
			deck[count_position].nominal_value = tmp.nominal_value;
			deck[count_position].suit = tmp.suit;
		}
	}
}

Card Deck_of_cards::getCard(int i)
{
	Card tmp = deck[i];
	return tmp;
}
