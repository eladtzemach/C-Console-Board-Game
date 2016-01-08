#include "wolfAction.h"
#include <iostream>
using namespace std;
WolfAction::WolfAction() : ActionCard(Animal::WOLF) {}
QueryResult WolfAction::query() {
    cout << "Please enter the location (X and Y coordinates) of the card you wish to add to your hand: ";
    int x, y;
    cin >> x >> y;
    return QueryResult(x, y);}
void WolfAction::perform(Table &table, Player *playerList, QueryResult queryResult) {
    int currentPlayer = gameInfo.currentPlayer;
    int x, y;
    queryResult.getCoordinates(x, y);
    shared_ptr<AnimalCard> chosenCard;
    while (true) {
        try {
            chosenCard = table.pickAt(y, x);
        } catch (...) {
            cout << "Invalid location, try again." << endl;
            queryResult = query();
            queryResult.getCoordinates(x, y);
            continue;}
        break;}
    playerList[currentPlayer].yourHand += chosenCard;}
