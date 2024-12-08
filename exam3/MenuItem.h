#ifndef MenuItem_H
#define MenuItem_H

#include <iostream>
#include "Screen.h"

using namespace std;

class MenuItem
{
    public:
        MenuItem(string name, double cost, double salePrice);

        // Virtual functions
        virtual ~MenuItem();
        virtual void print(ostream& os) const;

        string getName() const;
        double getCost() const;
        double getSalePrice() const;
        double getItemProfit() const;

        void setName(string);
        void setCost(double);
        void setSalePrice(double);

        friend ostream& operator<<(ostream&, const MenuItem&);

        static void setIndentText(string);
        static int getInstanceCount();
        string indent() const;
        static int titleWidth;
        
    private:
        static string indentText;
        static int instanceCount;
        string name;
        double cost;
        double salePrice;
};

#endif
