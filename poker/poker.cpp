#include <iostream>
#include "Deck_of_cards.h"
#include "Player.h"
using namespace std;

int main()
{
    srand(time(NULL));
    Deck_of_cards deck;
    deck.print();
    cout << endl << endl;
    deck.mix();
    deck.print();
    cout << endl;
    Player player;
    player.distribution(deck.getCard(51), deck.getCard(50));
    player.print();
    cout << endl;
    Player player2;
    player2.distribution(deck.getCard(49), deck.getCard(48));
    player2.print();
}
