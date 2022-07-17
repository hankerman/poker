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
    int countCard = 51;
    Player player;
    player.distribution(deck.getCard(countCard--), deck.getCard(countCard--));
    player.print();
    cout << endl;
    Player player2;
    player2.distribution(deck.getCard(countCard--), deck.getCard(countCard--));
    player2.print();
}
