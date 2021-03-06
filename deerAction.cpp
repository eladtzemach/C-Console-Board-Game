#include "deerAction.h"
#include <iostream>
using namespace std;

DeerAction::DeerAction() : ActionCard(Animal::DEER) {}

QueryResult DeerAction::query() {
    cout << "Please choose the player number you wish to switch goals with.\n";
    int x;
    cin >> x;
    return QueryResult(x);
}
void DeerAction::perform(Table &table,
                  Player *playerList,
                      QueryResult queryResult) {
    int currentPlayer = gameInfo.currentPlayer;
    int x;
    queryResult.getPlayer(x);
    x--; // Correct the index
    string currentAnimal = playerList[currentPlayer].getSecretAnimal();
    string otherAnimal = playerList[x].swapSecretAnimal(currentAnimal);
    playerList[currentPlayer].swapSecretAnimal(otherAnimal);
}
