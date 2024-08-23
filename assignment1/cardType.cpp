#include <iostream>
#include "cardType.h"
#include <sstream>

using namespace std;

int cardType::instanceCount = 0;

const string cardType::ranks[cardType::RANK_COUNT] = {"Ace", "2", "3", "4", "5", "6", "7",
                            "8", "9", "10", "Jack", "Queen", "King"};

const suitType cardType::suits[cardType::SUIT_COUNT] = { 
    {"Hearts", "♥" },
    {"Clubs", "♣"},
    {"Diamonds", "♦"},
    {"Spades", "♠"}
};

cardType::cardType() {
    // dbg instances
    //cout << "cardType constructor (" << instanceCount++ << ")" << endl;
    cardValue = 0;
}

void cardType::initCard(int suitIndex, int rankIndex) {
    this->suit = cardType::suits[suitIndex];
    this->rank = cardType::ranks[rankIndex];

    int cardValue;
    if (this->rank == "Ace") {
        cardValue = 11;
    } else if (rankIndex >= 9) {
        cardValue = 10;
    } else {
        cardValue = rankIndex + 1; //stoi(rank);
    }

    this->cardValue = cardValue;
}

// Read only getters {{
string cardType::getRank() const {
    return rank;
}

string cardType::getSuit() const {
    return suit.name;
}   

int cardType::getValue() const {
    return cardValue;
}

string cardType::toString(bool concise) const {
    if (concise) {
        int color = 0;
        if (suit.name == "Hearts" || suit.name == "Diamonds") {
            color = 31;
        }

        ostringstream ss;
        ss << "\033[1;" << color << "m" << rank.substr(0, 1) + suit.symbol << "\033[0m";
        return ss.str();
    } else {
        return rank + " of " + suit.name + " (" + to_string(cardValue) + ")";
    }
}   
// }} 