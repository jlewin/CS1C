#include <iostream>
#include "deckType.h"
#include "cardType.h"

using namespace std;

deckType::deckType() {
    cout << "deckType constructor" << endl;
    
    const int rankCount = cardType::RANK_COUNT;

    int cardIndex = 0;

    // Iterate over suits, creating a card for each rank in the suit
    for (int suitIndex = 0; suitIndex < cardType::SUIT_COUNT; suitIndex++) {
        // Create a card for each rank in the suit
        for (int rankIndex = 0; rankIndex < rankCount; rankIndex++) {
            // Init the card
            cards[cardIndex++].initCard(suitIndex, rankIndex);
        }
    }
}

void deckType::shuffle() {
    int midPoint = TOTAL_CARDS / 2;
    int upperIndex = midPoint;

    for (int lowerIndex = 1; lowerIndex <= midPoint; lowerIndex += 2) {
        upperIndex = midPoint + lowerIndex - 1;

        // Copy values into temp
        cardType temp = cards[lowerIndex];
        
        // Swap the values of the lowerIndex and upperIndex
        cards[lowerIndex] = cards[upperIndex];
        cards[upperIndex] = temp;
    }
}

void deckType::printDeck() {

    bool concise = true;
    string separator = concise ? ", " : "\n";

    for (int i = 0; i < TOTAL_CARDS; i++) {
        cout << cards[i].toString(concise) << (i < TOTAL_CARDS -1 ? separator : "");
    }

    cout << endl;
}
