#ifndef LineItem_H
#define LineItem_H

#include "MenuItem.h"

class LineItem
{
    public:
        LineItem(const MenuItem& menuItem, int quantity);
        
    private:
        MenuItem menuItem;
        int quantity;
};

#endif
