#include <iostream>
#include "Deck_of_cards.h"
#include "Player.h"
using namespace std;

void bubleSort2(Card* cards)
{
    int size = 7;
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
    
    bubleSort2(cards);
    //print(cards);

    for (int i = 1; i < 3 ; i++) {
        if (cards[i].suit == cards[i + 1].suit && cards[i].suit == cards[i-1].suit) {
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
    Card card2{ 4 , 2 };
    cards.push_back(card2);
    Card card3{ 3 , 9 };
    cards.push_back(card3);
    Card card4{ 4 , 3 };
    cards.push_back(card4);
    Card card5{ 3 , 6 };
    cards.push_back(card5);
    Card card6{ 3 , 4 };
    cards.push_back(card6);
    Card card7{ 3 , 5 };
    cards.push_back(card7);

    print(cards);
    
    if (isPair(cards)) {
        cout << "yes";
    }
    else {
        cout << "no";
    }

}
