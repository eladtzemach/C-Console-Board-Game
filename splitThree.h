#ifndef splitThree_h
#define splitThree_h
#include "animalCard.h"
class SplitThree : public AnimalCard {
    Animal animals[2][2];
    EvenOdd row;
    Orientation orientation;
protected:
    virtual void print(ostream& o) const;
public:
    SplitThree(Animal[2][2]);
    virtual void setOrientation(Orientation);
    virtual void setRow(EvenOdd);
    virtual void printRow(EvenOdd) const;
    virtual Animal getAnimal(int) const;
    virtual EvenOdd getRow() const;
};
#endif
