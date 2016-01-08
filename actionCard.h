
#ifndef actionCard_h
#define actionCard_h
#include "table.h"
#include "startCard.h"
#include "player.h"
#include "queryResult.h"


struct GameInfo {
    int currentPlayer;
    int numberOfPlayers; };


class ActionCard : public StartCard {
protected:
    GameInfo gameInfo;
public:
    ActionCard(Animal);
    void printRow(EvenOdd);
    void setGameInfo(GameInfo);
    virtual QueryResult query() = 0;
    virtual void perform(Table &, Player *, QueryResult) = 0;
};

#endif
