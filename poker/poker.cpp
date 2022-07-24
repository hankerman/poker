#include <iostream>
#include "Deck_of_cards.h"
#include "Player.h"
using namespace std;

void bubleSort(Card* cards)
{
    int size = 7;
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

void print(Card* cardvec) {

    for (int i = 0; i < 7; i++) {
        cout << "|" << cardvec[i].suit << " " << cardvec[i].nominal_value << "|" << " ";
    }
    cout << endl;

}

bool isPair(vector<Card> cardvec)
{
    int size = cardvec.size();    
    bool flag = false;
    Card* cards = new Card[size];    
    for (int i = 0; i < size; i++) {
        cards[i] = cardvec[i];
    }
    
    bubleSort(cards);
    print(cards);

    for (int i = size-2; i != 0 ; i--) {
        if (cards[i].nominal_value == cards[i + 1].nominal_value && cards[i].nominal_value == cards[i-1].nominal_value) {
            flag = true;
        }
    }
    delete[] cards;
    return flag;
}



void print(vector<Card> cardvec) {

    for (int i = 0; i < cardvec.size(); i++) {
        cout << "|" << cardvec[i].suit << " " << cardvec[i].nominal_value << "|" << " ";
    }
    cout << endl;

}

int main()
{
    srand(time(NULL));
    /*Deck_of_cards deck;
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
    player2.print();*/

    vector<Card> cards;
    Card card{ 3 , 10 };
    cards.push_back(card);
    Card card2{ 4 , 10 };
    cards.push_back(card2);
    Card card3{ 3 , 9 };
    cards.push_back(card3);
    Card card4{ 4 , 12 };
    cards.push_back(card4);
    Card card5{ 3 , 2 };
    cards.push_back(card5);
    Card card6{ 3 , 4 };
    cards.push_back(card6);
    Card card7{ 5 , 10 };
    cards.push_back(card7);

    print(cards);
    
    if (isPair(cards)) {
        cout << "yes";
    }
    else {
        cout << "no";
    }

}
