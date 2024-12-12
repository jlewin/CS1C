#ifndef MenuItem_H
#define MenuItem_H

#include <iostream>
#include "Screen.h"

using namespace std;

class MenuItem
{
    public:
        MenuItem();
        MenuItem(string name, double cost, double salePrice);
        ~MenuItem();
        void print(ostream& os) const;

        string getName() const;
        double getCost() const;
        double getSalePrice() const;
        double getItemProfit() const;

        void setName(string);
        void setCost(double);
        void setSalePrice(double);

        friend ostream& operator<<(ostream&, const MenuItem&);
        static int getInstanceCount();

    private:
        static int instanceCount;
        string name;
        double cost;
        double salePrice;
};

#endif
