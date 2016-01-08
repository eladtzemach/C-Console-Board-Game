

#include "animalCard.h"


char charForAnimal(Animal animal) {
    switch (animal) {
    case Animal::DEER:
        return 'd';
        break;
    case Animal::BEAR:
        return 'b';
        break;
    case Animal::HARE:
        return 'h';
        break;
    case Animal::WOLF:
        return 'w';
        break;
    case Animal::ALL:
        return '*';
        break;
    case Animal::MOOSE:
        return 'm';
        break;
    default:
        return 'x';
        break;
    }
}
