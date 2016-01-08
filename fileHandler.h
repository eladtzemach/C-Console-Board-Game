#ifndef fileHandler_h
#define fileHandler_h
#include <string>
#include "table.h"
#include "player.h"
#include "deck.h"
using namespace std;
void writeToFile(string filename,
                 Table *table,
                 Deck<AnimalCard> *deck,
                 Player *playerList,
                 int numberOfPlayers);
#endif
