#ifndef Deck_H
#define Deck_H

#include "Card.h"
#include <iostream>

using namespace std;

class Deck
{
    public:
        Deck();
        void shuffle();
        void printDeck();
        static const int TOTAL_CARDS = 52;
        bool equals(const Deck& otherDeck);

    private:
        Card cards[TOTAL_CARDS];

};

#endif
