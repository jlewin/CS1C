#include <iostream>
#include "Card.h"
#include <sstream>

using namespace std;

int Card::instanceCount = 0;

const string Card::ranks[Card::RANK_COUNT] = {"Ace", "2", "3", "4", "5", "6", "7",
                            "8", "9", "10", "Jack", "Queen", "King"};

const Suit Card::suits[Card::SUIT_COUNT] = { 
    {"Hearts", "♥" },
    {"Clubs", "♣"},
    {"Diamonds", "♦"},
    {"Spades", "♠"}
};

Card::Card() {
    // dbg instances
    //cout << "cardType constructor (" << instanceCount++ << ")" << endl;
    cardValue = 0;
}

void Card::initCard(int suitIndex, int rankIndex) {
    this->suit = Card::suits[suitIndex];
    this->rank = Card::ranks[rankIndex];

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
string Card::getRank() const {
    return rank;
}

bool Card::equals(const Card& otherCard) {
    return rank == otherCard.rank
        && cardValue == otherCard.cardValue;
}


string Card::getSuit() const {
    return suit.name;
}   

int Card::getValue() const {
    return cardValue;
}

string Card::toString(bool concise) const {
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