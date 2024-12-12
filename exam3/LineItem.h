#ifndef LineItem_H
#define LineItem_H

#include "MenuItem.h"

class LineItem
{
    public:
        LineItem(const MenuItem& menuItem, int quantity);
        ~LineItem();
        friend ostream& operator<<(ostream&, const LineItem*);
        static int getInstanceCount();
        string getName() const;

        double getCost() const;
        double getPrice() const;
        double getProfit() const;

    private:
        static int instanceCount;
        void print(ostream&) const;

    private:
        const MenuItem& menuItem;
        int quantity;
};

#endif
