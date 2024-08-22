#include <iostream>
#include "deck.h"
#include "cardType.h"

using namespace std;


int main()
{
    // Construct a deck
    cardDeckType deck = cardDeckType();
    deck.printDeck();

    // Shuffle the deck
    deck.shuffle();
    deck.printDeck();

    return 0;
}


cardDeckType::cardDeckType() {

    cout << "cardDeckType constructor" << endl;
    const int RANK_COUNT = 13;
    const int SUIT_COUNT = 4;

    string ranks[RANK_COUNT] = {"Ace", "2", "3", "4", "5", "6", "7",
                            "8", "9", "10", "Jack", "Queen", "King"};

    string suits[SUIT_COUNT] = {"Clubs", "Diamonds", "Spades", "Hearts"};

    // Iterate over suits, creating a card for each rank in the suit
    for (int i = 0; i < SUIT_COUNT; i++) {
        string suit = suits[i];
        // Create a card for each rank in the suit
        for (int j = 0; j < RANK_COUNT; j++) {
            string rank = ranks[j];
            int card_value;
            if (rank == "Ace") {
                card_value = 11;
            } else if (j >= 9) {
                card_value = 10;
            } else {
                card_value = j + 1; //stoi(rank);
            }

            // Reference, init, and print the updated card
            cardType &card = cards[i * RANK_COUNT + j];
            card.initCard(rank, suit, card_value);
            //cout << card.toString() << endl;
        }
        //cout << "----------------" << endl;
    }
}

void cardDeckType::shuffle() {
    int midPoint = TOTAL_CARDS / 2;

    cout << "----------------------- midpoint ? --------------------------------" << endl;

    // Print the first card at the midpoint
    cout << cards[midPoint].toString() << endl;
    cout << "----------------------- ??? --------------------------------" << endl;

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

cardType* cardDeckType::getCards() {
    return cards;
}

void cardDeckType::printDeck() {
    for (int i = 0; i < TOTAL_CARDS; i++) {
        cout << cards[i].toString() << endl;
    }
}
