#include <iostream>
#include "Deck.h"

using namespace std;

int main()
{
    // Construct a deck
    Deck initialDeck;
    Deck shuffledDeck;

    // Print out the initial deck
    cout << "\nInitial Deck" << endl;
    initialDeck.printDeck();

    int shuffleCount = 0;

    // Shuffle until the shuffled deck is back to the original order
    do {

        shuffledDeck.shuffle();

        // Print out the first and the matching shuffled decks
        if (shuffleCount++ == 0) {
            cout << "\nPerfect Shuffle #" << shuffleCount << endl;
            shuffledDeck.printDeck();
        }
    } while(!initialDeck.equals(shuffledDeck));

    cout << "\nPerfect Shuffle #" << shuffleCount << endl;
    shuffledDeck.printDeck();

    cout << "\n✱ " << shuffleCount << " perfect shuffles are needed to arrive back at the initial deck." << endl << endl;
    return 0;
}
