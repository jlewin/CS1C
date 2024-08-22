#ifndef H_DeckType
#define H_DeckType

#include "cardType.h"
#include <iostream>

using namespace std;

class deckType
{
    public:
        deckType();
        void shuffle();
        void printDeck();

    private:
        static const int TOTAL_CARDS = 52;
        cardType cards[TOTAL_CARDS];

};

#endif
