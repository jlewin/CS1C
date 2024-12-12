#ifndef CustomerOrder_H
#define CustomerOrder_H

#include <iostream>
#include <vector>
#include "LineItem.h"

class CustomerOrder
{
    public:
        CustomerOrder(string);
        ~CustomerOrder();
        friend ostream& operator<<(ostream&, const CustomerOrder*);
        void addItem(const MenuItem*, int);
        double getTotalCost() const;
        double getTotalRevenue() const;
        double getTotalProfit() const;

        const vector<LineItem*>& getLineItems() const {
            return lineItems;
        }

    private:
        vector<LineItem*> lineItems;
        string customerName;
};
#endif
