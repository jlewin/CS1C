#ifndef Card_H
#define Card_H

#include <iostream>

using namespace std;

struct Suit
{
    string name;
    string symbol;
};

class Card
{
    public:
        Card();
        void initCard(int suitIndex, int rankIndex);
        string getRank() const; 
        string getSuit() const;
        int getValue() const;
        string toString(bool concise = false) const;

        static const int RANK_COUNT = 13;
        static const int SUIT_COUNT = 4;

        static const string ranks[RANK_COUNT];
        static const Suit suits[SUIT_COUNT];
        static int instanceCount;

    private:
        string rank;
        Suit suit;
        int cardValue;

};

#endif
