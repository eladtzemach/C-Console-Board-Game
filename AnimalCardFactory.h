#ifndef animalCardFactory_hpp
#define animalCardFactory_hpp
#include "animalCard.h"
#include "deck.h"

class AnimalCardFactory {
    Deck<AnimalCard> deck;
    static AnimalCardFactory* deckFactory;
    AnimalCardFactory();
public:
    static AnimalCardFactory* getFactory();
    Deck<AnimalCard>& getDeck();
};

#endif
