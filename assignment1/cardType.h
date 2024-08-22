#ifndef H_CardType
#define H_CardType

#include <iostream>

using namespace std;

struct suitType
{
    string name;
    string symbol;
};

class cardType
{
    public:
        cardType();
        void initCard(int suitIndex, int rankIndex);
        string getRank() const; 
        string getSuit() const;
        int getValue() const;
        string toString(bool concise = false) const;

        static const int RANK_COUNT = 13;
        static const int SUIT_COUNT = 4;

        static const string ranks[RANK_COUNT];
        static const suitType suits[SUIT_COUNT];
        static int instanceCount;

    private:
        string rank;
        suitType suit;
        int cardValue;

};

#endif
