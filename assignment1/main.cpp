#include <iostream>
#include "deckType.h"

using namespace std;

int main()
{
    // Construct a deck
    deckType deck = deckType();
    
    // Print out the intial deck
    deck.printDeck();

    // Shuffle the deck
    deck.shuffle();

    // Print out the shuffled deck
    deck.printDeck();

    return 0;
}
