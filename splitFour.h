#ifndef SplitFour_h
#define SplitFour_h
#include "animalCard.h"
class SplitFour : public AnimalCard {
	Orientation orientation;
    EvenOdd row;
    Animal animals[2][2];
protected:
    virtual void print(ostream& o) const;
public:
    SplitFour(Animal[2][2]);
    virtual Animal getAnimal(int) const;
    virtual EvenOdd getRow() const;
    virtual void printRow(EvenOdd) const;
    virtual void setOrientation(Orientation);
    virtual void setRow(EvenOdd);
};

#endif
