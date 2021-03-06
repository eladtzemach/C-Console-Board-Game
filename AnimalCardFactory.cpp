#include "AnimalCardFactory.h"
#include "splitFour.h"
#include "splitThree.h"
#include "splitTwo.h"
#include "deerAction.h"
#include "bearAction.h"
#include "hareAction.h"
#include "wolfAction.h"
#include "mooseAction.h"
#include <algorithm>
#include <random>

void addCard(Deck<AnimalCard> &deck, AnimalCard *newCard) {
    deck.push_back((shared_ptr<AnimalCard>)((AnimalCard *)newCard));
}

AnimalCardFactory::AnimalCardFactory() {
    addCard(deck, new BearAction());
    addCard(deck, new DeerAction());
    addCard(deck, new HareAction());
    addCard(deck, new MooseAction());
    addCard(deck, new WolfAction());
    for (int i = 1; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            Animal twoSplit[2][2]{{(Animal)i, (Animal)i},
                              {(Animal)j, (Animal)j}};
            addCard(deck, new SplitTwo(twoSplit));
            Animal twoSplitBis[2][2]{{(Animal)i, (Animal)j},
                               {(Animal)i, (Animal)j}};
            addCard(deck, new SplitTwo(twoSplitBis));
            for (int k = j + 1; k < 6; k++) {
                Animal threeSplit[2][2]{(Animal)i,
                                     (Animal)j,
                                   (Animal)i,
                                        (Animal)k};
                addCard(deck, new SplitThree(threeSplit));
                Animal threeSplitBis[2][2]{(Animal)i,
                                   (Animal)i,
                                    (Animal)k,
                 (Animal)j};
                addCard(deck, new SplitThree(threeSplitBis));
                for (int m = k + 1; m < 6; m++) {
                    Animal fourSplit[2][2]{(Animal)i,
                                       (Animal)j,
                                     (Animal)k,
                                     (Animal)m};
                    addCard(deck, new SplitThree(fourSplit));
                    Animal fourSplitBis[2][2]{(Animal)m,
                   (Animal)i,
                                         (Animal)j,
                               (Animal)k};
                    addCard(deck, new SplitThree(fourSplitBis));
                    Animal fourSplitBisBis[2][2]{(Animal)k,
                               (Animal)m,
                                      (Animal)i,
                                      (Animal)j};
                    addCard(deck, new SplitThree(fourSplitBisBis));
                }
            }
        }
    }

    auto engine = default_random_engine{};
    shuffle(begin(deck), end(deck), engine); }

AnimalCardFactory *AnimalCardFactory::getFactory() {
    static AnimalCardFactory deckFactory;
    return &deckFactory;
}

Deck<AnimalCard> &AnimalCardFactory::getDeck() {
    return deck;
}
