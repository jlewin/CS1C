#ifndef CustomerOrder_H
#define CustomerOrder_H

#include <iostream>
#include <vector>
#include "LineItem.h"

class CustomerOrder
{
    public:
        CustomerOrder(string);
        friend ostream& operator<<(ostream&, const CustomerOrder*);
        void addItem(const MenuItem*, int);

    private:
        vector<LineItem*> lineItems;
        string customerName;
};
#endif
