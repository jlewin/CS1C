#ifndef H_CardType
#define H_CardType

#include <iostream>

using namespace std;

class cardType
{
    public:
        cardType();
        void initCard(string rank, string suit, int value);
        string getRank() const; 
        string getSuit() const;
        int getValue() const;
        string toString() const;

    private:
        string rank;
        string suit;
        int cardValue;
};
#endif
