#include <vector>
#include "player.h"
#include "deck.h"
#include "animalCard.h"
#include "actionCard.h"
#include "AnimalCardFactory.h"
#include "fileHandler.h"
#include "startStack.h"
#include "table.h"
#include <iostream>
using namespace std;
int main(int argc, const char *argv[]) {
    cout << "Please enter the number of players: (2-5) ";
    int i = 0;
    while (i == 0) {
        cin >> i;
    } cout << endl;


    string name;
    Player *playerList = new Player[i];
    AnimalCardFactory *factory = AnimalCardFactory::getFactory();

    for (int j = 0; j != i; j++) {
        cout << "Name of player " << j + 1 << ": ";
        cin >> name;
        playerList[j].setName(name);
        cout << endl; }


    bool playerHasWon = false;
    Table gameBoard = Table();
    int nbdraws[5]{0, 0, 0, 0, 0};


    while (!playerHasWon) {
        bool shouldPause = false;
        cout << "Pause, save and exit the game? Yes(1)/No(0) " << endl;
        cin >> shouldPause;

        if (shouldPause) {
            cout << "Saving..." << endl;
            writeToFile("savedGame.txt", &gameBoard, &factory->getDeck(), playerList, i);
            cout << "Game was saved successfully to savedGame.txt!" << endl;
            return 0; }

        for (int k = 0; k != i; k++) {
            cout << "Table: " << endl;
            gameBoard.print();
            for (int n = 0; n != nbdraws[k]; n++)
               playerList[k].yourHand += factory->getDeck().draw();
               cout << "Player: " << playerList[k].getName() << endl;
               cout << playerList[k] << endl;
            int c, x, y;

            shared_ptr<AnimalCard> chosenCard = nullptr;

            while (true) { try {
                    c = -1;

               cout << "Please enter the number of card you wish to play:";
                 while (c < 0 || c > playerList[k].yourHand.noCards() - 1)
                        cin >> c;

               int orientation = -1;
            cout << "Rotate the card 180 degrees? Yes(1)/No(0)";
             while (orientation != 0 && orientation != 1)
                 cin >> orientation;

              cout << endl;
               cout << "Where do you wish to place it? \n type in X coordinate, then press "
                            "ENTER, type in Y coordinate and press ENTER again." << endl;
                    cin >> x >> y;
             cout << endl;
              chosenCard = playerList[k].yourHand[c];


                    if (x == 52 && y == 52) {
                        if (shared_ptr<ActionCard> actionCard = dynamic_pointer_cast<ActionCard>(chosenCard)) {
                            cout << "Would you like to put the card at the top (1) or bottom (0)?";
                            bool choiceIsTop;
                            cin >> choiceIsTop;

                            if (choiceIsTop) {
                                gameBoard += actionCard; }
                            else {
                                gameBoard -= actionCard;
                                actionCard->setGameInfo({k, i});
                                QueryResult queryResult = actionCard->query();
                                actionCard->perform(gameBoard,
                                                    playerList,
                                                    queryResult);
                            }} else {

                            cout << "Only action cards may be placed on the "
                                    "stack!" << endl;
                            throw IllegalPlacement(x, y);
                        }
                    } else {
                        chosenCard->setOrientation((Orientation)orientation);

                        nbdraws[k] = gameBoard.addAt(chosenCard, y, x);
                    }
                } catch (...) {
                    cout << "Can't do that! Try again." << endl;
                    continue; }
                break; }
            playerList[k].yourHand -= chosenCard;
            for (int m = 0; m != i; m++) {
               string name = playerList[m].getName();

                if (gameBoard.win(name))
                    playerHasWon = true;}}}

    return 0;
}
