#include <iostream>
#include "Deck.h"

using namespace std;

int main()
{
    // Construct a deck
    Deck initialDeck;

    const int MAX_SHUFFLES = 20;

    // Print out the initial deck
    cout << "\nInitial Deck" << endl;
    initialDeck.printDeck();

    // Shuffle the required number of time to arrive at the original deck, printing
    // out the first and last shuffles
    for (int i = 1; i <= MAX_SHUFFLES; i++) {
        Deck shuffledDeck;

        // Perfect shuffle the deck, i number of times
        for (int j = 0; j < i; j++) {
            shuffledDeck.shuffle();
        }

        bool matchesInitial = initialDeck.equals(shuffledDeck);

        // Print out the first and the matching shuffled decks
        if (i == 1 || matchesInitial) {
            cout << "\nPerfect Shuffle #" << i << endl;
            shuffledDeck.printDeck();
        }

        if (matchesInitial) {
            cout << "\n✱ " << i << " perfect shuffles are needed to arrive back at the initial deck." << endl;
            break;
        }
    }
    
    cout << endl;
    return 0;
}
