#include <iostream>
#include "deckType.h"
#include "cardType.h"

using namespace std;

deckType::deckType() {
    //cout << "deckType constructor" << endl;
    int cardIndex = 0;

    // Iterate over suits, creating a card for each rank in the suit
    for (int suitIndex = 0; suitIndex < cardType::SUIT_COUNT; suitIndex++) {
        // Create a card for each rank in the suit
        for (int rankIndex = 0; rankIndex < cardType::RANK_COUNT; rankIndex++) {
            // Init the card
            cards[cardIndex++].initCard(suitIndex, rankIndex);
        }
    }
}

void deckType::shuffle() {
    int midPoint = TOTAL_CARDS / 2;
    int upperIndex = midPoint;

    cardType shuffled[TOTAL_CARDS];

    int i = 0;

    for (int lowerIndex = 0; lowerIndex < midPoint; lowerIndex += 1) {
        upperIndex = midPoint + lowerIndex;

        shuffled[i++] = cards[lowerIndex];
        shuffled[i++] = cards[upperIndex];
    }

    // Copy from shuffled to active cards
    for (int i = 0; i < TOTAL_CARDS; i++) {
        cards[i] = shuffled[i];
    }
}

void deckType::printDeck() {
    bool border = true;
    bool concise = true;
    string separator = concise ? (border ? "│" : "┊") : "\n";

    if (concise && border) {
        cout << "┌";
        for (int i = 0; i < TOTAL_CARDS; i++) {
            cout << "──" << (i < TOTAL_CARDS - 1 ? "┬" : "┐");
        }
        cout << endl;
        cout << separator;
    }

    for (int i = 0; i < TOTAL_CARDS; i++) {
        cout << cards[i].toString(concise) << separator;
    }

    if (concise && border) {
        cout << endl;
        cout << "└";
        for (int i = 0; i < TOTAL_CARDS; i++) {
            cout << "──" << (i < TOTAL_CARDS - 1 ? "┴" : "┘");

        }
    }


    cout << endl;
}
