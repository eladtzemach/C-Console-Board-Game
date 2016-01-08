#include "bearAction.h"
#include <iostream>
using namespace std;


BearAction::BearAction() : ActionCard(Animal::BEAR) {}

QueryResult BearAction::query() {
    cout << "Please enter the player number you wish to switch hands with: ";
    int x;
    cin >> x;
    return QueryResult(x);
}
void BearAction::perform(Table &table, Player *playerList, QueryResult queryResult) {
    int currentPlayer = gameInfo.currentPlayer;
    int x;
    queryResult.getPlayer(x);
    x--;
    Hand firstHand = playerList[currentPlayer].yourHand;
    playerList[currentPlayer].yourHand = playerList[x].yourHand;
    playerList[x].yourHand = firstHand;}
