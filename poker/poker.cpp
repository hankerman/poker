#include <iostream>
#include "Dealer.h"
using namespace std;

int main()
{
    srand(time(NULL));
    cout << "Enter you name:";
    string name = "Tony";
    Player Tony(name);
    name = "Jery";
    Player Jery(name);
    name = "Mary";
    Player Mary(name);
    cin >> name;
    Player player(name);
    Dealer dealer;
    dealer.addPlayer(player);
    dealer.addPlayer(Tony);
    dealer.addPlayer(Jery);
    dealer.addPlayer(Mary);
    /*vector<Player> play;
    play.push_back(player);
    play.push_back(Tony);
    play.push_back(Jery);
    play.push_back(Mary);
    dealer.addPlayer(play);*/

    bool end = true;
    int round = 1;
    dealer.distribution();
    while (end) {

        system("cls");
        cout << "Table: ";
        dealer.print(round);
        cout << dealer.getPlayer(1).getName() << " ";
        dealer.getPlayer(1).print();
        cout << dealer.getPlayer(2).getName() << " ";
        dealer.getPlayer(2).print();
        cout << dealer.getPlayer(3).getName() << " ";
        dealer.getPlayer(3).print();
        cout << dealer.getPlayer(0).getName() << " ";
        dealer.getPlayer(0).print();
        end = false;
    }

}
