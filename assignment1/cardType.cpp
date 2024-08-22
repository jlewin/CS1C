#include <iostream>
#include "cardType.h"

using namespace std;

cardType::cardType() {
    cout << "cardType constructor" << endl;
    rank = "";
    suit = "";
    cardValue = 0;
}

void cardType::initCard(string rank, string suit, int value) {
    this->rank = rank;
    this->suit = suit;
    this->cardValue = value;
}

// Read only getters {{
string cardType::getRank() const {
    return rank;
}

string cardType::getSuit() const {
    return suit;
}   

int cardType::getValue() const {
    return cardValue;
}

string cardType::toString() const {
    return rank + " of " + suit + " (" + to_string(cardValue) + ")";
}   
// }} 