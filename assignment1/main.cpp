#include <iostream>
#include "deckType.h"

using namespace std;

int main()
{
    // Construct a deck
    deckType deck = deckType();

    // Print out the initial deck
    cout << "\nInitial Deck" << endl;
    deck.printDeck();

    // Shuffle the required number of time to arrive at the original deck, printing
    // out the first and last shuffles
    for (int i = 0; i < 8; i++) {
        deck.shuffle();

        if (i == 0 || i == 7) {
            // Print out the shuffled deck
            cout << "Sort #" << i + 1 << endl;
            deck.printDeck();
        }
    }

    cout << "\n✱ Eight perfect shuffles are needed to arrive back at the initial deck." << endl;
    cout << endl;
    return 0;
}
